// Fill out your copyright notice in the Description page of Project Settings.


#include "ATStandbyGameMode.h"

#include "ATStandbyGameState.h"

AATStandbyGameMode::AATStandbyGameMode()
{
	GameStateClass = AATStandbyGameState::StaticClass();
}
