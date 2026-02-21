#include "script_component.hpp"
/* File: fnc_takeFromBelt.sqf
 * Author(s): riksuFIN
 * Description: Steals item from another player's belt.
 *
 * Local to:	Client who's taking item
 * Parameter(s):
 0:	Slot number
 1: Player who's taking this object
 *
 Returns: Nothing
 *
 * Example:	
 *	[player] call RAA_beltSlot_fnc_takeFromBelt
*/
params [["_slot", -1], ["_target", objNull], ["_player", ACE_player]];

if (isNull _player || isNull _target) exitWith {};

private _beltDataFull = _target getVariable [QGVAR(data), []];
private _beltData = _beltDataFull param [_slot, []];

if (_beltData isEqualTo []) exitWith {
    [COMPNAME, GVAR(debug), "ERROR", format ["Failed to grab slot %1 item from %2's belt: No Data", _slot, _target]] call EFUNC(common,debugNew);
};

private _classname = _beltData param [0, ""];

[COMPNAME, GVAR(debug), "INFO", format ["Taking object %1 from %2 by %3 from slot %4", _classname, _target, _player, _slot]] call EFUNC(common,debugNew);

// Remove this item from its owner's belt. If owner is alive this has to be done on their machine
if (alive _target) then {

    [_slot, _target] remoteExec [QFUNC(beltSlot_deleteFromBelt), _target];

    if (isPlayer _target) then {
        ["Someone took something from your belt.", false, 7, 1] remoteExec ["ace_common_fnc_displayText", _target];
    //  ["Someone took something from your belt"] remoteExec ["systemChat", _target];   // TODO: switch systemChat to ACE hint
        [4, 1, 5] remoteExec ["addCamShake", _target];
    };
} else {

    // This target is a dead corpse, we can directly remove this item.
    deleteVehicle (_beltData param [3, objNull]);
    _beltDataFull set [_slot, nil];
    _target setVariable [QGVAR(data), _beltDataFull, true];
};


// Add visual feedback
[_player, "PutDown"] call ACE_common_fnc_doGesture;


// Attempt to put it directly to player's own belt
private _success = ["", _player, _className, true] call RAA_beltSlot_fnc_beltSlot_doMoveToBelt;

if (_success) exitWith {};

// Failed to put on belt, spawn it in inventory or, if even that fails, spawn it on ground
private _return = [_player, _className, ""] call ace_common_fnc_addToInventory;
