#include "script_component.hpp"

class CfgPatches 
{
	class ADDON
	{
		name = COMPONENT_NAME;
		author = "riksuFIN";
		requiredVersion = REQUIRED_VERSION;
		VERSION_CONFIG;
		units[] = {	// Classes from cfgVehicles
			"RAA_unfinished_ied_item",
			"RAA_facepaint_item",
			"RAA_sound_axe_01",
			"RAA_sound_radio_rock",
			"RAA_sound_radio_epic",
			"RAA_sound_radio_chill",
			"RAA_sound_radio_vdvSong",
			"RAA_sound_chainsaw_01",
			"RAA_Flag_Motti"
		};
		weapons[] = {	// Classes from cfgWeapons
			"RAA_facepaint",
			"RAA_can_broken",
			"RAA_canteen_broken",
			"RAA_waterBottle_broken",
			"RAA_axe",
			"RAA_chainsaw",
			"RAA_unfinished_ied"
		};

		requiredAddons[] = {
			"A3_Data_F_Tank_Loadorder",
			"RAA_common",
			"cba_xeh",
			"ace_interact_menu",
			"zen_dialog",
			"ace_overheating"
		//	"CUP_Editor_Plants_Config",	// For fallen tree used for delimbed trees
		};
		
		
	};
};

#include "CfgEventHandlers.hpp"

#include "cfgMoves.hpp"
#include "cfgSounds.hpp"
#include "cfgVehicles.hpp"
#include "cfgWeapons.hpp"
