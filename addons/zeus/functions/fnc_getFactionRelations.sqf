#include "script_component.hpp"
/* File: fnc_onZeusInterfaceOpen.sqf
 * Author(s): riksuFIN
 * Description: Gets path for correct icon for showing relations between factions
 *	
 * Called from: GUI curatorDisplay
 * Local to: Client
 * Parameter(s):
 NONE
 *
 Returns:	NOTHING
 *
 * Example:	call RAA_zeus_fnc_fnc_getFactionRelations
*/
if !(GVAR(factionRelationsIndicator_enable)) exitWith {
};


params ["_ctrl", ""];

if (_ctrl isEqualTo "") then {
	_ctrl = (findDisplay 312) displayCtrl 1101;
};

private _img = "";

if ([west, east] call BIS_fnc_sideIsFriendly) then {
	_img = "F";
} else {
	_img = "H";
};

if ([east, resistance] call BIS_fnc_sideIsFriendly) then {
	_img = _img + "F";
} else {
	_img = _img + "H";
};

if ([resistance, west] call BIS_fnc_sideIsFriendly) then {
	_img = _img + "F";
} else {
	_img = _img + "H";
};

// Assemple full path
//_img = "\r\misc\addons\RAA_zeus\pics\sideRelations\" + _img + ".paa";
_img = QPATHTOF(pics\sideRelations\) + _img + ".paa";
//_img = ["\r\misc\addons\RAA_zeus\pics\sideRelations\", _img, ".paa"] joinString "";	

if (GVAR(debug)) then {systemChat format ["[RAA_zeus] SideRelations: %1. Received ctrl %2", _img, _this param [0, ""]];};

_ctrl ctrlSetText _img;

[	{
		_this ctrlSetFade 1;
		_this ctrlCommit 2;
	}, 
	_ctrl, 
	8
] call CBA_fnc_waitAndExecute;

_img



