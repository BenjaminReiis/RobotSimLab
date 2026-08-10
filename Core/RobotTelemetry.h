#pragma once

#include "CoreMinimal.h"
#include "RobotTelemetry.generated.h"

USTRUCT(BlueprintType)
struct FRobotTelemetry
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly)
    FVector Position = FVector::ZeroVector;

    UPROPERTY(BlueprintReadOnly)
    FRotator Rotation = FRotator::ZeroRotator;

    UPROPERTY(BlueprintReadOnly)
    FVector Velocity = FVector::ZeroVector;

    UPROPERTY(BlueprintReadOnly)
    float Speed = 0.0f;

    UPROPERTY(BlueprintReadOnly)
    float Battery = 100.0f;

    UPROPERTY(BlueprintReadOnly)
    float SimulationTime = 0.0f;

    UPROPERTY(BlueprintReadOnly)
    int32 CollisionCount = 0;

    UPROPERTY(BlueprintReadOnly)
    float ControlFrequency = 0.0f;
};
