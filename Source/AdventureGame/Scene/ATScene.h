// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ATScene.generated.h"

class UUserWidget;

/**
 * 
 */
UCLASS()
class UATScene : public UObject
{
	GENERATED_BODY()

public:
	virtual void ShowScene();
	virtual void HideScene();

protected:
	virtual void OnPostCreateWidgetInstance();
	
protected:
	UPROPERTY()
	TSubclassOf<UUserWidget>	WidgetClass;

	UPROPERTY()
	TObjectPtr<UUserWidget>		WidgetInstance;
};
