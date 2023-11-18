// Fill out your copyright notice in the Description page of Project Settings.


#include "ATCharacter.h"

#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AATCharacter::AATCharacter()
	: DefaultMappingContext(nullptr)
	, JumpAction(nullptr)
	, MoveAction(nullptr)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// SpringArm 持失
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	check(SpringArm);
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 400.0f;

	// Camera 持失
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	check(Camera);
	Camera->SetupAttachment(SpringArm);
}

// Called when the game starts or when spawned
void AATCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	// Add Input Mapping Context
	check(DefaultMappingContext);
	const APlayerController* const PlayerController = Cast<APlayerController>(Controller);
	check(PlayerController);
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(DefaultMappingContext, 0);
}

// Called every frame
void AATCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AATCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	check(EnhancedInputComponent);

	// Jump
	check(JumpAction);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &AATCharacter::Jump);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &AATCharacter::StopJumping);

	// Move
	check(MoveAction);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AATCharacter::Move);
}

void AATCharacter::Move(const FInputActionValue& InValue)
{
	// input is a Vector2D
	const FVector2D MovementVector = InValue.Get<FVector2D>();

	if (Controller == nullptr)
	{
		check(0);
		return;
	}

	// find out which way is forward
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	// get forward vector
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

	// get right vector 
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	// add movement 
	AddMovementInput(ForwardDirection, MovementVector.Y);
	AddMovementInput(RightDirection, MovementVector.X);
}

