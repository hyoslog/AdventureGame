// Fill out your copyright notice in the Description page of Project Settings.


#include "ATGameMode.h"

#include "..\Character\ATCharacter.h"
#include "..\Player\ATPlayerController.h"

AATGameMode::AATGameMode()
{
	PlayerControllerClass = AATPlayerController::StaticClass();	

	static const ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Characters/BP_ATCharacter.BP_ATCharacter_C"));
	check(PlayerPawnBPClass.Class);
	DefaultPawnClass = PlayerPawnBPClass.Class;
}
