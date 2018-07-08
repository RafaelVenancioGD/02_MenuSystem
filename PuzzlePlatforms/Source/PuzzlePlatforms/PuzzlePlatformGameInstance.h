// ScalenoSoftware

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PuzzlePlatformGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UPuzzlePlatformGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	UPuzzlePlatformGameInstance(const FObjectInitializer & FObjectInitializer);
	
	virtual void Init();

	UFUNCTION(Exec)
	void Host();

	UFUNCTION(Exec)
	void Join(const FString& Address);

private:
	TSubclassOf<class UUserWidget> MenuClass;


};
