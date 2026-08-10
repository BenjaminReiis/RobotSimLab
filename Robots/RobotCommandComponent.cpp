#include "RobotCommandComponent.h"


URobotCommandComponent::URobotCommandComponent()
{
    PrimaryComponentTick.bCanEverTick = false;

    CurrentCommand.LinearVelocity = 0.0f;

    CurrentCommand.AngularVelocity = 0.0f;

    CurrentCommand.bEmergencyStop = false;
}


void URobotCommandComponent::SetCommand(
    float LinearVelocity,
    float AngularVelocity
)
{
    if (CurrentCommand.bEmergencyStop)
    {
        return;
    }

    CurrentCommand.LinearVelocity =
        LinearVelocity;

    CurrentCommand.AngularVelocity =
        AngularVelocity;
}


void URobotCommandComponent::EmergencyStop()
{
    CurrentCommand.LinearVelocity = 0.0f;

    CurrentCommand.AngularVelocity = 0.0f;

    CurrentCommand.bEmergencyStop = true;
}


void URobotCommandComponent::ClearCommand()
{
    CurrentCommand.LinearVelocity = 0.0f;

    CurrentCommand.AngularVelocity = 0.0f;

    CurrentCommand.bEmergencyStop = false;
}


FRobotCommand
URobotCommandComponent::GetCommand() const
{
    return CurrentCommand;
}
