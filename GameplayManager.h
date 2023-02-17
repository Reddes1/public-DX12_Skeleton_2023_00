#pragma once

//Sub-Managers
#include "SM_TilemapManager.h"
#include "SM_UnitDataManager.h"
#include "SM_GameStateManager.h"
#include "SM_CombatManager.h"

//Other
#include "SceneCamera2D.h"
#include "CS_Main_00.h"				//Main Game Control Scheme

/*
	Centralises all gameplay orientated behaviours and modules together.
	If possible, any behaviour that can be wrapped up into tidy classes should be added here,
	and getters added to access them. This will effectively act as a hub type class, but
	specifically for gameplay related tasks and actions, without cluttering this hub.
*/
class GameplayManager
{
public:

	////////////
	/// Data ///
	////////////


	////////////////////
	/// Constructors ///
	////////////////////

	GameplayManager() {}
	~GameplayManager() {}

	//////////////////
	/// Operations ///
	//////////////////

	//
	// Composite Functions
	//

	///////////
	/// Get ///
	///////////

	SM_TilemapManager& GetTileManager()			 { return m_TileManager; }
	SM_UnitDataManager& GetUnitDataManager()	 { return m_UnitDataManager; }
	SM_GameStateManager& GetStateManager()		 { return m_StateManager; }
	SM_CombatManager& GetCombatManager()		 { return m_CombatManager; }

	SceneCamera_2D& GetSceneCamera()			 { return m_SceneCamera; }
	CS_Interface& GetControlScheme()			 { return m_ControlScheme; }

	///////////
	/// Set ///
	///////////


private:

	//////////////////
	/// Operations ///
	//////////////////

	////////////
	/// Data ///
	////////////

	//Responsible for managing games tilemap
	SM_TilemapManager m_TileManager;
	
	//Responsible for loading and storing unit data
	SM_UnitDataManager m_UnitDataManager;

	//Responsible for tracking and managing program/game state for use elsewhere
	SM_GameStateManager m_StateManager;

	//Responsible for manage damage calculations, and setting unit states post combat
	SM_CombatManager m_CombatManager;

	//Manages the movement of the game camera
	SceneCamera_2D m_SceneCamera;

	//Main control scheme
	CS_Main_00 m_ControlScheme;
};


