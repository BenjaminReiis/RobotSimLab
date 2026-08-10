#pragma once

#include "CoreMinimal.h"
#include "MissionObjective.generated.h"

USTRUCT(BlueprintType)
struct ROBOTSIMLAB_API FMissionObjective
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission")
    FString ObjectiveId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission")
    FString Description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission")
    bool bCompleted = false;
};
