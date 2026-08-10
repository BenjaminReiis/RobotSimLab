#pragma once

#include "CoreMinimal.h"
#include "Sensors/SensorBase.h"
#include "VibrationSensor.generated.h"

UCLASS(Blueprintable)
class ROBOTSIMLAB_API UVibrationSensor : public USensorBase
{
    GENERATED_BODY()

public:

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vibration")
    float VibrationLevel = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vibration")
    float WarningLevel = 5.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vibration")
    float CriticalLevel = 10.0f;

    virtual float ReadValue() const override;

    UFUNCTION(BlueprintCallable, Category = "Vibration")
    bool IsWarning() const;

    UFUNCTION(BlueprintCallable, Category = "Vibration")
    bool IsCritical() const;
};
