#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "../Core/RobotTypes.h"
#include "../Core/RobotTelemetry.h"

#include "RobotBase.generated.h"

UCLASS()
class ROBOTSIMLAB_API ARobotBase : public APawn
{
    GENERATED_BODY()

public:

    ARobotBase();

    virtual void Tick(float DeltaTime) override;

    UFUNCTION(BlueprintCallable)
    virtual void StartRobot();

    UFUNCTION(BlueprintCallable)
    virtual void StopRobot();

    UFUNCTION(BlueprintCallable)
    virtual void EmergencyStop();

    UFUNCTION(BlueprintCallable)
    FRobotTelemetry GetTelemetry() const;

    UFUNCTION(BlueprintCallable)
    ERobotState GetRobotState() const;

    UFUNCTION(BlueprintCallable)
    FString GetRobotId() const;

protected:

    virtual void BeginPlay() override;

    virtual void UpdateTelemetry(float DeltaTime);

protected:

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Robot")
    FString RobotId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Robot")
    ERobotType RobotType;

    UPROPERTY(BlueprintReadOnly, Category = "Robot")
    ERobotState RobotState;

    UPROPERTY(BlueprintReadOnly, Category = "Telemetry")
    FRobotTelemetry Telemetry;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Robot")
    float MaxSpeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Robot")
    float BatteryConsumptionRate;

    float InternalSimulationTime;

    int32 InternalCollisionCount;
};
