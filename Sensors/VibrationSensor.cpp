#include "Sensors/VibrationSensor.h"

float UVibrationSensor::ReadValue() const
{
    return VibrationLevel;
}

bool UVibrationSensor::IsWarning() const
{
    return VibrationLevel >= WarningLevel;
}

bool UVibrationSensor::IsCritical() const
{
    return VibrationLevel >= CriticalLevel;
}
