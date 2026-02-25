#include "..\script_component.hpp"
/*
 * Author: Prisoner
 * Return a suitable position for the action point for the target's backpack.
 *
 * Arguments:
 0:	Unit
 1:	Selection name
 2: Distance
 *
 * Return Value:
 * Position of _target's beltslot item in model space <ARRAY>
 *
 * Example:
 * [_unit, "leftupleg", -0.1] call RAA_beltSlot_fnc_beltSlot_getGrabPosition
 *
 * Public: No
 */
params ["_target","_selectionPos","_distance"];
private _current = _target selectionPosition [_selectionPos,"Memory"];
private _rightDir = (_target selectionPosition ["rightupleg","Memory"]) vectorDiff (_target selectionPosition ["leftupleg","Memory"]);
_rightDir = vectorNormalized _rightDir;
_current  vectorAdd (_rightDir vectorMultiply _distance);
