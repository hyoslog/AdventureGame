// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ATScene.h"
#include "ATTitleScene.generated.h"

/**
 * 
 */
UCLASS()
class UATTitleScene final : public UATScene
{
	GENERATED_BODY()

private:
	UATTitleScene();
	
private:
	virtual void OnPostCreateWidgetInstance() override;

private:
	UFUNCTION()
	void OnMouseButtonDownEvent();
};
