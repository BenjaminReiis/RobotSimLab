#include "Missions/MissionBase.h"

void UMissionBase::StartMission()
{
    State = EMissionState::Running;
}

void UMissionBase::CompleteMission()
{
    State = EMissionState::Completed;
}

void UMissionBase::FailMission()
{
    State = EMissionState::Failed;
}

void UMissionBase::ResetMission()
{
    State = EMissionState::Inactive;
}
