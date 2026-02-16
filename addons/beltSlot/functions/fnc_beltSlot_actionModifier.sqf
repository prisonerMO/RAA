#include "script_component.hpp"
/* File: fnc_beltSlot_actionModifier.sqf
 * Author(s): riksuFIN
 * Description: Modifies name and icon of "move from belt to inventory" action.
 *
 * Called from: 
 * Local to:	
 * Parameter(s):
 0:	
 1:	
 2:	
 3:	
 4:	
 *
 Returns: 
 *
 * Example:	[] call RAA_misc_fnc_beltSlot_actionModifier
*/

params ["_actionData", "_slot", "_target", "_string", ["_chageIcon", true]];


// Modify the action - index 1 is the display name, 2 is the icon...

//_actionData set [1, format ['Move %1 to inventory', ((_target getVariable [QGVAR(data), []]) param [_slot, []]) param [2, 'Error: NO ITEM']]];
_actionData set [1, format [_string, ((_target getVariable [QGVAR(data), []]) param [_slot, []]) param [2, 'Error: NO ITEM']]];

if (_chageIcon) then {
    _actionData set [2, ((_target getVariable [QGVAR(data), []]) param [_slot, []]) param [1, '']];
};

