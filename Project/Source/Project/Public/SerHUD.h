#pragma once

#include "GameFramework/HUD.h"
#include "SerHUD.generated.h"

UENUM(BlueprintType)
enum class SerHUDState : uint8
{
	Playing,
	Paused,
	Menu
};

/**
 * 
 */
UCLASS()
class PROJECT_API ASerHUD : public AHUD
{
	GENERATED_BODY()

		ASerHUD(const FObjectInitializer& ObjectInitializer);

		SerHUDState CurrentState;
	
		/** update loop */
		virtual void DrawHUD() override;


public:

	UFUNCTION(BlueprintCallable, Category = "HUD")
		SerHUDState GetCurrentState();


	UFUNCTION(BlueprintImplementableEvent, Category = "HUDEvents")
		void MessageReceived(const FText& TextMessage);


	UFUNCTION(BlueprintNativeEvent, Category = "HUDEvents")
		void OnStateChanged(SerHUDState NewState);
};
