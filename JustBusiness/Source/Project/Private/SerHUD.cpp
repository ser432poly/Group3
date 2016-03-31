#include "Project.h"
#include "SerHUD.h"
#include "GameFramework/Actor.h"

ASerHUD::ASerHUD(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	/* Needs recticle texture location. That or we make it assignable in blueprint */
	static ConstructorHelpers::FObjectFinder<UTexture2D> HUDCenterDotObj(TEXT(""));
	//Reticle = UCanvas::MakeIcon(HUDCenterDotObj.Object);
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

	DrawReticle();

}

void ASerHUD::DrawReticle() {

	//float CenterX = Canvas->ClipX / 2;
//	float CenterY = Canvas->ClipY / 2;

	//Canvas->SetDrawColor(255, 255, 255, 255);
	//Canvas->DrawIcon(Reticle,
	//	CenterX - Reticle.UL*Reticle / 2.0f,
	//	CenterY - Reticle.VL*Reticle / 2.0f, 1f);
}