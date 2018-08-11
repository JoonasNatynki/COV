// Fill out your copyright notice in the Description page of Project Settings.

#include "COVBlueprintFunctionLibrary.h"
#include "CollisionQueryParams.h"
#include "Engine.h"
#include "Kismet/KismetMathLibrary.h"

FHitResult UCOVBlueprintFunctionLibrary::SimpleTraceByChannel(FVector startPos, FVector endPos, UObject* inObj)
{
	//	LINETRACE	################################
	FCollisionQueryParams RV_TraceParams = FCollisionQueryParams(FName(TEXT("Joonas")), false);
	RV_TraceParams.bTraceComplex = true;
	RV_TraceParams.bTraceAsyncScene = true;
	RV_TraceParams.bReturnPhysicalMaterial = false;
	RV_TraceParams.AddIgnoredActor(Cast<AActor>(inObj));

	//Re-initialize hit info
	FHitResult RV_Hit(ForceInit);

	//call GetWorld() from within an actor extending class
	bool blockingHit = inObj->GetWorld()->LineTraceSingleByChannel(
		RV_Hit,        //result
		startPos,    //start
		endPos, //end
		ECC_Camera, //collision channel
		RV_TraceParams
	);
	//	############################################
	return RV_Hit;
}