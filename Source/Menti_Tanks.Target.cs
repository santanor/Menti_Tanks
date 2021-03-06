// Copyright Mentisoft

using UnrealBuildTool;
using System.Collections.Generic;

public class Menti_TanksTarget : TargetRules
{
	public Menti_TanksTarget(TargetInfo Target)
	{
		Type = TargetType.Game;
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
