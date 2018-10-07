// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/EngineTypes.h"
#include "COVBlueprintFunctionLibrary.generated.h"


DECLARE_LOG_CATEGORY_EXTERN(COVBlueprintFunctionLibrary, Log, All)


//	MACROS	#####################################################################################################################
#define PRINT_FUNCTION *FString(__FUNCTION__).Append(":(").Append(FString::FormatAsNumber(__LINE__)).Append("): ")

#define IS_SERVER GetNetMode() == ENetMode::NM_DedicatedServer || GetNetMode() == ENetMode::NM_ListenServer
//#define XYZLOG(category, log category, msg, ...) UE_LOG(category, log category, TEXT("%s: %s"), PRINT_FUNCTION, TEXT(msg), ##__VA_ARGS__)

#define IS_NOT_LOCALLY_CONTROLLED_WARNING if(!IsLocallyControlled()){UE_LOG(LogTemp, Warning, TEXT("%s: Should a non-client be calling this function?"), PRINT_FUNCTION)}

#define COV_LOG(_namespace, _logcategory, _text, ...) \
{\
const FString appendText = FString::Printf(_text, ##__VA_ARGS__);\
UE_LOG(_namespace, _logcategory, TEXT("%s%s"), PRINT_FUNCTION, *appendText);\
}

#define GET_AND_STORE_COMPONENT(_componentclass, _containervariablename) {\
_componentclass* tempComp = nullptr;\
TSet<UActorComponent*> comps = GetComponents();\
for (auto & comp : comps)\
{\
	tempComp = Cast<_componentclass>(comp);\
	if (tempComp)\
	{\
		_containervariablename = tempComp;\
		break;\
	}\
}\
ensureMsgf(tempComp != nullptr, TEXT("##_componentclass Component was not found! Please add it as a component to this actor or the actor won't work properly!"));\
}\

//	BEGINNING OF USE INTERFACE MAKRO	###############################################################################
#define USE_INTERFACE(_objectwithinterface, _interface, _functionname, ...) TWeakObjectPtr<UObject> interfaceObject = _objectwithinterface;\
if (interfaceObject.IsValid())\
{\
	if (interfaceObject->GetClass()->ImplementsInterface(U##_interface::StaticClass()))\
	{\
		I##_interface::Execute_##_functionname(interfaceObject.Get(), ##__VA_ARGS__);\
	}\
	else\
	{\
		UE_LOG(LogTemp, Log, TEXT("Using interface failed! The object (%s) does not implement such."), *UKismetSystemLibrary::GetDisplayName(_objectwithinterface));\
	}\
}\
//	END OF USING INTERFACE MAKRO	###################################################################################
//	#####################################################################################################################

template<typename T>
static FString EnumToString(const FString& enumName, const T value)
{
	UEnum* pEnum = FindObject<UEnum>(ANY_PACKAGE, *enumName);
	return *(pEnum ? pEnum->GetNameStringByIndex(static_cast<uint8>(value)) : "null");
}


UCLASS()
class COV_API UCOVBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	//	Simplified line trace function. Parameters: 1) Starting position, 2) end position and 3) an actor in the world that will be "casting" this line trace
	UFUNCTION(Category = "COVFunctionLibrary", BlueprintCallable)
		static FHitResult SimpleTraceByChannel(UObject* castingObject, FVector startPos, FVector endPos, ECollisionChannel channel, FName TraceTag);
	UFUNCTION(Category = "COVFunctionLibrary", BlueprintCallable)
		static FHitResult CastCrossHairLineTrace(AActor* character, float rayDistance);

	UFUNCTION(Category = "COVFunctionLibrary", BlueprintCallable)
		//	Will read a file in a specific folder with the variable name
		static FString ReadFileLine(FString InFileName, FString Folder, FString ConfigName);
	UFUNCTION(Category = "COVFunctionLibrary", BlueprintCallable)
		//	Will read a file's variable's value in the config folder
		static FString ReadConfigFileLine(FString InFileName, FString ConfigName);
	UFUNCTION(Category = "COVFunctionLibrary", BlueprintCallable)
		//	Will return the number of lines in a file. No file found = -1
		static int32 GetNumberOfRowsInFile(FString InFileName, FString Folder);
	UFUNCTION(Category = "COVFunctionLibrary", BlueprintCallable, BlueprintPure)
		static FString GetGameVersionAsString();
};

/*
Timer example
	FTimerHandle smallDelay;
	FTimerDelegate TimerCallback;
	TimerCallback.BindLambda([&]
	{
		SetActorTickEnabled(true);
	});

	GetWorld()->GetTimerManager().SetTimer(smallDelay, TimerCallback, 0.4f, false, 0.5f);
*/