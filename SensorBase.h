#pragma once

#include "CoreMinimal.h"
#include "SensorBase.generated.h"

UCLASS(Abstract, Blueprintable)
class ROBOTSIMLAB_API USensorBase : public UObject
{
    GENERATED_BODY()

public:

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sensor")
    FString SensorId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sensor")
    FString SensorName;

    UPROPERTY(BlueprintReadOnly, Category = "Sensor")
    bool bEnabled = true;

    virtual float ReadValue() const;

    virtual void Reset();
};
