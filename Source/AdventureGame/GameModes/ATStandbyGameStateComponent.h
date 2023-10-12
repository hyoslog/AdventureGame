// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameStateComponent.h"
#include "ATStandbyGameStateComponent.generated.h"

/**
 * 
 */
UCLASS()
class UATStandbyGameStateComponent : public UGameStateComponent
{
	GENERATED_BODY()
	
public:
	enum class EStandbyState
	{
		None,
		Logo,
		StartMenu
	};

private:
	UATStandbyGameStateComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	EStandbyState CurrentState;
};
