#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "RobotCommandComponent.generated.h"


USTRUCT(BlueprintType)
struct FRobotCommand
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float LinearVelocity = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float AngularVelocity = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bEmergencyStop = false;
};


UCLASS(ClassGroup=(Robot), meta=(BlueprintSpawnableComponent))
class ROBOTSIMLAB_API URobotCommandComponent
    : public UActorComponent
{
    GENERATED_BODY()

public:

    URobotCommandComponent();

    UFUNCTION(BlueprintCallable)
    void SetCommand(
        float LinearVelocity,
        float AngularVelocity
    );

    UFUNCTION(BlueprintCallable)
    void EmergencyStop();

    UFUNCTION(BlueprintCallable)
    void ClearCommand();

    UFUNCTION(BlueprintCallable)
    FRobotCommand GetCommand() const;

private:

    UPROPERTY()
    FRobotCommand CurrentCommand;
};
