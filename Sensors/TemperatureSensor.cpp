#include "Sensors/TemperatureSensor.h"

float UTemperatureSensor::ReadValue() const
{
    return TemperatureCelsius;
}

bool UTemperatureSensor::IsWarning() const
{
    return TemperatureCelsius >= WarningTemperature;
}

bool UTemperatureSensor::IsCritical() const
{
    return TemperatureCelsius >= CriticalTemperature;
}
