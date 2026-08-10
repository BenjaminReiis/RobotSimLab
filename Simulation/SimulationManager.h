#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"

#include "SimulationTypes.h"

#include "SimulationManager.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
    FOnSimulationStateChanged,
    ESimulationState,
    NewState
);


UCLASS()
class ROBOTSIMLAB_API USimulationManager : public UWorldSubsystem
{
    GENERATED_BODY()

public:

    virtual void Initialize(
        FSubsystemCollectionBase& Collection
    ) override;

    virtual void Deinitialize() override;

    virtual void Tick(
        float DeltaTime
    ) override;

    virtual bool IsTickable() const override
    {
        return true;
    }


    UFUNCTION(BlueprintCallable)
    void StartSimulation();

    UFUNCTION(BlueprintCallable)
    void PauseSimulation();

    UFUNCTION(BlueprintCallable)
    void StopSimulation();

    UFUNCTION(BlueprintCallable)
    void ResetSimulation();


    UFUNCTION(BlueprintCallable)
    ESimulationState GetSimulationState() const;


    UFUNCTION(BlueprintCallable)
    float GetSimulationTime() const;


    UFUNCTION(BlueprintCallable)
    void SetSimulationSpeed(float Speed);


    UFUNCTION(BlueprintCallable)
    FSimulationSettings GetSettings() const;


    UPROPERTY(BlueprintAssignable)
    FOnSimulationStateChanged OnSimulationStateChanged;


protected:

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Simulation")
    FSimulationSettings Settings;


private:

    ESimulationState SimulationState;

    float SimulationTime;
};
