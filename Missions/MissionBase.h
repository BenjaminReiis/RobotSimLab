#pragma once

#include "CoreMinimal.h"
#include "MissionTypes.h"
#include "MissionBase.generated.h"

UCLASS(Blueprintable)
class ROBOTSIMLAB_API UMissionBase : public UObject
{
    GENERATED_BODY()

public:

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission")
    FString MissionId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission")
    FString MissionName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission")
    EMissionType MissionType = EMissionType::Custom;

    UPROPERTY(BlueprintReadOnly, Category = "Mission")
    EMissionState State = EMissionState::Inactive;

    UFUNCTION(BlueprintCallable, Category = "Mission")
    virtual void StartMission();

    UFUNCTION(BlueprintCallable, Category = "Mission")
    virtual void CompleteMission();

    UFUNCTION(BlueprintCallable, Category = "Mission")
    virtual void FailMission();

    UFUNCTION(BlueprintCallable, Category = "Mission")
    virtual void ResetMission();
};
