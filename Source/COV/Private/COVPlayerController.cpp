// Fill out your copyright notice in the Description page of Project Settings.

#include "COVPlayerController.h"
#include "COVCharacter.h"
#include <EngineUtils.h>

DEFINE_LOG_CATEGORY(XYZPlayerController)

//	BEGINNING OF USE INTERFACE MAKRO	###############################################################################
#define USE_INTERFACE(_object, _interface, _functionname, ...) TWeakObjectPtr<UObject> interfaceObject = _object;\
if (interfaceObject.IsValid())\
{\
	if (interfaceObject->GetClass()->ImplementsInterface(U##_interface::StaticClass()))\
	{\
		I##_interface::Execute_##_functionname(interfaceObject.Get(), ##__VA_ARGS__);\
	}\
	else\
	{\
		/*UE_LOG(LogTemp, Log, TEXT("Using interface failed! The object does not implement such."));*/\
	}\
}\
//	END OF USING INTERFACE MAKRO	###################################################################################

void ACOVPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("SpaceBar", IE_Pressed, this, &ACOVPlayerController::Input_SpaceBar_Pressed);
	InputComponent->BindAction("SpaceBar", IE_Released, this, &ACOVPlayerController::Input_SpaceBar_Released);
	InputComponent->BindAction("LeftMouseButton", IE_Pressed, this, &ACOVPlayerController::Input_LeftMouseButton_Pressed);
	InputComponent->BindAction("LeftMouseButton", IE_Released, this, &ACOVPlayerController::Input_LeftMouseButton_Released);
	InputComponent->BindAction("Interact", IE_Pressed, this, &ACOVPlayerController::Input_Interact);

	InputComponent->BindAxis("W", this, &ACOVPlayerController::Input_Key_W_Pressed);
	InputComponent->BindAxis("D", this, &ACOVPlayerController::Input_Key_D_Pressed);
	InputComponent->BindAxis("MouseMovementY", this, &ACOVPlayerController::Input_MouseMovementY);
	InputComponent->BindAxis("MouseMovementX", this, &ACOVPlayerController::Input_MouseMovementX);
}

void ACOVPlayerController::XYZ_Init()
{


}

ACOVCharacter* ACOVPlayerController::GetControlledCOVCharacter()
{
	ACOVCharacter* xyzchar = Cast<ACOVCharacter>(GetCharacter());
	return xyzchar;
}

void ACOVPlayerController::Input_Interact_Implementation()
{
	GetControlledCOVCharacter()->Input_Interact();
}

void ACOVPlayerController::Input_SpaceBar_Pressed_Implementation()
{
	UE_LOG(XYZPlayerController, Log, TEXT("Spacebar pressed."));
}

void ACOVPlayerController::Input_SpaceBar_Released_Implementation()
{
	UE_LOG(XYZPlayerController, Log, TEXT("Spacebar released."))
}

void ACOVPlayerController::Input_LeftMouseButton_Pressed_Implementation()
{
	UE_LOG(XYZPlayerController, Log, TEXT("Left mouse button pressed."))
}

void ACOVPlayerController::Input_LeftMouseButton_Released_Implementation()
{
	UE_LOG(XYZPlayerController, Log, TEXT("Left mouse button released."))
}

void ACOVPlayerController::Input_Key_W_Pressed_Implementation(float amount)
{
	USE_INTERFACE(GetPawn(), COVPlayerInput, Input_W, amount)
}

void ACOVPlayerController::Input_Key_D_Pressed_Implementation(float amount)
{
	USE_INTERFACE(GetPawn(), COVPlayerInput, Input_D, amount)
}

void ACOVPlayerController::Input_MouseMovementX_Implementation(float amount)
{
	AddYawInput(amount * _XSensitivity);
}

void ACOVPlayerController::Input_MouseMovementY_Implementation(float amount)
{
	AddPitchInput(amount * _YSensitivity);
}