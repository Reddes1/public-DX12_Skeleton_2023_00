#include "Entity_GameUnit.h"

#include "GameConstants.h"			//Game info
#include "AnimationDefinitions.h"	//Animator info
#include "GeneralUtils.h"

#include "Game.h"					//Manager Access

void Entity_GameUnit::Update(GameTimer& gt)
{
	//Only update if enabled
	if (GetActiveState())
	{

	}

	//We dont want the animations desyncing, so update this regardless
	m_MainAnimator.Update(gt.DeltaTime());
}

void Entity_GameUnit::Render(DirectX::SpriteBatch& batch, DirectX::DescriptorHeap* heap)
{
	//Only render if enabled (this is set to default because this entity is likely created without a texture being set
	if (GetRenderState())
	{
		m_MainSprite.Draw(batch, heap);
	}

}

void Entity_GameUnit::Init()
{
	//Bind base sprite with animator
	m_MainAnimator.SetSpritePointer(&m_MainSprite);

	//Disable flags & ensure certain updates dont occur
	SetActiveState(false);
	SetRenderState(false);

	m_MainAnimator.SetPlay(false);

}

void Entity_GameUnit::Release()
{

}


