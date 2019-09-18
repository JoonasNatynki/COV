// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/EngineTypes.h"
#include <CollisionQueryParams.h>
#include <GameFramework/Controller.h>
#include <GameFramework/Pawn.h>
#include <WorldCollision.h>
#include <UObjectIterator.h>
#include <GameFramework/PlayerController.h>

#include "UObject/Script.h"
#include "UObject/ObjectMacros.h"
#include "UObject/Object.h"
#include "Templates/SubclassOf.h"
#include "UObject/UnrealType.h"
#include "UObject/ScriptMacros.h"

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
const FString netModePrefix = UCOVBlueprintFunctionLibrary::GetNetModePrefix(this);\
UE_LOG(_namespace, _logcategory, TEXT("%s%s%s"), *netModePrefix, PRINT_FUNCTION, *appendText);\
}

#define GET_AND_CACHE_COMPONENT(_componentclass, _containervariablename) {\
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
		UE_LOG(LogTemp, Log, TEXT("Using interface failed! The object (%s) does not implement such."), *GetNameSafe(_objectwithinterface));\
	}\
}\
//	END OF USING INTERFACE MAKRO	###################################################################################
//	#####################################################################################################################

#define SIMPLE_DELAY(_funcDef, rate, bLooping, firstDelay)\
FTimerHandle smallDelay;\
FTimerDelegate timerCallback;\
timerCallback.BindLambda([&]\
{\
	_funcDef\
});\
GetWorld()->GetTimerManager().SetTimer(smallDelay, timerCallback, rate, bLooping, firstDelay);\

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
	//	Simplified line trace function with a baked in Trace Parameter initialization
	UFUNCTION(Category = "COVFunctionLibrary", BlueprintCallable)
		static FORCEINLINE FHitResult SimpleTraceByChannel(const UObject* inObj, const FVector& startPos, const FVector& endPos, ECollisionChannel channel, const FName& TraceTag);

	UFUNCTION(Category = "COVFunctionLibrary", BlueprintCallable)
		//	A simplified line tracer for getting a hit on your cross hairs
		static FORCEINLINE FHitResult CastCrossHairLineTrace(const AActor* character, float rayDistance);

	UFUNCTION(Category = "COVFunctionLibrary", BlueprintCallable)
		//	Will read a file in a specific folder with the variable name
		static FString GetFileLine(const FString& InFileName, const FString& Folder, const FString& ConfigName);

	UFUNCTION(Category = "COVFunctionLibrary", BlueprintCallable)
		//	Will read a file's variable's value in the config folder
		static FString GetConfigFileLine(const FString& InFileName, const FString& ConfigName);

	UFUNCTION(Category = "COVFunctionLibrary", BlueprintCallable)
		//	Will return the number of lines in a file. No file found = -1
		static int32 GetNumberOfRowsInFile(const FString& InFileName, const FString& Folder);

	UFUNCTION(Category = "COVFunctionLibrary", BlueprintCallable, BlueprintPure)
		//	Will return the number of commits in a the repository. No repository found = -1
		static int32 GetRepositoryCommitCount();

	UFUNCTION(Category = "COVFunctionLibrary", BlueprintCallable)
		static APlayerCameraManager* TryGetPawnCameraManager(const APawn* pawn);

	UFUNCTION(Category = "COVFunctionLibrary", BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
		static FString GetNetModePrefix(const UObject* WorldContextObject);

	UFUNCTION(Category = "COVFunctionLibrary", BlueprintCallable)
		//	Simply checks if the object is of type or not
		static bool IsOfType(const UObject* object, TSubclassOf<UObject> type);

	UFUNCTION(Category = "COVFunctionLibrary", BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
		static TArray<FVector> CalculateBarabolicTrajectory(const FVector& startLocation, const FVector& velocity, const FVector& gravity, const float samplingResolutionCoefficient, const int32 numberOfTrajectoryPoints, const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, BlueprintPure, CustomThunk, meta = (DisplayName = "Is array empty", CompactNodeTitle = "ISEMPTY", ArrayParm = "TargetArray"), Category = "Utilities|Array")
		static bool IsArrayEmpty(const TArray<int32>& TargetArray);

	UFUNCTION(Category = "COVFunctionLibrary", BlueprintCallable)
		static FRotator OrientRotationToNormalVector(const FRotator& CurrentRotation, const FVector& Normal);

	UFUNCTION(Category = "COVFunctionLibrary", BlueprintCallable)
		static TArray<UClass*> GetAllChildClassesOfType(TSubclassOf<AActor> type);

	static bool GenericIsArrayEmpty(void* targetArray, const UArrayProperty* arrayProp);

	DECLARE_FUNCTION(execIsArrayEmpty)
	{
		Stack.MostRecentProperty = nullptr;
		Stack.StepCompiledIn<UArrayProperty>(NULL);
		void* ArrayAddr = Stack.MostRecentPropertyAddress;
		UArrayProperty* ArrayProperty = Cast<UArrayProperty>(Stack.MostRecentProperty);
		if (!ArrayProperty)
		{
			Stack.bArrayContextFailed = true;
			return;
		}

		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)RESULT_PARAM = GenericIsArrayEmpty(ArrayAddr, ArrayProperty);
		P_NATIVE_END;
	}



	static FString GetNetModeName(const UObject* worldContextObject);

	static FORCEINLINE bool SimpleTraceSphere(
		AActor* ActorToIgnore,
		const FVector& Start,
		const FVector& End,
		const float Radius,
		FHitResult& HitOut,
		ECollisionChannel TraceChannel = ECC_Pawn
	);
};








FORCEINLINE bool UCOVBlueprintFunctionLibrary::SimpleTraceSphere(
	AActor* ActorToIgnore,
	const FVector& Start,
	const FVector& End,
	const float Radius,
	FHitResult& HitOut,
	ECollisionChannel TraceChannel
) {
		 FCollisionQueryParams TraceParams(FName(TEXT("SimpleTraceSphere")), true, ActorToIgnore);
		 TraceParams.bTraceComplex = true;
		 //TraceParams.bTraceAsyncScene = true;
		 TraceParams.bReturnPhysicalMaterial = false;

		 //Ignore Actors
		 TraceParams.AddIgnoredActor(ActorToIgnore);

		 //Re-initialize hit info
		 HitOut = FHitResult(ForceInit);

		 //Get World Source
		 TObjectIterator<APlayerController> ThePC;
		 if (!ThePC) return false;


		 return ThePC->GetWorld()->SweepSingleByChannel(
			 HitOut,
			 Start,
			 End,
			 FQuat(),
			 TraceChannel,
			 FCollisionShape::MakeSphere(Radius),
			 TraceParams
		 );
}

FORCEINLINE FHitResult UCOVBlueprintFunctionLibrary::SimpleTraceByChannel(const UObject* inObj, const FVector& startPos, const FVector& endPos, ECollisionChannel channel, const FName& TraceTag)
{
	FCollisionQueryParams RV_TraceParams = FCollisionQueryParams(TraceTag, false);
	RV_TraceParams.bTraceComplex = true;
	RV_TraceParams.bReturnPhysicalMaterial = false;
	RV_TraceParams.AddIgnoredActor(Cast<AActor>(inObj));
	RV_TraceParams.TraceTag = TraceTag;

	//Re-initialize hit info
	FHitResult RV_Hit(ForceInit);

	//call GetWorld() from within an actor extending class
	bool blockingHit = inObj->GetWorld()->LineTraceSingleByChannel
	(
		RV_Hit,
		startPos,
		endPos,
		channel,
		RV_TraceParams
	);
	return RV_Hit;
}

FORCEINLINE FHitResult UCOVBlueprintFunctionLibrary::CastCrossHairLineTrace(const AActor* character, float rayDistance)
{
	FHitResult RV_Hit(ForceInit);
	const APawn* pawn = Cast<APawn>(character);

	if (!ensureMsgf(IsValid(pawn), TEXT("Could not cast crosshair line trace. The actor wasn't a pawn or the pawn wasn't valid anymore.")))
	{
		return RV_Hit;
	}

	AActor* pawnCameraManager = Cast<AActor>(TryGetPawnCameraManager(pawn));

	if (IsValid(pawnCameraManager))
	{

		//	Ray starting point
		FVector playerViewWorldLocation = pawnCameraManager->GetActorLocation();
		//	end point target direction

		FVector controllerForwardVector = pawnCameraManager->GetActorForwardVector();

		RV_Hit = UCOVBlueprintFunctionLibrary::SimpleTraceByChannel
		(
			character,
			playerViewWorldLocation + (controllerForwardVector),
			playerViewWorldLocation + (controllerForwardVector * rayDistance),
			ECollisionChannel::ECC_Camera,
			FName("AimTrace")
		);

		return RV_Hit;
	}

	return RV_Hit;
}

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