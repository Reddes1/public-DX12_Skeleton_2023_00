#pragma once

#include "EM_EntityInterface.h"		//Parent

//EM Components
#include "EM_Sprite.h"				
#include "EM_Animator.h"			

#include "GameTypes.h"				//Unit Data

/*
	Main gameplay unit for this game.
*/

class Entity_GameUnit : public EM_EntityInterface2D
{
public:

	////////////
	/// Data ///
	////////////


	////////////////////
	/// Constructors ///
	////////////////////

	Entity_GameUnit() { Init(); }
	~Entity_GameUnit() { Release(); }


	/////////////////
	/// Overrides ///
	/////////////////

	void Update(GameTimer& gt) override;
	void Render(DirectX::SpriteBatch& batch, DirectX::DescriptorHeap* heap) override;

	//Optional Overrides (Uncomment as needed)
	void ResetEntityToDefaults() override { }


	//////////////////
	/// Operations ///
	//////////////////


	///////////
	/// Get ///
	///////////

	EM_Sprite& GetBaseSprite()			{ return m_MainSprite; }
	EM_Animator& GetBaseAnimator()		{ return m_MainAnimator; }
	UnitData& GetUnitData()				{ return m_Data; }


	///////////
	/// Set ///
	///////////

private:

	//////////////////
	/// Operations ///
	//////////////////

	void Init();
	void Release();


	////////////
	/// Data ///
	////////////

	//Sprite/Animator Combo
	EM_Sprite m_MainSprite;
	EM_Animator m_MainAnimator;

	//Local copy of unit data
	UnitData m_Data;

};