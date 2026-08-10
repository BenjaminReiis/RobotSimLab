#pragma once

#include "CoreMinimal.h"
#include "SimulationTypes.generated.h"


UENUM(BlueprintType)
enum class ESimulationState : uint8
{
    Stopped     UMETA(DisplayName = "Stopped"),
    Running     UMETA(DisplayName = "Running"),
    Paused      UMETA(DisplayName = "Paused"),
    Resetting   UMETA(DisplayName = "Resetting")
};


USTRUCT(BlueprintType)
struct FSimulationSettings
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SimulationSpeed = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bUsePhysics = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bEnableSensors = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bEnableTelemetry = true;
};
