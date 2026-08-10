#pragma once

#include "CoreMinimal.h"

class RobotSimLab_API FPIDController
{
public:

    FPIDController();

    FPIDController(
        float InKp,
        float InKi,
        float InKd
    );

    void SetParameters(
        float InKp,
        float InKi,
        float InKd
    );

    void SetOutputLimits(
        float InMin,
        float InMax
    );

    void Reset();

    float Calculate(
        float Setpoint,
        float Measurement,
        float DeltaTime
    );

    float GetKp() const;
    float GetKi() const;
    float GetKd() const;

private:

    float Kp;
    float Ki;
    float Kd;

    float Integral;
    float PreviousError;

    float OutputMin;
    float OutputMax;

    bool bInitialized;
};
