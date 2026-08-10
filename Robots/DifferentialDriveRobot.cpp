#include "DifferentialDriveRobot.h"

ADifferentialDriveRobot::ADifferentialDriveRobot()
{
    PrimaryActorTick.bCanEverTick = true;

    RobotType = ERobotType::Mobile;

    WheelBase = 100.0f;

    MaximumLinearVelocity = 600.0f;

    MaximumAngularVelocity = 2.0f;

    TargetLinearVelocity = 0.0f;

    TargetAngularVelocity = 0.0f;

    CurrentLinearVelocity = 0.0f;

    CurrentAngularVelocity = 0.0f;

    LinearPID.SetParameters(
        2.0f,
        0.2f,
        0.05f
    );

    AngularPID.SetParameters(
        2.5f,
        0.15f,
        0.05f
    );

    LinearPID.SetOutputLimits(
        -MaximumLinearVelocity,
        MaximumLinearVelocity
    );

    AngularPID.SetOutputLimits(
        -MaximumAngularVelocity,
        MaximumAngularVelocity
    );
}

void ADifferentialDriveRobot::BeginPlay()
{
    Super::BeginPlay();

    ResetController();
}

void ADifferentialDriveRobot::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (RobotState != ERobotState::Running)
    {
        return;
    }

    UpdateController(DeltaTime);
}

void ADifferentialDriveRobot::SetTargetVelocity(
    float LinearVelocity,
    float AngularVelocity
)
{
    TargetLinearVelocity = FMath::Clamp(
        LinearVelocity,
        -MaximumLinearVelocity,
        MaximumLinearVelocity
    );

    TargetAngularVelocity = FMath::Clamp(
        AngularVelocity,
        -MaximumAngularVelocity,
        MaximumAngularVelocity
    );
}

void ADifferentialDriveRobot::SetPIDParameters(
    float Kp,
    float Ki,
    float Kd
)
{
    LinearPID.SetParameters(
        Kp,
        Ki,
        Kd
    );

    AngularPID.SetParameters(
        Kp,
        Ki,
        Kd
    );
}

void ADifferentialDriveRobot::ResetController()
{
    LinearPID.Reset();
    AngularPID.Reset();

    CurrentLinearVelocity = 0.0f;
    CurrentAngularVelocity = 0.0f;
}

void ADifferentialDriveRobot::UpdateController(
    float DeltaTime
)
{
    const float LinearOutput =
        LinearPID.Calculate(
            TargetLinearVelocity,
            CurrentLinearVelocity,
            DeltaTime
        );

    const float AngularOutput =
        AngularPID.Calculate(
            TargetAngularVelocity,
            CurrentAngularVelocity,
            DeltaTime
        );

    CurrentLinearVelocity = LinearOutput;

    CurrentAngularVelocity = AngularOutput;

    ApplyMovement(
        CurrentLinearVelocity,
        CurrentAngularVelocity
    );
}

void ADifferentialDriveRobot::ApplyMovement(
    float LinearVelocity,
    float AngularVelocity
)
{
    const FVector Forward =
        GetActorForwardVector();

    const FVector Movement =
        Forward * LinearVelocity;

    AddActorWorldOffset(
        Movement * GetWorld()->GetDeltaSeconds(),
        true
    );

    const float RotationDegrees =
        FMath::RadiansToDegrees(
            AngularVelocity *
            GetWorld()->GetDeltaSeconds()
        );

    AddActorWorldRotation(
        FRotator(
            0.0f,
            RotationDegrees,
            0.0f
        )
    );
}
