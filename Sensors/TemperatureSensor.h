#pragma once

#include "CoreMinimal.h"
#include "Sensors/SensorBase.h"
#include "TemperatureSensor.generated.h"

UCLASS(Blueprintable)
class ROBOTSIMLAB_API UTemperatureSensor : public USensorBase
{
    GENERATED_BODY()

public:

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Temperature")
    float TemperatureCelsius = 25.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Temperature")
    float WarningTemperature = 70.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Temperature")
    float CriticalTemperature = 90.0f;

    virtual float ReadValue() const override;

    UFUNCTION(BlueprintCallable, Category = "Temperature")
    bool IsWarning() const;

    UFUNCTION(BlueprintCallable, Category = "Temperature")
    bool IsCritical() const;
};
