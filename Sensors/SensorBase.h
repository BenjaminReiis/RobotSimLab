#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
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

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sensor")
    bool bEnabled = true;

    UFUNCTION(BlueprintCallable, Category = "Sensor")
    virtual float ReadValue() const;

    UFUNCTION(BlueprintCallable, Category = "Sensor")
    virtual void Reset();
};
