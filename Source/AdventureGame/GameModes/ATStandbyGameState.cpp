// Fill out your copyright notice in the Description page of Project Settings.


#include "ATStandbyGameState.h"
#include "ATStandbyGameStateComponent.h"

AATStandbyGameState::AATStandbyGameState(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	StandbyGameStateComponent = ObjectInitializer.CreateDefaultSubobject<UATStandbyGameStateComponent>(this, TEXT("StandbyGameStateComponent"));
	check(StandbyGameStateComponent);
}
