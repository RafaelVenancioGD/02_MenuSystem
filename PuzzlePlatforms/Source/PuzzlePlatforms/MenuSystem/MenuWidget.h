// ScalenoSoftware

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuInterface.h"
#include "MenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UMenuWidget : public UUserWidget
{
	GENERATED_BODY()	
	
public:
	void SetUp();
	void SetMenuInterface(IMenuInterface* MenuInterface);
	void Teardown();
	void OnLevelRemovedFromWorld(ULevel * InLevel, UWorld * InWorld);

protected:
	IMenuInterface * MenuInterface;	
};
