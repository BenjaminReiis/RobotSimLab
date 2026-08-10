#pragma once

#include "CoreMinimal.h"
#include "Sensors/SensorBase.h"
#include "CurrentSensor.generated.h"

UCLASS(Blueprintable)
class ROBOTSIMLAB_API UCurrentSensor : public USensorBase
{
    GENERATED_BODY()

public:

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
    float CurrentAmps = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
    float WarningCurrentAmps = 15.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Current")
    float CriticalCurrentAmps = 20.0f;

    virtual float ReadValue() const override;

    UFUNCTION(BlueprintCallable, Category = "Current")
    bool IsWarning() const;

    UFUNCTION(BlueprintCallable, Category = "Current")
    bool IsCritical() const;
};
