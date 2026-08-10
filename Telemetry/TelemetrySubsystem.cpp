#include "TelemetrySubsystem.h"

#include "../Robots/RobotBase.h"

void UTelemetrySubsystem::RegisterRobot(
    ARobotBase* Robot
)
{
    if (!Robot)
    {
        return;
    }

    if (!Robots.Contains(Robot))
    {
        Robots.Add(Robot);
    }
}

void UTelemetrySubsystem::UnregisterRobot(
    ARobotBase* Robot
)
{
    Robots.Remove(Robot);
}

FRobotTelemetry UTelemetrySubsystem::GetRobotTelemetry(
    ARobotBase* Robot
) const
{
    if (!Robot)
    {
        return FRobotTelemetry();
    }

    return Robot->GetTelemetry();
}

void UTelemetrySubsystem::Tick(
    float DeltaTime
)
{
    for (int32 Index = Robots.Num() - 1;
         Index >= 0;
         --Index)
    {
        ARobotBase* Robot = Robots[Index];

        if (!IsValid(Robot))
        {
            Robots.RemoveAt(Index);
            continue;
        }

        OnTelemetryUpdated.Broadcast(
            Robot->GetTelemetry()
        );
    }
}
