// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "ATStandbyGameState.generated.h"

class UATStandbyGameStateComponent;

/**
 * 
 */
UCLASS()
class AATStandbyGameState : public AGameStateBase
{
	GENERATED_BODY()

private:
	AATStandbyGameState(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	
private:
	UPROPERTY()
	TObjectPtr<UATStandbyGameStateComponent> StandbyGameStateComponent;
};
