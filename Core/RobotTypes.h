#pragma once

#include "CoreMinimal.h"
#include "RobotTypes.generated.h"

UENUM(BlueprintType)
enum class ERobotType : uint8
{
    Mobile      UMETA(DisplayName = "Mobile Robot"),
    Industrial  UMETA(DisplayName = "Industrial Arm"),
    Drone       UMETA(DisplayName = "Drone"),
    Humanoid    UMETA(DisplayName = "Humanoid")
};

UENUM(BlueprintType)
enum class ERobotState : uint8
{
    Idle        UMETA(DisplayName = "Idle"),
    Running     UMETA(DisplayName = "Running"),
    Paused      UMETA(DisplayName = "Paused"),
    Emergency   UMETA(DisplayName = "Emergency"),
    Completed   UMETA(DisplayName = "Completed")
};
