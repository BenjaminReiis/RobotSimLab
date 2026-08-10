#pragma once

#include "CoreMinimal.h"
#include "MissionTypes.generated.h"

UENUM(BlueprintType)
enum class EMissionState : uint8
{
    Inactive,
    Running,
    Completed,
    Failed
};

UENUM(BlueprintType)
enum class EMissionType : uint8
{
    Navigation,
    Inspection,
    Diagnostic,
    Custom
};
