// Fill out your copyright notice in the Description page of Project Settings.


#include "ATCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AATCharacter::AATCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// SkeletalMesh 室特
	static const ConstructorHelpers::FObjectFinder<USkeletalMesh> CharacterSkeletalMesh(TEXT("/Game/Characters/Mannequins/Meshes/SKM_Quinn.SKM_Quinn"));
	if (CharacterSkeletalMesh.Succeeded() == false)
	{
		check(0);
	}
	USkeletalMeshComponent* CharacterMeshComponent = GetMesh();
	if (CharacterMeshComponent == nullptr)
	{
		check(0);
	}
	CharacterMeshComponent->SetSkeletalMesh(CharacterSkeletalMesh.Object);

	// SpringArm 持失
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	if (SpringArm == nullptr)
	{
		check(0);
	}
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 400.0f;

	// Camera 持失
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	if (Camera == nullptr)
	{
		check(0);
	}
	Camera->SetupAttachment(SpringArm);
}

// Called when the game starts or when spawned
void AATCharacter::BeginPlay()
{
	Super::BeginPlay();
	
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

}

