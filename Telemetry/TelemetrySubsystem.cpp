#include "Telemetry/TelemetrySubsystem.h"

void UTelemetrySubsystem::UpdateTelemetry(const FRobotTelemetry& NewTelemetry)
{
    CurrentTelemetry = NewTelemetry;
}

FRobotTelemetry UTelemetrySubsystem::GetTelemetry() const
{
    return CurrentTelemetry;
}

bool UTelemetrySubsystem::HasWarning() const
{
    return
        CurrentTelemetry.Temperature >= 70.0f ||
        CurrentTelemetry.Current >= 15.0f;
}

bool UTelemetrySubsystem::HasCriticalFault() const
{
    return
        CurrentTelemetry.Temperature >= 90.0f ||
        CurrentTelemetry.Current >= 20.0f;
}
