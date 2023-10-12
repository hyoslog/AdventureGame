// Fill out your copyright notice in the Description page of Project Settings.


#include "ATStandbyGameStateComponent.h"

UATStandbyGameStateComponent::UATStandbyGameStateComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, CurrentState(EStandbyState::None)
{
}
