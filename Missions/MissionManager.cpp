#include "Missions/MissionManager.h"

void UMissionManager::SetMission(UMissionBase* Mission)
{
    CurrentMission = Mission;
}

void UMissionManager::StartCurrentMission()
{
    if (CurrentMission)
    {
        CurrentMission->StartMission();
    }
}

void UMissionManager::CompleteCurrentMission()
{
    if (CurrentMission)
    {
        CurrentMission->CompleteMission();
    }
}

void UMissionManager::FailCurrentMission()
{
    if (CurrentMission)
    {
        CurrentMission->FailMission();
    }
}

void UMissionManager::ResetCurrentMission()
{
    if (CurrentMission)
    {
        CurrentMission->ResetMission();
    }
}
