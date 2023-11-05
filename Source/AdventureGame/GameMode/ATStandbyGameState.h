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
class AATStandbyGameState final : public AGameStateBase
{
	GENERATED_BODY()

private:
	AATStandbyGameState(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	TObjectPtr<UATStandbyGameStateComponent> GetStandbyGameStateComponent() const { return StandbyGameStateComponent; }

private:
	virtual void PostInitializeComponents() override;
	
private:
	UPROPERTY()
	TObjectPtr<UATStandbyGameStateComponent> StandbyGameStateComponent;
};
