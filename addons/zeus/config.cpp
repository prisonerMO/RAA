#include "script_component.hpp"

class CfgPatches
{
	class ADDON
	{
		author = "riksuFIN";
		name = COMPONENT_NAME;
		requiredVersion = REQUIRED_VERSION;
		VERSION_CONFIG;
		
		units[] = {	// Classes from cfgVehicles
		};
		weapons[] = {	// Classes from cfgWeapons
		};

		requiredAddons[] = {
			"A3_Data_F_Tank_Loadorder",
			"cba_xeh",
			"zen_context_menu",
			"zen_context_actions",	// For overwriting remote-control action
			"RAA_common",
			"RAA_misc",
			"RAA_animation",
			"acex_field_rations"
		};
	};
};


#include "CfgEventHandlers.hpp"
#include "cfgContext.hpp"
#include "curatorDisplay.hpp"
