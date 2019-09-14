// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "UE4Helpers.generated.h"

class FUE4HelpersModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};


DECLARE_LOG_CATEGORY_EXTERN(LogUE4CodeHelpers, Log, All)


//	MACROS	#####################################################################################################################

//	Print function name as a UE_LOG parameter
#define PRINT_FUNCTION *FString(__FUNCTION__).Append(":(").Append(FString::FormatAsNumber(__LINE__)).Append("): ")

//	Check if the actor/actorcomponent is running this code on the server
#define IS_SERVER GetNetMode() == ENetMode::NM_DedicatedServer || GetNetMode() == ENetMode::NM_ListenServer

//	Extended logging macro. Prints out additional information to the log text
//#define UE4_ELOG(category, log category, msg, ...) UE_LOG(category, log category, TEXT("%s: %s"), PRINT_FUNCTION, TEXT(msg), ##__VA_ARGS__)

//	A one line macro to print out a warning if running the piece of code on a non-locally controlled pawn
#define IS_NOT_LOCALLY_CONTROLLED_WARNING if(!IsLocallyControlled()){UE_LOG(LogUE4CodeHelpers, Warning, TEXT("%s: Should a non-client be calling this function?"), PRINT_FUNCTION)}

//	Extended logging macro. Prints out additional information to the log text
#define UE_ELOG(_namespace, _logcategory, _text, ...) \
{\
const FString appendText = FString::Printf(_text, ##__VA_ARGS__);\
UE_LOG(_namespace, _logcategory, TEXT("%s%s"), PRINT_FUNCTION, *appendText);\
}

//	Handy macro for searching a component and storing it into a variable
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

//	Handy macro for searching a component and storing it into a variable. Call this only on actor components
#define GET_AND_STORE_COMPONENT_FROM_COMPONENT(_componentclass, _containervariablename) {\
_componentclass* tempComp = nullptr;\
TSet<UActorComponent*> comps = GetOwner()->GetComponents();\
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

//	Handy macro for using an interface on one line
#define USE_INTERFACE(_objectwithinterface, _interface, _functionname, ...) TWeakObjectPtr<UObject> interfaceObject = _objectwithinterface;\
if (interfaceObject.IsValid())\
{\
	if (interfaceObject->GetClass()->ImplementsInterface(U##_interface::StaticClass()))\
	{\
		I##_interface::Execute_##_functionname(interfaceObject.Get(), ##__VA_ARGS__);\
	}\
	else\
	{\
		UE_LOG(LogUE4CodeHelpers, Log, TEXT("Using interface failed! The object (%s) does not implement such."), *GetNameSafe(_objectwithinterface));\
	}\
}\

#define SIMPLE_DELAY(_funcDef, rate, bLooping, firstDelay)\
FTimerHandle smallDelay;\
FTimerDelegate timerCallback;\
timerCallback.BindLambda([&]\
{\
	_funcDef\
});\
GetWorld()->GetTimerManager().SetTimer(smallDelay, timerCallback, rate, bLooping, firstDelay);\

//	Converts an enum to string. Useful in printing out logs etc...
template<typename T>
static FString EnumToString(const FString& enumName, const T value)
{
	UEnum* pEnum = FindObject<UEnum>(ANY_PACKAGE, *enumName);
	return *(pEnum ? pEnum->GetNameStringByIndex(static_cast<uint8>(value)) : "null");
}

//	Blueprint function library class
UCLASS()
class UE4HELPERS_API UE4CodeHelpers : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	//	Simplified line trace function with a baked in Trace Parameter initialization
	UFUNCTION(Category = "UE4CodeHelpers", BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
		static FHitResult SimpleTraceByChannel(UObject* WorldContextObject, const FVector& startPos, const FVector& endPos, const ECollisionChannel& channel, const FName& TraceTag);
	UFUNCTION(Category = "UE4CodeHelpers", BlueprintCallable)
		//	A simplified line tracer for getting a hit on your cross hairs
		static FHitResult CastCrossHairLineTrace(AActor* character, float rayDistance);

	UFUNCTION(Category = "UE4CodeHelpers", BlueprintCallable)
		//	Will read a file in a specific folder with the variable name
		static FString GetVariableValueFromFile(const FString& InFileName, const FString& Folder, const FString& ConfigName);
	UFUNCTION(Category = "UE4CodeHelpers", BlueprintCallable)
		//	Will read a file's variable's value in the config folder
		static FString GetConfigFileLine(const FString& InFileName, const FString& ConfigName);
	UFUNCTION(Category = "UE4CodeHelpers", BlueprintCallable)
		//	Will return the number of lines in a file. No file found = -1
		static int32 GetNumberOfRowsInFile(const FString& InFileName, const FString& Folder);
	UFUNCTION(Category = "UE4CodeHelpers", BlueprintCallable, BlueprintPure)
		//	Will return the number of commits in a the repository. No repository found = -1
		static int32 GetRepositoryCommitCount();
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