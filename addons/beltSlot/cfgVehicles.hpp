class CfgVehicles {
	class Man;
	class CAManBase: Man {
		class ACE_SelfActions {
			class ACE_Equipment {
				class RAA_beltSlot {
						displayName = "Belt Slots";
						condition = QGVAR(enabled);
						statement = "";
					//	showDisabled = 0;
					//	exceptions[] = {"isNotInside", "isNotSwimming", "isNotSitting"};
						exceptions[] = {};
						icon = QPATHTOF(pics\icon_belt.paa);
					
					class RAA_beltSlot_moveToBelt {
						displayName = "Move item to belt";
						condition = QUOTE(call FUNC(beltSlot_canMoveToBelt));
					//    exceptions[] = {};
						statement = "";
					//	icon = QPATHTOF(pics\icon_cutting_tree);
						insertChildren = QUOTE(call FUNC(beltSlot_getChildrens));
						
					};
					
					class RAA_belSlot_item1 {
						displayName = "%1";
						condition = QUOTE(0 call FUNC(beltSlot_canMoveFrombelt));
					//    exceptions[] = {};
						statement = QUOTE(0 call FUNC(beltSlot_doMoveFrombelt));
						icon = "";
						modifierFunction = QUOTE([ARR_5(_this select 3,0,_player,""Move %1 to inventory"",true)] call FUNC(beltSlot_actionModifier));
						//modifierFunction = QUOTE([ARR_2(_this,0)] call FUNC(beltSlot_actionModifier));
					
						class RAA_beltSlot_moveFromBelt1 {
							displayName = "Move to inventory";
							condition = QUOTE(true);
						//    exceptions[] = {};
							statement = QUOTE(0 call FUNC(beltSlot_doMoveFrombelt));
							icon = "";
						};

						class RAA_beltSlot_dropToGround1 {
							displayName = "Drop to ground";
							condition = QUOTE(true);
						//    exceptions[] = {};
							statement = QUOTE([ARR_3(0,ACE_player,9)] call FUNC(beltSlot_doMoveFrombelt));
							icon = "";
						};
					};
					
					class RAA_belSlot_item2 {
						displayName = "%1";
						condition = QUOTE(1 call FUNC(beltSlot_canMoveFrombelt));
					//    exceptions[] = {};
						statement = QUOTE(1 call FUNC(beltSlot_doMoveFrombelt));
						icon = "";
						modifierFunction = QUOTE([ARR_5(_this select 3,1,_player,""Move %1 to inventory"",true)] call FUNC(beltSlot_actionModifier));
					

						class RAA_beltSlot_moveFromBelt2 {
							displayName = "Move to inventory";
							condition = QUOTE(true);
							exceptions[] = {};
							statement = QUOTE(1 call FUNC(beltSlot_doMoveFrombelt));
							icon = "";
						};

						class RAA_beltSlot_dropToGround2 {
							displayName = "Drop to ground";
							condition = QUOTE(true);
						//    exceptions[] = {};
							statement = QUOTE([ARR_3(1,ACE_player,9)] call FUNC(beltSlot_doMoveFrombelt));
							icon = "";
						};
					};
				};
				
			};
			
			class ace_field_rations {
				class RAA_misc_drinkFromBeltItem {
					displayName = "Drink from item on belt";
					condition = "true";
				//	exceptions[] = {};
					exceptions[] = {"notOnMap", "isNotInside"};
					statement = "";
					showDisabled =0;
					icon = QPATHTOF(pics\icon_belt.paa);
					insertChildren = QUOTE(call FUNC(beltSlot_getDrinkableChildrens));
				};
				
			};
			
			class ACE_Explosives {
				class RAA_beltSlot_placeExplosive {
					displayName = "Place (From Belt)";
					condition = "true";
					statement = "";
					exceptions[] = {};
					icon = QPATHTOF(pics\icon_belt.paa);
					insertChildren = QUOTE(ACE_player call FUNC(placeExplosive_getChildren));
				};
			};
		};

		class ACE_Actions {
			class RAA_beltSlot_slot1 {
					displayName = "Grab N/A";
					condition = QUOTE(GVAR(enabled) && {_target getVariable [ARR_2(QQGVAR(data),[])] param [ARR_2(0,[])] isNotEqualTo []});
					statement = QUOTE([ARR_3(0,_target,_player)] call FUNC(takeFromBelt));
					//icon = QPATHTOF();
					modifierFunction = QUOTE([ARR_5(_this select 3,0,_target,""Grab %1"",true)] call FUNC(beltSlot_actionModifier));
					position = QUOTE([ARR_3(-0.2,0,-0.05)]);	// TODO find correct placement
					distance = 2;
			};
			class RAA_beltSlot_slot2 {
					displayName = "Grab N/A";
					condition = QUOTE(GVAR(enabled) && {_target getVariable [ARR_2(QQGVAR(data),[])] param [ARR_2(1,[])] isNotEqualTo []});
					statement = QUOTE([ARR_3(1,_target,_player)] call FUNC(takeFromBelt));
					//icon = QPATHTOF();
					modifierFunction = QUOTE([ARR_5(_this select 3,1,_target,""Grab %1"",true)] call FUNC(beltSlot_actionModifier));
					position = QUOTE([ARR_3(0.2,0,-0.05)]);	// TODO find correct placement
					distance = 2;
			};
		};



	};

};
