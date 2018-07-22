// ScalenoSoftware

#include "MainMenu.h"
#include "Components/Button.h"

bool UMainMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) { return false; }
	if (!ensure(Host != nullptr)) {	return false; }

	Host->OnClicked.AddDynamic(this,&UMainMenu::HostServer);
	
	return true;
}

void UMainMenu::SetMenuInterface(IMenuInterface* MenuInterface)
{
	this->MenuInterface = MenuInterface;
}

void UMainMenu::SetUp()
{
	this->AddToViewport();

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) { return ; }
	APlayerController* PlayerController = World->GetFirstPlayerController();

	if (!ensure(PlayerController != nullptr)) return;

	FInputModeUIOnly InputModeData;

	InputModeData.SetWidgetToFocus(this->TakeWidget());

	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	PlayerController->SetInputMode(InputModeData);
	PlayerController->bShowMouseCursor = true;
}

void UMainMenu::OnLevelRemovedFromWorld(ULevel * InLevel, UWorld * InWorld)
{
	Super::OnLevelRemovedFromWorld(InLevel, InWorld);
	
	FInputModeGameOnly InputModeData;
	APlayerController* PlayerController = InWorld->GetFirstPlayerController();

	PlayerController->SetInputMode(InputModeData);
	PlayerController->bShowMouseCursor = false;
}


void UMainMenu::HostServer()
{
	if (MenuInterface != nullptr)
	{
		MenuInterface->Host();
	}

}