// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BigChungus/Public/CrabCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCrabCharacter() {}
// Cross Module References
	BIGCHUNGUS_API UClass* Z_Construct_UClass_ACrabCharacter_NoRegister();
	BIGCHUNGUS_API UClass* Z_Construct_UClass_ACrabCharacter();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_BigChungus();
// End Cross Module References
	void ACrabCharacter::StaticRegisterNativesACrabCharacter()
	{
	}
	UClass* Z_Construct_UClass_ACrabCharacter_NoRegister()
	{
		return ACrabCharacter::StaticClass();
	}
	struct Z_Construct_UClass_ACrabCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACrabCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_BigChungus,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACrabCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "CrabCharacter.h" },
		{ "ModuleRelativePath", "Public/CrabCharacter.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACrabCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACrabCharacter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACrabCharacter_Statics::ClassParams = {
		&ACrabCharacter::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_ACrabCharacter_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ACrabCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACrabCharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACrabCharacter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACrabCharacter, 1670356123);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACrabCharacter(Z_Construct_UClass_ACrabCharacter, &ACrabCharacter::StaticClass, TEXT("/Script/BigChungus"), TEXT("ACrabCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACrabCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
