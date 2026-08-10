#pragma once

#include "CoreMinimal.h"
#include "Sensors/SensorBase.h"
#include "VoltageSensor.generated.h"

UCLASS(Blueprintable)
class ROBOTSIMLAB_API UVoltageSensor : public USensorBase
{
    GENERATED_BODY()

public:

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Voltage")
    float Voltage = 24.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Voltage")
    float MinimumVoltage = 18.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Voltage")
    float MaximumVoltage = 30.0f;

    virtual float ReadValue() const override;

    UFUNCTION(BlueprintCallable, Category = "Voltage")
    bool IsOutOfRange() const;
};
