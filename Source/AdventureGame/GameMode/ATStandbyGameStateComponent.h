// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameStateComponent.h"
#include "ATStandbyGameStateComponent.generated.h"

class UUserWidget; 
class UImage;
class UATScene;

/**
 * 
 */
UCLASS()
class UATStandbyGameStateComponent final : public UGameStateComponent
{
	GENERATED_BODY()
	
public:
	/**
	* 대기 화면 타입
	* @warning ENUM 추가 시, CreateScenes(...)에도 작업 필요
	*/
	enum EStandbyScene
	{
		Title,
		StartMenu,
		Max
	};

private:
	UATStandbyGameStateComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	void ChangeScene(const EStandbyScene InState);

private:
	void CreateScenes(const FObjectInitializer& ObjectInitializer);

private:
	EStandbyScene CurrentScene;	

	UPROPERTY()
	TObjectPtr<UATScene> Scenes[EStandbyScene::Max];
};
