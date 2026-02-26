
class RscPicture;
class RscDisplayCurator {
	class Controls {
		class RAA_sideRelations: RscPicture
		{
			idc = 1101;
			x = QUOTE(0.2 * safeZoneW + safezoneX);
			y = QUOTE(0.1 * safezoneH + safezoneY);
			w = QUOTE(0.06 * safezoneW);
			h = QUOTE(0.11 * safezoneH);

			fade = 0;
		//	text = QPATHTOF(pics\sideRelations\FFF.paa);
			text = "";
		//	text = QFUNC(getFactionRelations);
			onLoad = QUOTE(_this call DFUNC(getFactionRelations));
		//	onLoad = "systemChat str _this";
			
		//	params ["_displayOrControl", ["_config", configNull]];
			
		};
	};
};
