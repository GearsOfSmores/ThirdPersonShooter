// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef SHOOTER_Item_generated_h
#error "Item.generated.h already included, missing '#pragma once' in Item.h"
#endif
#define SHOOTER_Item_generated_h

#define Shooter___Test_Source_Shooter_Item_h_35_SPARSE_DATA
#define Shooter___Test_Source_Shooter_Item_h_35_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnSphereEndOverlap); \
	DECLARE_FUNCTION(execOnSphereOverlap);


#define Shooter___Test_Source_Shooter_Item_h_35_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnSphereEndOverlap); \
	DECLARE_FUNCTION(execOnSphereOverlap);


#define Shooter___Test_Source_Shooter_Item_h_35_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAItem(); \
	friend struct Z_Construct_UClass_AItem_Statics; \
public: \
	DECLARE_CLASS(AItem, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Shooter"), NO_API) \
	DECLARE_SERIALIZER(AItem)


#define Shooter___Test_Source_Shooter_Item_h_35_INCLASS \
private: \
	static void StaticRegisterNativesAItem(); \
	friend struct Z_Construct_UClass_AItem_Statics; \
public: \
	DECLARE_CLASS(AItem, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Shooter"), NO_API) \
	DECLARE_SERIALIZER(AItem)


#define Shooter___Test_Source_Shooter_Item_h_35_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AItem(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AItem) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AItem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AItem); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AItem(AItem&&); \
	NO_API AItem(const AItem&); \
public:


#define Shooter___Test_Source_Shooter_Item_h_35_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AItem(AItem&&); \
	NO_API AItem(const AItem&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AItem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AItem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AItem)


#define Shooter___Test_Source_Shooter_Item_h_35_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__ItemMesh() { return STRUCT_OFFSET(AItem, ItemMesh); } \
	FORCEINLINE static uint32 __PPO__CollisionBox() { return STRUCT_OFFSET(AItem, CollisionBox); } \
	FORCEINLINE static uint32 __PPO__PickupWidget() { return STRUCT_OFFSET(AItem, PickupWidget); } \
	FORCEINLINE static uint32 __PPO__AreaSphere() { return STRUCT_OFFSET(AItem, AreaSphere); } \
	FORCEINLINE static uint32 __PPO__ItemName() { return STRUCT_OFFSET(AItem, ItemName); } \
	FORCEINLINE static uint32 __PPO__ItemCount() { return STRUCT_OFFSET(AItem, ItemCount); } \
	FORCEINLINE static uint32 __PPO__ItemState() { return STRUCT_OFFSET(AItem, ItemState); } \
	FORCEINLINE static uint32 __PPO__ItemZCurve() { return STRUCT_OFFSET(AItem, ItemZCurve); } \
	FORCEINLINE static uint32 __PPO__ItemInterpStartLocation() { return STRUCT_OFFSET(AItem, ItemInterpStartLocation); } \
	FORCEINLINE static uint32 __PPO__CameraTargetLocation() { return STRUCT_OFFSET(AItem, CameraTargetLocation); } \
	FORCEINLINE static uint32 __PPO__bInterping() { return STRUCT_OFFSET(AItem, bInterping); } \
	FORCEINLINE static uint32 __PPO__ZCurveTime() { return STRUCT_OFFSET(AItem, ZCurveTime); } \
	FORCEINLINE static uint32 __PPO__Character() { return STRUCT_OFFSET(AItem, Character); } \
	FORCEINLINE static uint32 __PPO__ItemScaleCurve() { return STRUCT_OFFSET(AItem, ItemScaleCurve); }


#define Shooter___Test_Source_Shooter_Item_h_32_PROLOG
#define Shooter___Test_Source_Shooter_Item_h_35_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Shooter___Test_Source_Shooter_Item_h_35_PRIVATE_PROPERTY_OFFSET \
	Shooter___Test_Source_Shooter_Item_h_35_SPARSE_DATA \
	Shooter___Test_Source_Shooter_Item_h_35_RPC_WRAPPERS \
	Shooter___Test_Source_Shooter_Item_h_35_INCLASS \
	Shooter___Test_Source_Shooter_Item_h_35_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Shooter___Test_Source_Shooter_Item_h_35_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Shooter___Test_Source_Shooter_Item_h_35_PRIVATE_PROPERTY_OFFSET \
	Shooter___Test_Source_Shooter_Item_h_35_SPARSE_DATA \
	Shooter___Test_Source_Shooter_Item_h_35_RPC_WRAPPERS_NO_PURE_DECLS \
	Shooter___Test_Source_Shooter_Item_h_35_INCLASS_NO_PURE_DECLS \
	Shooter___Test_Source_Shooter_Item_h_35_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SHOOTER_API UClass* StaticClass<class AItem>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Shooter___Test_Source_Shooter_Item_h


#define FOREACH_ENUM_EITEMSTATE(op) \
	op(EItemState::EIS_Pickup) \
	op(EItemState::EIS_EquipInterping) \
	op(EItemState::EIS_PickedUp) \
	op(EItemState::EIS_Equipped) \
	op(EItemState::EIS_Falling) 

enum class EItemState : uint8;
template<> SHOOTER_API UEnum* StaticEnum<EItemState>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
