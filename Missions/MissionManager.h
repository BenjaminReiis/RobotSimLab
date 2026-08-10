#pragma once

#include "CoreMinimal.h"
#include "Missions/MissionBase.h"
#include "MissionManager.generated.h"

UCLASS(Blueprintable)
class ROBOTSIMLAB_API UMissionManager : public UObject
{
    GENERATED_BODY()

public:

    UPROPERTY(BlueprintReadOnly, Category = "Missions")
    UMissionBase* CurrentMission = nullptr;

    UFUNCTION(BlueprintCallable, Category = "Missions")
    void SetMission(UMissionBase* Mission);

    UFUNCTION(BlueprintCallable, Category = "Missions")
    void StartCurrentMission();

    UFUNCTION(BlueprintCallable, Category = "Missions")
    void CompleteCurrentMission();

    UFUNCTION(BlueprintCallable, Category = "Missions")
    void FailCurrentMission();

    UFUNCTION(BlueprintCallable, Category = "Missions")
    void ResetCurrentMission();
};
