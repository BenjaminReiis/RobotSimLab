#include "SimulationManager.h"


void USimulationManager::Initialize(
    FSubsystemCollectionBase& Collection
)
{
    Super::Initialize(Collection);

    SimulationState =
        ESimulationState::Stopped;

    SimulationTime = 0.0f;

    Settings.SimulationSpeed = 1.0f;

    Settings.bUsePhysics = true;

    Settings.bEnableSensors = true;

    Settings.bEnableTelemetry = true;
}


void USimulationManager::Deinitialize()
{
    SimulationState =
        ESimulationState::Stopped;

    SimulationTime = 0.0f;

    Super::Deinitialize();
}


void USimulationManager::Tick(
    float DeltaTime
)
{
    if (SimulationState !=
        ESimulationState::Running)
    {
        return;
    }

    const float ScaledDeltaTime =
        DeltaTime *
        FMath::Max(
            Settings.SimulationSpeed,
            0.0f
        );

    SimulationTime +=
        ScaledDeltaTime;
}


void USimulationManager::StartSimulation()
{
    if (SimulationState ==
        ESimulationState::Running)
    {
        return;
    }

    SimulationState =
        ESimulationState::Running;

    OnSimulationStateChanged.Broadcast(
        SimulationState
    );
}


void USimulationManager::PauseSimulation()
{
    if (SimulationState !=
        ESimulationState::Running)
    {
        return;
    }

    SimulationState =
        ESimulationState::Paused;

    OnSimulationStateChanged.Broadcast(
        SimulationState
    );
}


void USimulationManager::StopSimulation()
{
    SimulationState =
        ESimulationState::Stopped;

    OnSimulationStateChanged.Broadcast(
        SimulationState
    );
}


void USimulationManager::ResetSimulation()
{
    SimulationState =
        ESimulationState::Resetting;

    SimulationTime = 0.0f;

    OnSimulationStateChanged.Broadcast(
        SimulationState
    );

    SimulationState =
        ESimulationState::Stopped;

    OnSimulationStateChanged.Broadcast(
        SimulationState
    );
}


ESimulationState
USimulationManager::GetSimulationState() const
{
    return SimulationState;
}


float
USimulationManager::GetSimulationTime() const
{
    return SimulationTime;
}


void
USimulationManager::SetSimulationSpeed(
    float Speed
)
{
    Settings.SimulationSpeed =
        FMath::Clamp(
            Speed,
            0.01f,
            20.0f
        );
}


FSimulationSettings
USimulationManager::GetSettings() const
{
    return Settings;
}
