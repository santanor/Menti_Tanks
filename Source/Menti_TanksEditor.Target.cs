// Copyright Mentisoft

using UnrealBuildTool;
using System.Collections.Generic;

public class Menti_TanksEditorTarget : TargetRules
{
	public Menti_TanksEditorTarget(TargetInfo Target)
	{
		Type = TargetType.Editor;
	}

	//
	// TargetRules interface.
	//

	public override void SetupBinaries(
		TargetInfo Target,
		ref List<UEBuildBinaryConfiguration> OutBuildBinaryConfigurations,
		ref List<string> OutExtraModuleNames
		)
	{
		OutExtraModuleNames.AddRange( new string[] { "Menti_Tanks" } );
	}
}
