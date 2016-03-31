#include "Project.h"
#include "SerHUD.h"


ASerHUD::ASerHUD(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

void ASerHUD::OnStateChanged_Implementation(SerHUDState NewState)
{
	CurrentState = NewState;
}


SerHUDState ASerHUD::GetCurrentState()
{
	return CurrentState;
}

void ASerHUD::DrawHUD()
{
	Super::DrawHUD();

}
