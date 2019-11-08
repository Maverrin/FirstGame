// Copyright 2018 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "VoxelGraph/VoxelNode.h"
#include "VoxelUtilities.h"
#include "VoxelGraph/VoxelNodeHelpers.h"
#include "VoxelGraph/VoxelGraphWorldGenerator.h"
#include "VoxelPlaceableItems/VoxelDefaultItems.h"
#include "VoxelWorldGeneratorPicker.h"
#include "VoxelGraph/VoxelNodeDefinitions.h"
#include "VoxelGraph/VoxelCppConstructor.h"
#include "VoxelGraph/VoxelBaseNodes.h"
#include "VoxelGraph/VoxelGraphCompiler.h"
#include "VoxelGraph/VoxelCompilationNode.h"
#include "VoxelDefaultNodes.generated.h"

#define LOCTEXT_NAMESPACE "VoxelNodes"

// Return the current X coordinate, casted to a float. Always a whole number
UCLASS(meta = (DisplayName = "X (float)"))
class VOXEL_API UVoxelNode_XF : public UVoxelFloatNode
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()
public:
	UVoxelNode_XF() { SetOutputs(EC::Float); }
	SET_NODE_DEPENDENCIES(FVoxelCompilationNode::X)
	SET_VOXELNODE_TITLE("X")
	GENERATED_COMPUTENODE
	(
		,
		DEFINE_OUTPUTS_REVERSED(float),
		_O0 = _C0.X;
	)
};

// Return the current Y coordinate, casted to a float. Always a whole number
UCLASS(meta = (DisplayName = "Y (float)"))
class VOXEL_API UVoxelNode_YF : public UVoxelFloatNode
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()
public:
	UVoxelNode_YF() { SetOutputs(EC::Float); }
	SET_NODE_DEPENDENCIES(FVoxelCompilationNode::Y)
	SET_VOXELNODE_TITLE("Y")
	GENERATED_COMPUTENODE
	(
		,
		DEFINE_OUTPUTS_REVERSED(float),
		_O0 = _C0.Y;
	)
};

// Return the current Z coordinate, casted to a float. Always a whole number
UCLASS(meta = (DisplayName = "Z (float)"))
class VOXEL_API UVoxelNode_ZF : public UVoxelFloatNode
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()
public:
	UVoxelNode_ZF() { SetOutputs(EC::Float); }
	SET_NODE_DEPENDENCIES(FVoxelCompilationNode::Z)
	SET_VOXELNODE_TITLE("Z")
	GENERATED_COMPUTENODE
	(
		,
		DEFINE_OUTPUTS_REVERSED(float),
		_O0 = _C0.Z;
	)
};

//////////////////////////////////////////////////////////////////////////////////////

// Return the current X coordinate
UCLASS(meta = (DisplayName = "X (int)"))
class VOXEL_API UVoxelNode_XI : public UVoxelIntNode
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()
public:
	UVoxelNode_XI() { SetOutputs(EC::Int); }
	SET_NODE_DEPENDENCIES(FVoxelCompilationNode::X)
	SET_VOXELNODE_TITLE("X")
	GENERATED_COMPUTENODE
	(
		,
		DEFINE_OUTPUTS_REVERSED(int),
		_O0 = _C0.X;
	)
};

// Return the current Y coordinate
UCLASS(meta = (DisplayName = "Y (int)"))
class VOXEL_API UVoxelNode_YI : public UVoxelIntNode
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()
public:
	UVoxelNode_YI() { SetOutputs(EC::Int); }
	SET_NODE_DEPENDENCIES(FVoxelCompilationNode::Y)
	SET_VOXELNODE_TITLE("Y")
	GENERATED_COMPUTENODE
	(
		,
		DEFINE_OUTPUTS_REVERSED(int),
		_O0 = _C0.Y;
	)
};

// Return the current Z coordinate
UCLASS(meta = (DisplayName = "Z (int)"))
class VOXEL_API UVoxelNode_ZI : public UVoxelIntNode
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()
public:
	UVoxelNode_ZI() { SetOutputs(EC::Int); }
	SET_NODE_DEPENDENCIES(FVoxelCompilationNode::Z)
	SET_VOXELNODE_TITLE("Z")
	GENERATED_COMPUTENODE
	(
		,
		DEFINE_OUTPUTS_REVERSED(int),
		_O0 = _C0.Z;
	)
};

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

// Get the material color. Outputs are between 0 and 1
UCLASS(meta = (DisplayName = "Get Color"))
class VOXEL_API UVoxelNode_GetColor : public UVoxelMaterialNode
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_GetColor()
	{
		SetInputs(EC::Material);
		SetOutputs(EC::Float, "R",
				   EC::Float, "G",
				   EC::Float, "B",
				   EC::Float, "A");
	}

	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(FVoxelMaterial),
		DEFINE_OUTPUTS_REVERSED(float, float, float, float),
		FVoxelNodeFunctions::GetColor(_I0, _O0, _O1, _O2, _O3);
	)
};

// Get the Voxel Spawned Actor Id
UCLASS(meta = (DisplayName = "Get Voxel Spawned Actor Id"))
class VOXEL_API UVoxelNode_GetVoxelSpawnedActorId : public UVoxelMaterialNode
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_GetVoxelSpawnedActorId()
	{
		SetInputs(EC::Material);
		SetOutputs(EC::Int, "Voxel Spawned Actor Id");
	}
	
#if ENABLE_VOXELACTORS
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(FVoxelMaterial),
		DEFINE_OUTPUTS_REVERSED(int),
		_O0 = _I0.GetVoxelActorId();
	)
#else
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(FVoxelMaterial),
		DEFINE_OUTPUTS_REVERSED(int),
		_O0 = 0;
	)
#endif
};

// Get the Voxel Grass Id
UCLASS(meta = (DisplayName = "Get Voxel Grass Id"))
class VOXEL_API UVoxelNode_GetVoxelGrassId : public UVoxelMaterialNode
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_GetVoxelGrassId()
	{
		SetInputs(EC::Material);
		SetOutputs(EC::Int, "Voxel Grass Id");
	}
	
#if ENABLE_VOXELGRASS
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(FVoxelMaterial),
		DEFINE_OUTPUTS_REVERSED(int),
		_O0 = _I0.GetVoxelGrassId();
	)
#else
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(FVoxelMaterial),
		DEFINE_OUTPUTS_REVERSED(int),
		_O0 = 0;
	)
#endif
};

// Get the index of the material. Output is between 0 and 255
UCLASS(meta = (DisplayName = "Get Index"))
class VOXEL_API UVoxelNode_GetIndex : public UVoxelMaterialNode
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_GetIndex()
	{
		SetInputs(EC::Material);
		SetOutputs(EC::Int, "Index");
	}

	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(FVoxelMaterial),
		DEFINE_OUTPUTS_REVERSED(int),
		_O0 = _I0.GetIndex();
	)
};

UCLASS(meta = (DisplayName = "Get Double Index"))
class VOXEL_API UVoxelNode_GetDoubleIndex : public UVoxelMaterialNode
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_GetDoubleIndex()
	{
		SetInputs(EC::Material);
		SetOutputs(EC::Int, "Index A", EC::Int, "Index B", EC::Float, "Blend");
	}

	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(FVoxelMaterial),
		DEFINE_OUTPUTS_REVERSED(float, int, int),
		FVoxelNodeFunctions::GetDoubleIndex(_I0, _O0, _O1, _O2);
	)
};

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

// Max
UCLASS(meta = (DisplayName = "Max (float)"))
class VOXEL_API UVoxelNode_FMax : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_FMax()
	{
		SetInputs(2, MAX_PINS, EC::Float);
		SetOutputs(EC::Float);
	}

	GENERATED_COMPUTENODE_PREFIXOPLOOP(FMath::Max<float>, float)
};

// Min
UCLASS(meta = (DisplayName = "Min (float)"))
class VOXEL_API UVoxelNode_FMin : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_FMin()
	{
		SetInputs(2, MAX_PINS, EC::Float);
		SetOutputs(EC::Float);
	}

	GENERATED_COMPUTENODE_PREFIXOPLOOP(FMath::Min<float>, float)
};

//////////////////////////////////////////////////////////////////////////////////////

// Max
UCLASS(meta = (DisplayName = "Max (int)"))
class VOXEL_API UVoxelNode_IMax : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_IMax()
	{
		SetInputs(2, MAX_PINS, EC::Int);
		SetOutputs(EC::Int);
	}

	GENERATED_COMPUTENODE_PREFIXOPLOOP(FMath::Max<int>, int)
};

// Min
UCLASS(meta = (DisplayName = "Min (int)"))
class VOXEL_API UVoxelNode_IMin : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_IMin()
	{
		SetInputs(2, MAX_PINS, EC::Int);
		SetOutputs(EC::Int);
	}
	
	GENERATED_COMPUTENODE_PREFIXOPLOOP(FMath::Min<int>, int)
};

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

// A < B
UCLASS(meta = (DisplayName = "float < float", Keywords = "< less"))
class VOXEL_API UVoxelNode_FLess : public UVoxelNodeHelper
{
	GENERATED_BODY()
public:	UVoxelNode_FLess() GENERATED_BINARYFLOAT_VOXELNODE(<);
};

// A <= B
UCLASS(meta = (DisplayName = "float <= float", Keywords = "<= less"))
class VOXEL_API UVoxelNode_FLessEqual : public UVoxelNodeHelper
{
	GENERATED_BODY()
public:	UVoxelNode_FLessEqual() GENERATED_BINARYFLOAT_VOXELNODE(<=);
};

// A > B
UCLASS(meta = (DisplayName = "float > float", Keywords = "> greater"))
class VOXEL_API UVoxelNode_FGreater : public UVoxelNodeHelper
{
	GENERATED_BODY()
public:	UVoxelNode_FGreater() GENERATED_BINARYFLOAT_VOXELNODE(>);
};

// A >= B
UCLASS(meta = (DisplayName = "float >= float", Keywords = ">= greater"))
class VOXEL_API UVoxelNode_FGreaterEqual : public UVoxelNodeHelper
{
	GENERATED_BODY()
public:	UVoxelNode_FGreaterEqual() GENERATED_BINARYFLOAT_VOXELNODE(>=);
};

// A == B
UCLASS(meta = (DisplayName = "float == float", Keywords = "== equal"))
class VOXEL_API UVoxelNode_FEqual : public UVoxelNodeHelper
{
	GENERATED_BODY()
public:	UVoxelNode_FEqual() GENERATED_BINARYFLOAT_VOXELNODE(==);
};

// A != B
UCLASS(meta = (DisplayName = "float != float", Keywords = "!= not equal"))
class VOXEL_API UVoxelNode_FNotEqual : public UVoxelNodeHelper
{
	GENERATED_BODY()
public:	UVoxelNode_FNotEqual() GENERATED_BINARYFLOAT_VOXELNODE(!=);
};

//////////////////////////////////////////////////////////////////////////////////////

// A < B
UCLASS(meta = (DisplayName = "int < int", Keywords = "< less"))
class VOXEL_API UVoxelNode_ILess : public UVoxelNodeHelper
{
	GENERATED_BODY()
public:	UVoxelNode_ILess() GENERATED_BINARYINT_VOXELNODE(<);
};

// A <= B
UCLASS(meta = (DisplayName = "int <= int", Keywords = "<= less"))
class VOXEL_API UVoxelNode_ILessEqual : public UVoxelNodeHelper
{
	GENERATED_BODY()
public:	UVoxelNode_ILessEqual() GENERATED_BINARYINT_VOXELNODE(<=);
};

// A > B
UCLASS(meta = (DisplayName = "int > int", Keywords = "> greater"))
class VOXEL_API UVoxelNode_IGreater : public UVoxelNodeHelper
{
	GENERATED_BODY()
public:	UVoxelNode_IGreater() GENERATED_BINARYINT_VOXELNODE(>);
};

// A >= B
UCLASS(meta = (DisplayName = "int >= int", Keywords = ">= greater"))
class VOXEL_API UVoxelNode_IGreaterEqual : public UVoxelNodeHelper
{
	GENERATED_BODY()
public:	UVoxelNode_IGreaterEqual() GENERATED_BINARYINT_VOXELNODE(>=);
};

// A == B
UCLASS(meta = (DisplayName = "int == int", Keywords = "== equal"))
class VOXEL_API UVoxelNode_IEqual : public UVoxelNodeHelper
{
	GENERATED_BODY()
public:	UVoxelNode_IEqual() GENERATED_BINARYINT_VOXELNODE(==);
};

// A != B
UCLASS(meta = (DisplayName = "int != int", Keywords = "!= not equal"))
class VOXEL_API UVoxelNode_INotEqual : public UVoxelNodeHelper
{
	GENERATED_BODY()
public:	UVoxelNode_INotEqual() GENERATED_BINARYINT_VOXELNODE(!=);
};

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

// Add
UCLASS(meta = (DisplayName = "float + float", Keywords = "+ add plus"))
class VOXEL_API UVoxelNode_FAdd : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_FAdd()
	{
		SetInputs(2, MAX_PINS, EC::Float);
		SetOutputs(EC::Float);
	}
	COMPACT_VOXELNODE("+")
	GENERATED_COMPUTENODE_INFIXOPLOOP(+, float)
};

// Multiply
UCLASS(meta = (DisplayName = "float * float", Keywords = "* multiply"))
class VOXEL_API UVoxelNode_FMultiply : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_FMultiply()
	{
		SetInputs(2, MAX_PINS, EC::Float);
		SetOutputs(EC::Float);
	}
	COMPACT_VOXELNODE("*")
	GENERATED_COMPUTENODE_INFIXOPLOOP(*, float)
};

//////////////////////////////////////////////////////////////////////////////////////

// Subtract
UCLASS(meta = (DisplayName = "float - float", Keywords = "- subtract minus"))
class VOXEL_API UVoxelNode_FSubstract : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_FSubstract()
	{
		SetInputs(EC::Float, EC::Float);
		SetOutputs(EC::Float);
	}
	COMPACT_VOXELNODE("-")
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(float, float),
		DEFINE_OUTPUTS_REVERSED(float),
		_O0 = _I0 - _I1;
	)
};

// Divide
UCLASS(meta = (DisplayName = "float / float", Keywords = "/ divide division"))
class VOXEL_API UVoxelNode_FDivide : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_FDivide()
	{
		SetInputs(EC::Float, EC::Float);
		SetOutputs(EC::Float);
		SetDefaultValues("0", "1");
	}
	COMPACT_VOXELNODE("/")
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(float, float),
		DEFINE_OUTPUTS_REVERSED(float),
		_O0 = _I0 / _I1;
	)
};

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

// Add
UCLASS(meta = (DisplayName = "int + int", Keywords = "+ add plus"))
class VOXEL_API UVoxelNode_IAdd : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_IAdd()
	{
		SetInputs(2, MAX_PINS, EC::Int);
		SetOutputs(EC::Int);
	}
	COMPACT_VOXELNODE("+")
	GENERATED_COMPUTENODE_INFIXOPLOOP(+, int)
};

// Multiply
UCLASS(meta = (DisplayName = "int * int", Keywords = "* multiply"))
class VOXEL_API UVoxelNode_IMultiply : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_IMultiply()
	{
		SetInputs(2, MAX_PINS, EC::Int);
		SetOutputs(EC::Int);
	}
	COMPACT_VOXELNODE("*")
	GENERATED_COMPUTENODE_INFIXOPLOOP(*, int)
};

//////////////////////////////////////////////////////////////////////////////////////

// Subtract
UCLASS(meta = (DisplayName = "int - int", Keywords = "- subtract minus"))
class VOXEL_API UVoxelNode_ISubstract : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_ISubstract()
	{
		SetInputs(EC::Int, EC::Int);
		SetOutputs(EC::Int);
	}
	COMPACT_VOXELNODE("-")
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(int, int),
		DEFINE_OUTPUTS_REVERSED(int),
		_O0 = _I0 - _I1;
	)
};

// Divide
UCLASS(meta = (DisplayName = "int / int", Keywords = "/ divide division"))
class VOXEL_API UVoxelNode_IDivide : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_IDivide()
	{
		SetInputs(EC::Int, EC::Int);
		SetOutputs(EC::Int);
		SetDefaultValues("0", "1");
	}
	COMPACT_VOXELNODE("/")
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(int, int),
		DEFINE_OUTPUTS_REVERSED(int),
		_O0 = _I1 == 0 ? 0 : _I0 / _I1;
	)
};

// Left bit shift
UCLASS(meta = (DisplayName = "<<", Keywords = "<< left bit shift"))
class VOXEL_API UVoxelNode_ILeftBitShift : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_ILeftBitShift()
	{
		SetInputs(EC::Int, EC::Int);
		SetOutputs(EC::Int);
		SetDefaultValues("0", "1");
	}
	COMPACT_VOXELNODE("<<")
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(int, int),
		DEFINE_OUTPUTS_REVERSED(int),
		_O0 = _I0 << _I1;
	)
};

// Right bit shift
UCLASS(meta = (DisplayName = ">>", Keywords = ">> right bit shift"))
class VOXEL_API UVoxelNode_IRightBitShift : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_IRightBitShift()
	{
		SetInputs(EC::Int, EC::Int);
		SetOutputs(EC::Int);
		SetDefaultValues("0", "1");
	}
	COMPACT_VOXELNODE(">>")
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(int, int),
		DEFINE_OUTPUTS_REVERSED(int),
		_O0 = _I0 >> _I1;
	)
};

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

// Cast to float
UCLASS(meta = (DisplayName = "int to float", Keywords = "cast, convert"))
class VOXEL_API UVoxelNode_FloatOfInt : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_FloatOfInt()
	{
		SetInputs(EC::Int);
		SetOutputs(EC::Float);
	}
	COMPACT_VOXELNODE("float")
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(int),
		DEFINE_OUTPUTS_REVERSED(float),
		_O0 = (float)_I0;
	)
};

// Round to int
UCLASS(meta = (DisplayName = "Round"))
class VOXEL_API UVoxelNode_Round : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_Round()
	{
		SetInputs(EC::Float);
		SetOutputs(EC::Int);
	}
	COMPACT_VOXELNODE("Round")
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(float),
		DEFINE_OUTPUTS_REVERSED(int),
		_O0 = FMath::RoundToInt(_I0);
	)
};

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

// Lerp between A and B. Warning: Alpha not clamped! Lerp(0, 1, 2) = 2!
UCLASS(meta = (DisplayName = "Lerp"))
class VOXEL_API UVoxelNode_Lerp : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_Lerp()
	{
		SetInputs(EC::Float, "A",
				  EC::Float, "B",
				  EC::Float, "Alpha");
		SetOutputs(EC::Float);
	}
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(float, float, float),
		DEFINE_OUTPUTS_REVERSED(float),
		_O0 = FMath::Lerp<float>(_I0, _I1, _I2);
	)
};

// Clamp Value between Min and Max
UCLASS(meta = (DisplayName = "Clamp"))
class VOXEL_API UVoxelNode_Clamp : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_Clamp()
	{
		SetInputs(EC::Float, "Value",
				  EC::Float, "Min",
				  EC::Float, "Max");
		SetOutputs(EC::Float);
		SetDefaultValues("0", "0", "1");
	}
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(float, float, float),
		DEFINE_OUTPUTS_REVERSED(float),
		_O0 = FMath::Clamp<float>(_I0, _I1, _I2);
	)
};

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

// And
UCLASS(meta = (DisplayName = "AND Boolean", Keywords = "& and"))
class VOXEL_API UVoxelNode_BAnd : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_BAnd()
	{
		SetInputs(2, MAX_PINS, EC::Boolean);
		SetOutputs(EC::Boolean);
	}
	COMPACT_VOXELNODE("AND")
	GENERATED_COMPUTENODE_INFIXOPLOOP(&&, bool)
};

// Or
UCLASS(meta = (DisplayName = "OR Boolean", Keywords = "| or"))
class VOXEL_API UVoxelNode_BOr : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_BOr()
	{
		SetInputs(2, MAX_PINS, EC::Boolean);
		SetOutputs(EC::Boolean);
	}
	COMPACT_VOXELNODE("OR")
	GENERATED_COMPUTENODE_INFIXOPLOOP(||, bool)
};

// Not
UCLASS(meta = (DisplayName = "NOT Boolean", Keywords = "! not"))
class VOXEL_API UVoxelNode_BNot : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_BNot()
	{
		SetInputs(EC::Boolean);
		SetOutputs(EC::Boolean);
	}
	COMPACT_VOXELNODE("NOT")
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(bool),
		DEFINE_OUTPUTS_REVERSED(bool),
		_O0 = !_I0;
	)
};

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

// Switch: if bool is true, then A is returned, else B is
UCLASS(meta = (DisplayName = "Switch (int)"))
class VOXEL_API UVoxelNode_SwitchInt : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_SwitchInt()
	{
		SetInputs(EC::Int, "A",
				  EC::Int, "B",
				  EC::Boolean, "Pick A");
		SetOutputs(EC::Int);
	}
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(bool, int, int),
		DEFINE_OUTPUTS_REVERSED(int),
		_O0 = _I2 ? _I0 : _I1;
	)
};

// Switch: if bool is true, then A is returned, else B is
UCLASS(meta = (DisplayName = "Switch (float)"))
class VOXEL_API UVoxelNode_SwitchFloat : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_SwitchFloat()
	{
		SetInputs(EC::Float, "A",
				  EC::Float, "B",
				  EC::Boolean, "Pick A");
		SetOutputs(EC::Float);
	}
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(bool, float, float),
		DEFINE_OUTPUTS_REVERSED(float),
		_O0 = _I2 ? _I0 : _I1;
	)
};

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

// 1 - X
UCLASS(meta = (DisplayName = "1 - X"))
class VOXEL_API UVoxelNode_1MinusX : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_1MinusX()
	{
		SetInputs(EC::Float);
		SetOutputs(EC::Float);
	}
	COMPACT_VOXELNODE("1 - X")
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(float),
		DEFINE_OUTPUTS_REVERSED(float),
		_O0 = 1 - _I0;
	)
};

// Square root
UCLASS(meta = (DisplayName = "Sqrt"))
class VOXEL_API UVoxelNode_Sqrt : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_Sqrt()
	{
		SetInputs(EC::Float);
		SetOutputs(EC::Float);
	}
	COMPACT_VOXELNODE("SQRT")
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(float),
		DEFINE_OUTPUTS_REVERSED(float),
		_O0 = FVoxelNodeFunctions::Sqrt(_I0);
	)
};

// Pow
UCLASS(meta = (DisplayName = "Pow"))
class VOXEL_API UVoxelNode_Pow : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_Pow()
	{
		SetInputs(EC::Float, EC::Float);
		SetOutputs(EC::Float);
	}
	COMPACT_VOXELNODE("POW")
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(float, float),
		DEFINE_OUTPUTS_REVERSED(float),
		_O0 = FMath::Pow(_I0, _I1);
	)
};

// Modulo
UCLASS(meta = (DisplayName = "% (int)", Keywords = "% modulus"))
class VOXEL_API UVoxelNode_IMod : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_IMod()
	{
		SetInputs(EC::Int, EC::Int);
		SetOutputs(EC::Int);
	}
	COMPACT_VOXELNODE("%")
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(int, int),
		DEFINE_OUTPUTS_REVERSED(int),
		_O0 = (_I1 == 0) ? 0 : (_I0 % _I1);
	)
};

// Absolute value
UCLASS(meta = (DisplayName = "Absolute (float)"))
class VOXEL_API UVoxelNode_FAbs : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_FAbs()
	{
		SetInputs(EC::Float);
		SetOutputs(EC::Float);
	}
	COMPACT_VOXELNODE("ABS")
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(float),
		DEFINE_OUTPUTS_REVERSED(float),
		_O0 = FMath::Abs(_I0);
	)
};

// Absolute value
UCLASS(meta = (DisplayName = "Absolute (int)"))
class VOXEL_API UVoxelNode_IAbs : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_IAbs()
	{
		SetInputs(EC::Int);
		SetOutputs(EC::Int);
	}
	COMPACT_VOXELNODE("ABS")
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(int),
		DEFINE_OUTPUTS_REVERSED(int),
		_O0 = FMath::Abs(_I0);
	)
};

// Returns the smallest integer greater than or equal to the input
UCLASS(meta = (DisplayName = "Ceil"))
class VOXEL_API UVoxelNode_Ceil : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_Ceil()
	{
		SetInputs(EC::Float);
		SetOutputs(EC::Int);
	}
	COMPACT_VOXELNODE("CEIL")
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(float),
		DEFINE_OUTPUTS_REVERSED(int),
		_O0 = FMath::CeilToInt(_I0);
	)
};

// Returns the largest integer less than or equal to the input
UCLASS(meta = (DisplayName = "Floor"))
class VOXEL_API UVoxelNode_Floor : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_Floor()
	{
		SetInputs(EC::Float);
		SetOutputs(EC::Int);
	}
	COMPACT_VOXELNODE("FLOOR")
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(float),
		DEFINE_OUTPUTS_REVERSED(int),
		_O0 = FMath::FloorToInt(_I0);
	)
};

// Return the length of (X, Y, Z)
UCLASS(meta = (DisplayName = "Vector Length"))
class VOXEL_API UVoxelNode_VectorLength : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_VectorLength()
	{
		SetInputs(EC::Float, "X",
				  EC::Float, "Y",
				  EC::Float, "Z");
		SetOutputs(EC::Float);
	}
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(float, float, float),
		DEFINE_OUTPUTS_REVERSED(float),
		_O0 = FVoxelNodeFunctions::VectorLength(_I0, _I1, _I2);
	)
};

// Return the signed fractional part of the input (ie 9.45 -> 0.45)
UCLASS(meta = (DisplayName = "Fraction"))
class VOXEL_API UVoxelNode_Fraction : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_Fraction()
	{
		SetInputs(EC::Float);
		SetOutputs(EC::Float);
	}
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(float, float, float),
		DEFINE_OUTPUTS_REVERSED(float),
		_O0 = FMath::Fractional(_I0);
	)
};

// Return the sign of the input (1, 0 or -1)
UCLASS(meta = (DisplayName = "Sign (float)"))
class VOXEL_API UVoxelNode_FSign : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_FSign()
	{
		SetInputs(EC::Float);
		SetOutputs(EC::Float);
	}
	COMPACT_VOXELNODE("SIGN")
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(float),
		DEFINE_OUTPUTS_REVERSED(float),
		_O0 = FMath::Sign(_I0);
	)
};

// Return the sign of the input (1, 0 or -1)
UCLASS(meta = (DisplayName = "Sign (int)"))
class VOXEL_API UVoxelNode_ISign : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_ISign()
	{
		SetInputs(EC::Int);
		SetOutputs(EC::Int);
	}
	COMPACT_VOXELNODE("SIGN")
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(int),
		DEFINE_OUTPUTS_REVERSED(int),
		_O0 = FMath::Sign(_I0);
	)
};

// Return the inverse square root of the input
UCLASS(meta = (DisplayName = "InvSqrt"))
class VOXEL_API UVoxelNode_InvSqrt : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_InvSqrt()
	{
		SetInputs(EC::Float);
		SetOutputs(EC::Float);
	}
	COMPACT_VOXELNODE("INVSQRT")
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(float),
		DEFINE_OUTPUTS_REVERSED(float),
		_O0 = FMath::InvSqrt(_I0);
	)
};

// Return the loge of the input
UCLASS(meta = (DisplayName = "Loge"))
class VOXEL_API UVoxelNode_Loge : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_Loge()
	{
		SetInputs(EC::Float);
		SetOutputs(EC::Float);
	}
	COMPACT_VOXELNODE("LOGE")
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(float),
		DEFINE_OUTPUTS_REVERSED(float),
		_O0 = FMath::Loge(_I0);
	)
};

// Return the exponential of the input
UCLASS(meta = (DisplayName = "Exp"))
class VOXEL_API UVoxelNode_Exp : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_Exp()
	{
		SetInputs(EC::Float);
		SetOutputs(EC::Float);
	}
	COMPACT_VOXELNODE("EXP")
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(float),
		DEFINE_OUTPUTS_REVERSED(float),
		_O0 = FMath::Exp(_I0);
	)
};

// Return the sine of the input
UCLASS(meta = (DisplayName = "Sin"))
class VOXEL_API UVoxelNode_Sin : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_Sin()
	{
		SetInputs(EC::Float);
		SetOutputs(EC::Float);
	}
	COMPACT_VOXELNODE("SIN")
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(float),
		DEFINE_OUTPUTS_REVERSED(float),
		_O0 = FMath::Sin(_I0);
	)
};

// Return the asin (inverse of sine) of the input
UCLASS(meta = (DisplayName = "Asin"))
class VOXEL_API UVoxelNode_Asin : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_Asin()
	{
		SetInputs(EC::Float);
		SetOutputs(EC::Float);
	}
	COMPACT_VOXELNODE("ASIN")
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(float),
		DEFINE_OUTPUTS_REVERSED(float),
		_O0 = FMath::Asin(_I0);
	)
};

// Return the sinh (hyperbolic sine) of the input
UCLASS(meta = (DisplayName = "Sinh"))
class VOXEL_API UVoxelNode_Sinh : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_Sinh()
	{
		SetInputs(EC::Float);
		SetOutputs(EC::Float);
	}
	COMPACT_VOXELNODE("SINH")
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(float),
		DEFINE_OUTPUTS_REVERSED(float),
		_O0 = FMath::Sinh(_I0);
	)
};

// Return the cosine of the input
UCLASS(meta = (DisplayName = "Cos"))
class VOXEL_API UVoxelNode_Cos : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_Cos()
	{
		SetInputs(EC::Float);
		SetOutputs(EC::Float);
	}
	COMPACT_VOXELNODE("COS")
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(float),
		DEFINE_OUTPUTS_REVERSED(float),
		_O0 = FMath::Cos(_I0);
	)
};

// Return the acos (inverse of cosine) of the input
UCLASS(meta = (DisplayName = "Acos"))
class VOXEL_API UVoxelNode_Acos : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_Acos()
	{
		SetInputs(EC::Float);
		SetOutputs(EC::Float);
	}
	COMPACT_VOXELNODE("ACOS")
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(float),
		DEFINE_OUTPUTS_REVERSED(float),
		_O0 = FMath::Acos(_I0);
	)
};

// Return the tan of the input
UCLASS(meta = (DisplayName = "Tan"))
class VOXEL_API UVoxelNode_Tan : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_Tan()
	{
		SetInputs(EC::Float);
		SetOutputs(EC::Float);
	}
	COMPACT_VOXELNODE("TAN")
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(float),
		DEFINE_OUTPUTS_REVERSED(float),
		_O0 = FMath::Tan(_I0);
	)
};

// Return the atan of the input
UCLASS(meta = (DisplayName = "Atan"))
class VOXEL_API UVoxelNode_Atan : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_Atan()
	{
		SetInputs(EC::Float);
		SetOutputs(EC::Float);
	}
	COMPACT_VOXELNODE("ATAN")
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(float),
		DEFINE_OUTPUTS_REVERSED(float),
		_O0 = FMath::Atan(_I0);
	)
};

// Return atan2(Y, X)
UCLASS(meta = (DisplayName = "Atan2"))
class VOXEL_API UVoxelNode_Atan2 : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_Atan2()
	{
		SetInputs(EC::Float, "Y", EC::Float, "X");
		SetOutputs(EC::Float);
	}
	COMPACT_VOXELNODE("ATAN2")
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(float, float),
		DEFINE_OUTPUTS_REVERSED(float),
		_O0 = FMath::Atan2(_I0, _I1);
	)
};

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

// Rotates around Axis (assumes Axis.Size() == 1)
UCLASS(meta = (DisplayName = "Vector Rotate Angle Axis"))
class VOXEL_API UVoxelNode_VectorRotateAngleAxis : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_VectorRotateAngleAxis()
	{
		SetInputs(
			EC::Float, "X",
			EC::Float, "Y",
			EC::Float, "Z",
			EC::Float, "Axis X",
			EC::Float, "Axis Y",
			EC::Float, "Axis Z",
			EC::Float, "Angle (Degrees)"
		);
		SetOutputs(
			EC::Float, "X",
			EC::Float, "Y",
			EC::Float, "Z"
		);
	}
	GENERATED_COMPUTENODE
	(
		DEFINE_INPUTS_REVERSED(float, float, float, float, float, float, float),
		DEFINE_OUTPUTS_REVERSED(float, float, float),
		FVoxelNodeFunctions::VectorRotateAngleAxis(_I0, _I1, _I2, _I3, _I4, _I5, _I6, _O0, _O1, _O2);
	)
};

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

// Return 0 when outside a worm, and the distance to the closest wall when inside
UCLASS(meta = (DisplayName = "Perlin Worm Distance"))
class VOXEL_API UVoxelNode_PerlinWormDistance : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_PerlinWormDistance()
	{
		SetOutputs(EC::Float);
	}

	SET_NODE_DEPENDENCIES(FVoxelCompilationNode::X | FVoxelCompilationNode::Y | FVoxelCompilationNode::Z)
	
	class FLocalVoxelComputeNode : public FVoxelComputeNode
	{
	public:
		using FVoxelComputeNode::FVoxelComputeNode;
		GENERATED_COMPUTE
		(
			,
			DEFINE_OUTPUTS_REVERSED(float),
			_O0 = FVoxelNodeFunctions::GetPerlinWormsDistance(_C0.ItemHolder, FVector(_C0.X, _C0.Y, _C0.Z));
		)
		void SetupConstructor(FVoxelCppConstructor& Constructor) const override
		{
			Constructor.AddInclude("VoxelPlaceableItems/VoxelDefaultItems.h");
		}
	};
};

// Returns the current LOD
UCLASS(meta = (DisplayName = "LOD"))
class VOXEL_API UVoxelNode_LOD : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_LOD()
	{
		SetOutputs(EC::Int);
	}

	SET_NODE_DEPENDENCIES(FVoxelCompilationNode::X | FVoxelCompilationNode::Y | FVoxelCompilationNode::Z)

	GENERATED_COMPUTENODE
	(
		,
		DEFINE_OUTPUTS_REVERSED(int),
		_O0 = _C0.LOD;
	)
};

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

// Seed parameter
UCLASS(meta = (DisplayName = "Seed"))
class VOXEL_API UVoxelNode_Seed : public UVoxelSeedNode
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Voxel")
	int32 DefaultValue = 1443;

	UPROPERTY(EditAnywhere, Category = "Voxel")
	FString Name = "SeedName";
	
	UVoxelNode_Seed()
	{
		SetOutputs(EC::Seed);
	}

	FText GetTitle() const override { return FText::FromString(Name); }
	
	class FLocalVoxelComputeNode : public FVoxelComputeNode
	{
	public:
		FLocalVoxelComputeNode(const UVoxelNode_Seed* Node, const FVoxelCompilationNode* CompilationNode)
			: FVoxelComputeNode(Node, CompilationNode)
			, DefaultValue(Node->DefaultValue)
			, Name(Node->Name)
		{
		}
		void Compute(FVoxelNodeType Inputs[], FVoxelNodeType Outputs[], const FVoxelContext& Context) const override {}
		void ComputeCpp(const TArray<FString>& Inputs, const TArray<FString>& Outputs, FVoxelCppConstructor& Constructor) const override {}
		
		void Init(FVoxelNodeType Inputs[], FVoxelNodeType Outputs[], const FVoxelWorldGeneratorInit& Init) override
		{
			Outputs[0]._Seed = Init.Seeds.Contains(Name) ? Init.Seeds[Name] : DefaultValue;
		}
		void InitCpp(const TArray<FString>& Inputs, const TArray<FString>& Outputs, FVoxelCppConstructor& Constructor) const override
		{
			Constructor.AddLine(Outputs[0] + " = " + Constructor.GetInitStructString() + ".Seeds.Contains(\"" + Name + "\") ? " + Constructor.GetInitStructString() + ".Seeds[\"" + Name + "\"] : " + FString::FromInt(DefaultValue) + ";");
		}

	private:
		const int32 DefaultValue;
		const FString Name;
	};
};

// Combine seeds
UCLASS(meta = (DisplayName = "Add Seeds"))
class VOXEL_API UVoxelNode_AddSeeds : public UVoxelSeedNode
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_AddSeeds()
	{
		SetInputs(2, MAX_PINS, EC::Seed);
		SetOutputs(EC::Seed);
	}
	
	COMPACT_VOXELNODE("+")

	class FLocalVoxelComputeNode : public FVoxelComputeNode
	{
	public:
		using FVoxelComputeNode::FVoxelComputeNode;
		
		void Compute(FVoxelNodeType Inputs[], FVoxelNodeType Outputs[], const FVoxelContext& Context) const override {}
		void ComputeCpp(const TArray<FString>& Inputs, const TArray<FString>& Outputs, FVoxelCppConstructor& Constructor) const override {}
		
		void Init(FVoxelNodeType Inputs[], FVoxelNodeType Outputs[], const FVoxelWorldGeneratorInit& Init) override
		{
			int X = Inputs[0]._Seed;
			for (int i = 1; i < InputCount; i++)
			{
				X += Inputs[i]._Seed;
			}

			Outputs[0]._Seed = X;
		}
		void InitCpp(const TArray<FString>& Inputs, const TArray<FString>& Outputs, FVoxelCppConstructor& Constructor) const override
		{
			Constructor.AddLine(GetInfixOpLoopString(Inputs, Outputs, InputCount, "+"));
		}
	};
};

// A random number >= Min and <= Max
UCLASS(meta = (DisplayName = "Rand Float"))
class VOXEL_API UVoxelNode_RandomFloat : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Voxel")
	float Min = 0;
	UPROPERTY(EditAnywhere, Category = "Voxel")
	float Max = 1;

	UVoxelNode_RandomFloat()
	{
		SetInputs(EC::Seed, "Seed");
		SetOutputs(EC::Float);
	}

	FText GetTitle() const override { return FText::FromString("Rand Float " + FString::SanitizeFloat(Min) + " " + FString::SanitizeFloat(Max)); }

	class FLocalVoxelComputeNode : public FVoxelComputeNode
	{
	public:
		FLocalVoxelComputeNode(const UVoxelNode_RandomFloat* Node, const FVoxelCompilationNode* CompilationNode)
			: FVoxelComputeNode(Node, CompilationNode)
			, Min(Node->Min)
			, Max(Node->Max)
			, RandFloatVariable(FVoxelVariable("float", CompilationNode->GetName() + "_RandFloat"))
		{
		}

		void SetupConstructor(FVoxelCppConstructor& Constructor) const override
		{
			Constructor.AddPrivateVariable(RandFloatVariable);
		}
		
		void Init(FVoxelNodeType Inputs[], FVoxelNodeType Outputs[], const FVoxelWorldGeneratorInit& Init) override
		{
			RandFloat = FRandomStream(Inputs[0]._Seed).FRandRange(Min, Max);
		}
		void InitCpp(const TArray<FString>& Inputs, const TArray<FString>& Outputs, FVoxelCppConstructor& Constructor) const override
		{
			Constructor.AddLine(RandFloatVariable.GetName() + " = FRandomStream(" + Inputs[0] + ")" + ".FRandRange(" + FString::SanitizeFloat(Min) + "f, " + FString::SanitizeFloat(Max) + "f);");
		}

		void Compute(FVoxelNodeType Inputs[], FVoxelNodeType Outputs[], const FVoxelContext& Context) const override
		{
			Outputs[0]._float = RandFloat;
		}
		void ComputeCpp(const TArray<FString>& Inputs, const TArray<FString>& Outputs, FVoxelCppConstructor& Constructor) const override
		{
			Constructor.AddLine(Outputs[0] + " = " + RandFloatVariable.GetName() + ";");
		}

	private:
		float Min;
		float Max;
		float RandFloat;
		FVoxelVariable const RandFloatVariable;
	};
};

// A random number >= Min and <= Max
UCLASS(meta = (DisplayName = "Rand int"))
class VOXEL_API UVoxelNode_RandomInt : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Voxel")
	int Min = 0;
	UPROPERTY(EditAnywhere, Category = "Voxel")
	int Max = 100;

	UVoxelNode_RandomInt()
	{
		SetInputs(EC::Seed, "Seed");
		SetOutputs(EC::Int);
	}

	FText GetTitle() const override { return FText::FromString("Rand Int " + FString::FromInt(Min) + " " + FString::FromInt(Max)); }

	class FLocalVoxelComputeNode : public FVoxelComputeNode
	{
	public:
		FLocalVoxelComputeNode(const UVoxelNode_RandomInt* Node, const FVoxelCompilationNode* CompilationNode)
			: FVoxelComputeNode(Node, CompilationNode)
			, Min(Node->Min)
			, Max(Node->Max)
			, RandIntVariable(FVoxelVariable("int", CompilationNode->GetName() + "_RandInt"))
		{
		}

		void SetupConstructor(FVoxelCppConstructor& Constructor) const override
		{
			Constructor.AddPrivateVariable(RandIntVariable);
		}
		
		void Init(FVoxelNodeType Inputs[], FVoxelNodeType Outputs[], const FVoxelWorldGeneratorInit& Init) override
		{
			RandInt = FRandomStream(Inputs[0]._Seed).RandRange(Min, Max);
		}
		void InitCpp(const TArray<FString>& Inputs, const TArray<FString>& Outputs, FVoxelCppConstructor& Constructor) const override
		{
			Constructor.AddLine(RandIntVariable.GetName() + " = FRandomStream(" + Inputs[0] + ")" + ".RandRange(" + FString::FromInt(Min) + ", " + FString::FromInt(Max) + ");");
		}

		void Compute(FVoxelNodeType Inputs[], FVoxelNodeType Outputs[], const FVoxelContext& Context) const override
		{
			Outputs[0]._int = RandInt;
		}
		void ComputeCpp(const TArray<FString>& Inputs, const TArray<FString>& Outputs, FVoxelCppConstructor& Constructor) const override
		{
			Constructor.AddLine(Outputs[0] + " = " + RandIntVariable.GetName() + ";");
		}

	private:
		int Min;
		int Max;
		int RandInt;
		FVoxelVariable const RandIntVariable;
	};
};

// World Voxel Size
UCLASS(meta = (DisplayName = "Voxel Size"))
class VOXEL_API UVoxelNode_VoxelSize : public UVoxelNodeHelper
{
	GENERATED_BODY()
	GENERATED_VOXELNODE_BODY()

public:
	UVoxelNode_VoxelSize()
	{
		SetOutputs(EC::Float);
	}
	
	class FLocalVoxelComputeNode : public FVoxelComputeNode
	{
	public:
		FLocalVoxelComputeNode(const UVoxelNode_VoxelSize* Node, const FVoxelCompilationNode* CompilationNode)
			: FVoxelComputeNode(Node, CompilationNode)
			, VoxelSizeVariable(FVoxelVariable("float", CompilationNode->GetName() + "_VoxelSize"))
		{
		}

		void SetupConstructor(FVoxelCppConstructor& Constructor) const override
		{
			Constructor.AddPrivateVariable(VoxelSizeVariable);
		}
		
		void Init(FVoxelNodeType Inputs[], FVoxelNodeType Outputs[], const FVoxelWorldGeneratorInit& Init) override
		{
			VoxelSize = Init.VoxelSize;
		}
		void InitCpp(const TArray<FString>& Inputs, const TArray<FString>& Outputs, FVoxelCppConstructor& Constructor) const override
		{
			Constructor.AddLine(VoxelSizeVariable.GetName() + " = " + Constructor.GetInitStructString() + ".VoxelSize;");
		}

		void Compute(FVoxelNodeType Inputs[], FVoxelNodeType Outputs[], const FVoxelContext& Context) const override
		{
			Outputs[0]._float = VoxelSize;
		}
		void ComputeCpp(const TArray<FString>& Inputs, const TArray<FString>& Outputs, FVoxelCppConstructor& Constructor) const override
		{
			Constructor.AddLine(Outputs[0] + " = " + VoxelSizeVariable.GetName() + ";");
		}

	private:
		float VoxelSize;
		FVoxelVariable const VoxelSizeVariable;
	};
};

#undef LOCTEXT_NAMESPACE
