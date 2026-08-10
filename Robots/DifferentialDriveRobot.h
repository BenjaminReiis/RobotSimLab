#pragma once

#include "CoreMinimal.h"

#include "RobotBase.h"
#include "../Control/PIDController.h"

#include "DifferentialDriveRobot.generated.h"

UCLASS()
class ROBOTSIMLAB_API ADifferentialDriveRobot
    : public ARobotBase
{
    GENERATED_BODY()

public:

    ADifferentialDriveRobot();

    virtual void Tick(float DeltaTime) override;

    UFUNCTION(BlueprintCallable)
    void SetTargetVelocity(
        float LinearVelocity,
        float AngularVelocity
    );

    UFUNCTION(BlueprintCallable)
    void SetPIDParameters(
        float Kp,
        float Ki,
        float Kd
    );

    UFUNCTION(BlueprintCallable)
    void ResetController();

protected:

    virtual void BeginPlay() override;

private:

    void UpdateController(float DeltaTime);

    void ApplyMovement(
        float LinearVelocity,
        float AngularVelocity
    );

private:

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Drive",
        meta = (AllowPrivateAccess = "true"))
    float WheelBase;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Drive",
        meta = (AllowPrivateAccess = "true"))
    float MaximumLinearVelocity;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Drive",
        meta = (AllowPrivateAccess = "true"))
    float MaximumAngularVelocity;

    UPROPERTY(BlueprintReadOnly, Category = "Drive",
        meta = (AllowPrivateAccess = "true"))
    float TargetLinearVelocity;

    UPROPERTY(BlueprintReadOnly, Category = "Drive",
        meta = (AllowPrivateAccess = "true"))
    float TargetAngularVelocity;

    float CurrentLinearVelocity;
    float CurrentAngularVelocity;

    FPIDController LinearPID;
    FPIDController AngularPID;
};
