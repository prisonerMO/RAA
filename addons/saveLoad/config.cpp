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
			QGVAR(module_base),
			QGVAR(module_blacklist),
			QGVAR(module_load_main),
			QGVAR(module_save_main),
			QGVAR(module_save_zeus),
			QGVAR(module_save_trigger),
			QGVAR(module_save_additionalSearchLocation),
			QGVAR(module_load_vehSpawnPos),
			QGVAR(module_load_defineCrate)
		};
		weapons[] = {	// Classes from cfgWeapons
			
			
			
		};

		requiredAddons[] = {
			"RAA_common"
		};

	};
};

#include "CfgFactionClasses.hpp"
#include "CfgEventHandlers.hpp"
#include "cfgVehicles.hpp"
#include "cfgWeapons.hpp"
