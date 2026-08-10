#include "Sensors/CurrentSensor.h"

float UCurrentSensor::ReadValue() const
{
    return CurrentAmps;
}

bool UCurrentSensor::IsWarning() const
{
    return CurrentAmps >= WarningCurrentAmps;
}

bool UCurrentSensor::IsCritical() const
{
    return CurrentAmps >= CriticalCurrentAmps;
}
