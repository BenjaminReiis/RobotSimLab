#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Core/RobotTelemetry.h"
#include "TelemetrySubsystem.generated.h"

UCLASS()
class ROBOTSIMLAB_API UTelemetrySubsystem : public UWorldSubsystem
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable, Category = "Telemetry")
    void UpdateTelemetry(const FRobotTelemetry& NewTelemetry);

    UFUNCTION(BlueprintPure, Category = "Telemetry")
    FRobotTelemetry GetTelemetry() const;

    UFUNCTION(BlueprintPure, Category = "Telemetry")
    bool HasWarning() const;

    UFUNCTION(BlueprintPure, Category = "Telemetry")
    bool HasCriticalFault() const;

private:

    UPROPERTY()
    FRobotTelemetry CurrentTelemetry;
};
