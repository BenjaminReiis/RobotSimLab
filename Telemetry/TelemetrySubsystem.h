#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"

#include "../Core/RobotTelemetry.h"

#include "TelemetrySubsystem.generated.h"

class ARobotBase;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
    FOnRobotTelemetryUpdated,
    FRobotTelemetry,
    Telemetry
);

UCLASS()
class ROBOTSIMLAB_API UTelemetrySubsystem
    : public UWorldSubsystem
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable)
    void RegisterRobot(ARobotBase* Robot);

    UFUNCTION(BlueprintCallable)
    void UnregisterRobot(ARobotBase* Robot);

    UFUNCTION(BlueprintCallable)
    FRobotTelemetry GetRobotTelemetry(
        ARobotBase* Robot
    ) const;

    UPROPERTY(BlueprintAssignable)
    FOnRobotTelemetryUpdated OnTelemetryUpdated;

    virtual void Tick(
        float DeltaTime
    ) override;

    virtual bool IsTickable() const override
    {
        return true;
    }

private:

    UPROPERTY()
    TArray<TObjectPtr<ARobotBase>> Robots;
};
