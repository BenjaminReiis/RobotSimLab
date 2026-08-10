#include "RobotBase.h"

ARobotBase::ARobotBase()
{
    PrimaryActorTick.bCanEverTick = true;

    RobotId = TEXT("robot_001");

    RobotType = ERobotType::Mobile;

    RobotState = ERobotState::Idle;

    MaxSpeed = 500.0f;

    BatteryConsumptionRate = 0.01f;

    InternalSimulationTime = 0.0f;

    InternalCollisionCount = 0;
}

void ARobotBase::BeginPlay()
{
    Super::BeginPlay();

    Telemetry.Position = GetActorLocation();
    Telemetry.Rotation = GetActorRotation();
}

void ARobotBase::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (RobotState == ERobotState::Running)
    {
        InternalSimulationTime += DeltaTime;

        UpdateTelemetry(DeltaTime);
    }
}

void ARobotBase::StartRobot()
{
    if (RobotState == ERobotState::Emergency)
    {
        return;
    }

    RobotState = ERobotState::Running;
}

void ARobotBase::StopRobot()
{
    RobotState = ERobotState::Paused;
}

void ARobotBase::EmergencyStop()
{
    RobotState = ERobotState::Emergency;
}

void ARobotBase::UpdateTelemetry(float DeltaTime)
{
    Telemetry.Position = GetActorLocation();

    Telemetry.Rotation = GetActorRotation();

    Telemetry.Velocity = GetVelocity();

    Telemetry.Speed = GetVelocity().Size();

    Telemetry.Battery = FMath::Max(
        0.0f,
        100.0f -
        (
            InternalSimulationTime *
            BatteryConsumptionRate
        )
    );

    Telemetry.SimulationTime =
        InternalSimulationTime;

    Telemetry.CollisionCount =
        InternalCollisionCount;
}

FRobotTelemetry ARobotBase::GetTelemetry() const
{
    return Telemetry;
}

ERobotState ARobotBase::GetRobotState() const
{
    return RobotState;
}

FString ARobotBase::GetRobotId() const
{
    return RobotId;
}
