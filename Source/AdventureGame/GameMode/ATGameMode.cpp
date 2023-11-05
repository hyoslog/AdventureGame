// Fill out your copyright notice in the Description page of Project Settings.


#include "ATGameMode.h"

#include "..\Character\ATCharacter.h"
#include "..\Player\ATPlayerController.h"

AATGameMode::AATGameMode()
{
	PlayerControllerClass = AATPlayerController::StaticClass();
	DefaultPawnClass = AATCharacter::StaticClass();
}
