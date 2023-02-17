#pragma once
#include "ModeInterface.h"	//Parent

//Entities
#include "Entity_GameUnit.h"
#include "AnimationDefinitions.h"

//Managers
#include "GameplayManager.h"

//UIs


/*
	Main game state that the game will be primarily played in.
*/
class Mode_Game_Scene : public ModeInterface
{
public:


	////////////
	/// Data ///
	////////////


	///////////////////
	/// Definitions ///
	///////////////////

	////////////////////
	/// Constructors ///
	////////////////////

	Mode_Game_Scene(size_t id);
	~Mode_Game_Scene() { Release(); }

	/////////////////
	/// Overrides ///
	/////////////////

	void Enter() override;
	bool Exit() override;
	void Update(GameTimer& gt) override;
	void Render(PassData& data) override;
	void ProcessKey(char key) override;
	void Release() override;

	//////////////////
	/// Operations ///
	//////////////////


	///////////
	/// Get ///
	///////////


	///////////
	/// Set ///
	///////////


private:

	//////////////////
	/// Operations ///
	//////////////////

	void Init();

	////////////
	/// Data ///
	////////////

	//Hold large, scene/background sprites here
	std::vector<EM_Sprite*> m_Backgrounds;

	//Hold reference to gameplay manager for quicker access
	GameplayManager* m_GPManager = nullptr;
	CS_Main_00* m_CS = nullptr;


	////////////
	/// Demo ///
	////////////

	Entity_GameUnit* m_DemoUnit;

};