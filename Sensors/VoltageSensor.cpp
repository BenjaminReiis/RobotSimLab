#include "Sensors/VoltageSensor.h"

float UVoltageSensor::ReadValue() const
{
    return Voltage;
}

bool UVoltageSensor::IsOutOfRange() const
{
    return Voltage < MinimumVoltage || Voltage > MaximumVoltage;
}
