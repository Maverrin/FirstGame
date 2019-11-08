// Copyright 2018 Phyronnaz

#include "VoxelGraph/VoxelCppConstructor.h"
#include "VoxelGraph/VoxelNode.h"
#include "VoxelGraph/VoxelGraphWorldGenerator.h"

FString FVoxelVariable::SanitizeName(const FString& InName)
{
	FString SanitizedName;
	FString ValidChars = TEXT("_0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
	FString ValidStartChars = TEXT("_ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

	for (int32 CharIdx = 0; CharIdx < InName.Len(); ++CharIdx)
	{
		FString Char = InName.Mid(CharIdx, 1);

		if (!ValidChars.Contains(*Char))
		{
			SanitizedName += TEXT("_");
		}
		else
		{
			SanitizedName += Char;
		}
	}

	if (SanitizedName.IsEmpty() || SanitizedName == TEXT("_"))
	{
		return TEXT("Name");
	}

	if (ValidStartChars.Contains(*SanitizedName.Mid(0, 1)))
	{
		return SanitizedName;
	}
	else
	{
		return TEXT("_") + SanitizedName;
	}
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

FVoxelCppConstructor::FVoxelCppConstructor(const FString& ClassName, UVoxelGraphGenerator* Graph)
	: ClassName(ClassName)
	, Graph(Graph)
	, Tree(MakeShared<FVoxelComputeNodeTreesHolder>())
{
	check(Graph);

	int32 MaxId = 0;
	FString Error;
	if (!Graph->CreateComputeTrees(*Tree, MaxId, LocalVariables, Error, false))
	{
		AddError(Error);
	}
}

bool FVoxelCppConstructor::Compile(FString& OutErrorMessage)
{	
	if (!Errors.IsEmpty())
	{
		OutErrorMessage = Errors;
		return false;
	}
		
	AddInclude("CoreMinimal.h");
	AddInclude("VoxelUtilities.h");
	AddInclude("VoxelMaterial.h");
	AddInclude("VoxelWorldGenerator.h");
	AddInclude("VoxelWorldGeneratorPicker.h");
	AddInclude("VoxelNodeDefinitions.h");

	// Setup nodes
	{
		Tree->ForAll([&](auto& T) { T.SetupConstructor(*this); });
		ExposedVariables.Sort([](const FVoxelExposedVariable& A, const FVoxelExposedVariable& B) { return A.GetPriority() < B.GetPriority(); });
	}

	AddInclude(ClassName + ".generated.h");

	const FString InstanceClassName("F" + ClassName + "Instance");
	const FString MainClassName("U" + ClassName);
	int Indentation = 0;

	// Intro
	{
		AddLine("// Copyright 2018 Phyronnaz");
		NewLine();
		AddLine("#pragma once");
		NewLine();
		AddLine("#pragma warning( disable : 4101 4701 )");
		AddLine("using Seed = int;");
	}

	NewLine();

	// Includes
	for (auto& Include : Includes)
	{
		AddLine("#include \"" + Include + "\"");
	}

	NewLine();
	NewLine();

	// Instance
	{
		AddLine("class " + InstanceClassName + " : public FVoxelWorldGeneratorInstance");
		AddLine("{");
		AddLine("public:");
		Indent();
		{
			// Constructor
			{
				{
					FString Line;
					Line += InstanceClassName;
					Line += "(";
					bool bFirst = true;
					for (auto& Variable : ExposedVariables)
					{
						if (bFirst)
						{
							bFirst = false;
						}
						else
						{
							Line += ", ";
						}
						Line += Variable.GetType() + " " + "In" + Variable.GetName();
					}
					Line += ")";
					AddLine(Line);
				}
				Indent();
				{
					bool bFirst = true;
					for (auto& Variable : ExposedVariables)
					{
						AddLine((bFirst ? ": " : ", ") + Variable.GetName() + "(" + "In" + Variable.GetName() + ")");
						bFirst = false;
					}
				}
				Unindent();
				AddLine("{");
				AddLine("}");
			}

			// Init
			AddLine("virtual void Init(const FVoxelWorldGeneratorInit& " + GetInitStructString() + ") override");
			AddLine("{");
			Indent();
			{
				AddLine("{");
				Indent();
				{
					bIsInit = true;
					for (auto& Variable : LocalVariables)
					{
						if (Variable.Value.Type == EVoxelPinCategory::Seed)
						{
							AddLine(Variable.Value.GetInitDeclaration());
						}
					}
					NewLine();
					Tree->ConstantsTree.InitCpp(*this);
					Tree->XTree.InitCpp(*this);
					Tree->XYTree.InitCpp(*this);
					Tree->XYZTree.InitCpp(*this);
					bIsInit = false;
				}
				Unindent();
				AddLine("}");
				AddLine("{");
				Indent();
				{
					CurrentDependencies = EVoxelAxisDependencies::Constant;
					Tree->ConstantsTree.ComputeCpp(*this);
				}
				Unindent();
				AddLine("}");
			}
			Unindent();
			AddLine("}");

			// GetValuesAndMaterials
			AddLine("virtual void GetValuesAndMaterials(FVoxelValue Values[], FVoxelMaterial Materials[], const FIntBox& Bounds, const FIntVector& Offset, int LOD, const FIntVector& ArraySize, int QueryLOD, const FVoxelPlaceableItemHolder& ItemHolder) const override");
			AddLine("{");
			Indent();
			{
				AddLine("FVoxelContext " + GetContextString() + "(ItemHolder, QueryLOD);");
				AddLine("const int Step = 1 << LOD;");
				NewLine();
				AddLine("check(Bounds.IsMultipleOf(Step));");

				AddLine("for (int X = Bounds.Min.X; X < Bounds.Max.X; X += Step)");
				AddLine("{");
				Indent();
				{
					AddLine(GetContextString() + ".X = X;");
					NewLine();
					DeclareValueAndMaterialAndLocalVariables(EVoxelAxisDependencies::X);
					NewLine();

					Tree->XTree.ComputeCpp(*this);

					AddLine("for (int Y = Bounds.Min.Y; Y < Bounds.Max.Y; Y += Step)");
					AddLine("{");
					Indent();
					{
						AddLine(GetContextString() + ".Y = Y;");
						NewLine();						
						DeclareValueAndMaterialAndLocalVariables(EVoxelAxisDependencies::XY);
						NewLine();

						Tree->XYTree.ComputeCpp(*this);

						AddLine("for (int Z = Bounds.Min.Z; Z < Bounds.Max.Z; Z += Step)");
						AddLine("{");
						Indent();
						{
							AddLine(GetContextString() + ".Z = Z;");
							NewLine();							
							DeclareValueAndMaterialAndLocalVariables(EVoxelAxisDependencies::XYZ);
							NewLine();

							Tree->XYZTree.ComputeCpp(*this);

							AddLine("SetValueAndMaterial(Values, Materials, Offset, LOD, ArraySize, ItemHolder, X, Y, Z, " + GetValueString() + ", " + GetMaterialString() + ");");
						}
						Unindent();
						AddLine("}");
					}
					Unindent();
					AddLine("}");
				}
				Unindent();
				AddLine("}");
			}
			Unindent();
			AddLine("}");
			
			// GetUpVector
			AddLine("virtual FVector GetUpVector(int X, int Y, int Z) const override");
			AddLine("{");
			Indent();
			{
				switch (Graph->WorldKind)
				{
				case EVoxelGraphGeneratorWorldKind::Sphere:
					AddLine("return FVector(X, Y, Z).GetSafeNormal();");
					break;
				case EVoxelGraphGeneratorWorldKind::Flat:
				default:
					AddLine("return FVector::UpVector;");
					break;
				}
			}
			Unindent();
			AddLine("}");

			if (ExposedVariables.Num() > 0)
			{
				// Exposed variables
				Unindent();
				AddLine("private:");
				Indent();
				{
					for (auto& Variable : ExposedVariables)
					{
						AddLine(Variable.GetDeclaration());
					}
				}
				NewLine();
			}

			if (PrivateVariables.Num() > 0)
			{
				// Private variables
				Unindent();
				AddLine("private:");
				Indent();
				{
					for (auto& Variable : PrivateVariables)
					{
						AddLine(Variable.GetDeclaration());
					}
				}
			}
			// Cached variables
			Unindent();
			AddLine("private:");
			Indent();
			DeclareValueAndMaterialAndLocalVariables(EVoxelAxisDependencies::Constant);
		}
		Unindent();
		AddLine("};");
	}

	NewLine();

	// UClass
	{
		AddLine("UCLASS(Blueprintable)");
		AddLine("class " + MainClassName + " : public UVoxelWorldGenerator");
		AddLine("{");
		Indent();
		{
			AddLine("GENERATED_BODY()");
			NewLine();
			Unindent();
			AddLine("public:");
			Indent();

			for (auto& Variable : ExposedVariables)
			{
				AddLine(FString::Printf(TEXT("UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=\"%s\")"), *Variable.GetCategory()));
				AddLine(Variable.GetExposedType() + " " + Variable.GetName() + (!Variable.GetDefaultValue().IsEmpty() ? " = " + Variable.GetDefaultValue() + ";" : ";"));
			}
			
			NewLine();
			AddLine(MainClassName + "() {}");

			// GetWorldGenerator()
			AddLine("TSharedRef<FVoxelWorldGeneratorInstance, ESPMode::ThreadSafe> GetWorldGenerator() override");
			AddLine("{");
			Indent();
			{
				FString Line;
				Line += "return MakeShared<";
				Line += InstanceClassName;
				Line += ", ESPMode::ThreadSafe>";
				Line += "(";
				bool bFirst = true;
				for (auto& Variable : ExposedVariables)
				{
					if (bFirst)
					{
						bFirst = false;
					}
					else
					{
						Line += ", ";
					}
					Line += Variable.GetAccessor(Variable.GetName());
				}
				Line += ");";
				AddLine(Line);
			}
			Unindent();
			AddLine("}");
		}
		Unindent();
		AddLine("};");
	}

	// Handle errors
	{
#if WITH_EDITOR
		if (NodesToSelect.Num() > 0)
		{
			Graph->GetVoxelGraphEditor()->SelectNodesAndZoomToFit(Graph->VoxelGraph, NodesToSelect);
		}
#endif
		if (!Errors.IsEmpty())
		{
			OutErrorMessage = Errors;
			return false;
		}
	}

	return true;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void FVoxelCppConstructor::AddExposedVariable(const FVoxelExposedVariable& ExposedVariable)
{
	FVoxelExposedVariable* Existing = ExposedVariables.FindByPredicate([&](const FVoxelExposedVariable& InVariable) { return InVariable.GetName() == ExposedVariable.GetName(); });
	if (Existing)
	{
		Errors.Append("Error: " + ExposedVariable.GetNode()->GetName() + " UniqueName is " + ExposedVariable.GetName() + " but an other node has that UniqueName (" + Existing->GetNode()->GetName() + ")\n");
#if WITH_EDITOR
		NodesToSelect.Add(ExposedVariable.GetNode()->GraphNode);
		NodesToSelect.Add(Existing->GetNode()->GraphNode);
#endif
	}
	else
	{
		ExposedVariables.Add(ExposedVariable);
	}
}
