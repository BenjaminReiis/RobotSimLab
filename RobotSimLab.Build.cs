using UnrealBuildTool;

public class RobotSimLab : ModuleRules
{
    public RobotSimLab(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject",
                "Engine",
                "InputCore",
                "EnhancedInput",
                "PhysicsCore"
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
            }
        );
    }
}
