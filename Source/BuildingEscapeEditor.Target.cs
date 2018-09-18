// Copyright Brandon Santangelo 2018.

using UnrealBuildTool;
using System.Collections.Generic;

public class BuildingEscapeEditorTarget : TargetRules
{
	public BuildingEscapeEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

        //bUseUnityBuild = false;         Not needed?
        //bUsePHCFiles = false;           Not Needed? Causes Errors

        ExtraModuleNames.Add("BuildingEscape");
	}
}
