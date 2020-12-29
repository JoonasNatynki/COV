// Fill out your copyright notice in the Description page of Project Settings.

#include "COVPlayerController.h"
#include "COVCharacter.h"
#include <EngineUtils.h>
#include <Kismet/KismetSystemLibrary.h>
#include "ScreenStack.h"
#include "UE4Helpers.h"

DEFINE_LOG_CATEGORY(COVPlayerController)

ACOVPlayerController::ACOVPlayerController(const class FObjectInitializer& PCIP)
{

}

void ACOVPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("E", IE_Pressed, this, &ACOVPlayerController::Input_E_Pressed);
	InputComponent->BindAction("E", IE_Released, this, &ACOVPlayerController::Input_E_Released);
	InputComponent->BindAction("Use/Interact", IE_Pressed, this, &ACOVPlayerController::Input_F_Pressed);
	InputComponent->BindAction("Use/Interact", IE_Released, this, &ACOVPlayerController::Input_F_Released);
	InputComponent->BindAction("Spacebar", IE_Pressed, this, &ACOVPlayerController::Input_Spacebar_Pressed);
	InputComponent->BindAction("Spacebar", IE_Released, this, &ACOVPlayerController::Input_Spacebar_Released);
	InputComponent->BindAction("LeftShift", IE_Pressed, this, &ACOVPlayerController::Input_LeftShift_Pressed);
	InputComponent->BindAction("LeftShift", IE_Released, this, &ACOVPlayerController::Input_LeftShift_Released);
	InputComponent->BindAction("LeftMouseButton", IE_Pressed, this, &ACOVPlayerController::Input_LeftMouseButton_Pressed);
	InputComponent->BindAction("LeftMouseButton", IE_Released, this, &ACOVPlayerController::Input_LeftMouseButton_Released);
	InputComponent->BindAction("RightMouseButton", IE_Pressed, this, &ACOVPlayerController::Input_RightMouseButton_Pressed);
	InputComponent->BindAction("RightMouseButton", IE_Released, this, &ACOVPlayerController::Input_RightMouseButton_Released);
	InputComponent->BindAction("MouseWheelUp", IE_Pressed, this, &ACOVPlayerController::Input_MouseWheelUp);
	InputComponent->BindAction("MouseWheelDown", IE_Released, this, &ACOVPlayerController::Input_MouseWheelDown);
	InputComponent->BindAction("LeftControl", IE_Pressed, this, &ACOVPlayerController::Input_LeftControl_Pressed);
	InputComponent->BindAction("LeftControl", IE_Released, this, &ACOVPlayerController::Input_LeftControl_Released);


	InputComponent->BindAxis("W", this, &ACOVPlayerController::Input_Key_W);
	InputComponent->BindAxis("D", this, &ACOVPlayerController::Input_Key_D);
	InputComponent->BindAxis("MovementInput", this, &ACOVPlayerController::Input_MovementInput);
	//InputComponent->BindAxis("MouseMovementY", this, &ACOVPlayerController::Input_MouseMovementY);
	//InputComponent->BindAxis("MouseMovementX", this, &ACOVPlayerController::Input_MouseMovementX);
}

ACOVCharacter* ACOVPlayerController::GetControlledCOVCharacter()
{
	ACOVCharacter* xyzchar = Cast<ACOVCharacter>(GetCharacter());
	return xyzchar;
}

void ACOVPlayerController::OnPossess(APawn* InPawn)
{
	APawn* _OldPawn = GetPawn();
	Super::OnPossess(InPawn);
	APawn* NewPawn = GetPawn();

	OnPawnPossessed.Broadcast(_OldPawn, NewPawn);
}

void ACOVPlayerController::OnUnPossess()
{
	APawn* _OldPawn = GetPawn();
	Super::OnUnPossess();

	OnPawnUnPossessed.Broadcast(_OldPawn);
}

void ACOVPlayerController::Input_E_Pressed_Implementation()
{
	//UE_LOG(COVPlayerController, Log, TEXT("E pressed."));
	USE_INTERFACE(GetPawn(), COVPlayerInput, Input_E_Pressed)
}

void ACOVPlayerController::Input_E_Released_Implementation()
{
	//UE_LOG(COVPlayerController, Log, TEXT("E released."));
	USE_INTERFACE(GetPawn(), COVPlayerInput, Input_E_Released)
}

void ACOVPlayerController::Input_F_Pressed_Implementation()
{
	//UE_LOG(COVPlayerController, Log, TEXT("E pressed."));
	USE_INTERFACE(GetPawn(), COVPlayerInput, Input_F_Pressed)
}

void ACOVPlayerController::Input_F_Released_Implementation()
{
	//UE_LOG(COVPlayerController, Log, TEXT("E released."));
	USE_INTERFACE(GetPawn(), COVPlayerInput, Input_F_Released)
}

void ACOVPlayerController::Input_Spacebar_Pressed_Implementation()
{
	//UE_LOG(COVPlayerController, Log, TEXT("Spacebar pressed."));
	USE_INTERFACE(GetPawn(), COVPlayerInput, Input_Spacebar_Pressed)
}

void ACOVPlayerController::Input_Spacebar_Released_Implementation()
{
	//UE_LOG(COVPlayerController, Log, TEXT("Spacebar released."))
	USE_INTERFACE(GetPawn(), COVPlayerInput, Input_Spacebar_Released)
}

void ACOVPlayerController::Input_LeftShift_Pressed_Implementation()
{
	//UE_LOG(COVPlayerController, Log, TEXT("Left shift pressed!"));
	USE_INTERFACE(GetPawn(), COVPlayerInput, Input_LeftShift_Pressed)
}

void ACOVPlayerController::Input_LeftShift_Released_Implementation()
{
	//UE_LOG(COVPlayerController, Log, TEXT("Left shift released!"));
	USE_INTERFACE(GetPawn(), COVPlayerInput, Input_LeftShift_Released)
}

void ACOVPlayerController::Input_Key_W_Implementation(float amount)
{
	USE_INTERFACE(GetPawn(), COVPlayerInput, Input_W, amount)
}

void ACOVPlayerController::Input_Key_D_Implementation(float amount)
{
	USE_INTERFACE(GetPawn(), COVPlayerInput, Input_D, amount)
}

void ACOVPlayerController::Input_LeftMouseButton_Pressed_Implementation()
{
	//UE_LOG(COVPlayerController, Log, TEXT("Left mouse button pressed."))
	USE_INTERFACE(GetPawn(), COVPlayerInput, Input_LeftMouseButton_Pressed)
}

void ACOVPlayerController::Input_LeftMouseButton_Released_Implementation()
{
	//UE_LOG(COVPlayerController, Log, TEXT("Left mouse button released."))
	USE_INTERFACE(GetPawn(), COVPlayerInput, Input_LeftMouseButton_Released)
}

void ACOVPlayerController::Input_RightMouseButton_Pressed_Implementation()
{
	//UE_LOG(COVPlayerController, Log, TEXT("Right mouse button pressed."))
	USE_INTERFACE(GetPawn(), COVPlayerInput, Input_RightMouseButton_Pressed)
}

void ACOVPlayerController::Input_RightMouseButton_Released_Implementation()
{
	//UE_LOG(COVPlayerController, Log, TEXT("Right mouse button released."))
	USE_INTERFACE(GetPawn(), COVPlayerInput, Input_RightMouseButton_Released)
}

void ACOVPlayerController::Input_MouseMovementX_Implementation(float amount)
{
	USE_INTERFACE(GetPawn(), COVPlayerInput, Input_MouseMovementX, amount)
	AddYawInput(amount * _XSensitivity);
}

void ACOVPlayerController::Input_MouseMovementY_Implementation(float amount)
{
	USE_INTERFACE(GetPawn(), COVPlayerInput, Input_MouseMovementY, amount)
		AddPitchInput(amount * _YSensitivity);
}

void ACOVPlayerController::Input_MovementInput_Implementation(float amount)
{
	USE_INTERFACE(GetPawn(), COVPlayerInput, Input_MovementInput, amount)
}

void ACOVPlayerController::Input_MouseWheelUp_Implementation()
{
	USE_INTERFACE(GetPawn(), COVPlayerInput, Input_MouseWheelUp);
}

void ACOVPlayerController::Input_MouseWheelDown_Implementation()
{
	USE_INTERFACE(GetPawn(), COVPlayerInput, Input_MouseWheelDown);
}

void ACOVPlayerController::Input_LeftControl_Pressed_Implementation()
{
	USE_INTERFACE(GetPawn(), COVPlayerInput, Input_LeftControl_Pressed);
}

void ACOVPlayerController::Input_LeftControl_Released_Implementation()
{
	USE_INTERFACE(GetPawn(), COVPlayerInput, Input_LeftControl_Released);
}