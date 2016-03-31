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



	//FCanvasIcon Reticle;

	SerHUDState CurrentState;


	/** update loop */
	virtual void DrawHUD() override;

	void DrawReticle();


public:

	UFUNCTION(BlueprintCallable, Category = "HUD")
		SerHUDState GetCurrentState();

	/* Event to call HUD text events to display in the HUD. Blueprint HUD class must implement how to deal with this event. */
	UFUNCTION(BlueprintImplementableEvent, Category = "HUDEvents")
		void MessageReceived(const FText& TextMessage);

	/* Event to update HUD state  */
	UFUNCTION(BlueprintNativeEvent, Category = "HUDEvents")
		void OnStateChanged(SerHUDState NewState);
};
