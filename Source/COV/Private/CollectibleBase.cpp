// Fill out your copyright notice in the Description page of Project Settings.

#include "CollectibleBase.h"
#include <Components/StaticMeshComponent.h>


// Sets default values
ACollectibleBase::ACollectibleBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	//	Default visual mesh
	DefaultCollectibleVisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Default visual mesh"));
	RootComponent = DefaultCollectibleVisualMesh;
}

// Called when the game starts or when spawned
void ACollectibleBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame 
void ACollectibleBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

