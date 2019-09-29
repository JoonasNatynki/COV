// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HoveringMotion.generated.h"

class UMeshComponent;

DECLARE_LOG_CATEGORY_EXTERN(LogHoveringMotion, Log, All)

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMEPLAYOBJECTCOMPONENTS_API UHoveringMotion : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHoveringMotion();

	UPROPERTY()
		//	The hovering mesh of the actor
		UMeshComponent* MeshToHover;

	UPROPERTY(Category = "Hovering Motion", EditAnywhere)
		bool bIsAnimating = true;


	UPROPERTY(Category = "Hovering Motion", EditAnywhere)
		//	If the mesh will rotate
		bool bRotate = true;

	UPROPERTY(Category = "Hovering Motion", EditAnywhere, meta = (EditCondition = "bRotate"))
		//	If the mesh will rotate around x axis
		bool bRotateXAxis = true;

	UPROPERTY(Category = "Hovering Motion", EditAnywhere, meta = (EditCondition = "bRotate"))
		//	If the mesh will rotate around y axis
		bool bRotateYAxis = true;

	UPROPERTY(Category = "Hovering Motion", EditAnywhere, meta = (EditCondition = "bRotate"))
		//	If the mesh will rotate around z axis
		bool bRotateZAxis = true;

	UPROPERTY(Category = "Hovering Motion", EditAnywhere, meta = (EditCondition = "bRotate"))
		float XAxisRotationSpeed = 0.26f;

	UPROPERTY(Category = "Hovering Motion", EditAnywhere, meta = (EditCondition = "bRotate"))
		float YAxisRotationSpeed = -0.2f;

	UPROPERTY(Category = "Hovering Motion", EditAnywhere, meta = (EditCondition = "bRotate"))
		float ZAxisRotationSpeed = 0.2f;

	UPROPERTY(Category = "Hovering Motion", EditAnywhere, meta = (EditCondition = "bRotate"))
		//	If the mesh will rotate around z axis
		bool bRandomizeInitialRotation = true;



	UPROPERTY(Category = "Hovering Motion", EditAnywhere)
		//	If the mesh will hover
		bool bHoverMovement = true;

	UPROPERTY(Category = "Hovering Motion", EditAnywhere, meta = (EditCondition = "bHoverMovement"))
		//	If the mesh will rotate around z axis
		bool bHoverXAxis = false;
	
	UPROPERTY(Category = "Hovering Motion", EditAnywhere, meta = (EditCondition = "bHoverMovement"))
		//	If the mesh will rotate around z axis
		bool bHoverYAxis = false;

	UPROPERTY(Category = "Hovering Motion", EditAnywhere, meta = (EditCondition = "bHoverMovement"))
		//	If the mesh will rotate around z axis
		bool bHoverZAxis = true;

	UPROPERTY(Category = "Hovering Motion", EditAnywhere, meta = (EditCondition = "bHoverMovement"))
		float HoverXMovementDistance = 0.0f;

	UPROPERTY(Category = "Hovering Motion", EditAnywhere, meta = (EditCondition = "bHoverMovement"))
		float HoverYMovementDistance = 0.0f;

	UPROPERTY(Category = "Hovering Motion", EditAnywhere, meta = (EditCondition = "bHoverMovement"))
		float HoverZMovementDistance = 20.0f;

	UPROPERTY(Category = "Hovering Motion", EditAnywhere, meta = (EditCondition = "bHoverMovement"))
		float HoverRepeatFrequency = 1.0f;




	UFUNCTION(Category = "Hovering Motion", BlueprintCallable)
		void SetHoveringMesh(UMeshComponent* meshComponentToHover);

	UFUNCTION(Category = "Hovering Motion", BlueprintCallable)
		void SetAnimating(bool bShouldAnimate);




	void UpdateMeshTransform(float deltaTime);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	//	If the component is rotating the root mesh. This determines if its just a local hovering transformation or the actual actors world location. This is expensive if simulated over the network
	bool bIsRotatingRootMesh = false;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
