#include "PIDController.h"

FPIDController::FPIDController()
    : Kp(1.0f)
    , Ki(0.0f)
    , Kd(0.0f)
    , Integral(0.0f)
    , PreviousError(0.0f)
    , OutputMin(-1.0f)
    , OutputMax(1.0f)
    , bInitialized(false)
{
}

FPIDController::FPIDController(
    float InKp,
    float InKi,
    float InKd
)
    : Kp(InKp)
    , Ki(InKi)
    , Kd(InKd)
    , Integral(0.0f)
    , PreviousError(0.0f)
    , OutputMin(-1.0f)
    , OutputMax(1.0f)
    , bInitialized(false)
{
}

void FPIDController::SetParameters(
    float InKp,
    float InKi,
    float InKd
)
{
    Kp = InKp;
    Ki = InKi;
    Kd = InKd;
}

void FPIDController::SetOutputLimits(
    float InMin,
    float InMax
)
{
    OutputMin = InMin;
    OutputMax = InMax;
}

void FPIDController::Reset()
{
    Integral = 0.0f;
    PreviousError = 0.0f;
    bInitialized = false;
}

float FPIDController::Calculate(
    float Setpoint,
    float Measurement,
    float DeltaTime
)
{
    if (DeltaTime <= KINDA_SMALL_NUMBER)
    {
        return 0.0f;
    }

    const float Error = Setpoint - Measurement;

    Integral += Error * DeltaTime;

    const float Derivative =
        bInitialized
            ? (Error - PreviousError) / DeltaTime
            : 0.0f;

    float Output =
        (Kp * Error) +
        (Ki * Integral) +
        (Kd * Derivative);

    Output = FMath::Clamp(
        Output,
        OutputMin,
        OutputMax
    );

    /*
     * Anti-windup simples.
     */
    if (Output == OutputMin || Output == OutputMax)
    {
        Integral -= Error * DeltaTime;
    }

    PreviousError = Error;
    bInitialized = true;

    return Output;
}

float FPIDController::GetKp() const
{
    return Kp;
}

float FPIDController::GetKi() const
{
    return Ki;
}

float FPIDController::GetKd() const
{
    return Kd;
}
