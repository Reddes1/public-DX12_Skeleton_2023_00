#include "Mode_MainGame.h"		//Owner

#include "Game.h"			//Manager Access

Mode_Game_Scene::Mode_Game_Scene(size_t id)
	:ModeInterface(id)
{
	Init();
}

void Mode_Game_Scene::Init()
{
	//Get Game
	Game* game = Game::GetGame();
	//Grab gameplay manager pointer
	m_GPManager = &game->GetGameplayManager();

	//Setup background
	m_Backgrounds.push_back(new EM_Sprite());
	m_Backgrounds[0]->SetTexture(DEFAULT_TEST_BG_TEXTURE_NAME, true);
	m_Backgrounds[0]->SetLayerDepth(DRAW_DEPTH_BACKGROUND_0);

	m_DemoUnit = new Entity_GameUnit();

	m_DemoUnit->GetBaseSprite().SetTexture("Anim_Test_SS_00");
	m_DemoUnit->GetBaseAnimator().SetAnimation((int)Test_Anim_00_Animations::ATTACK_00, true, true, false);
	m_DemoUnit->GetBaseSprite().SetOriginToCenter();
	m_DemoUnit->GetBaseSprite().SetPosition(game->GetWindowWidthF() * 0.5f, game->GetWindowHeightF() * 0.5f);
	m_DemoUnit->GetBaseSprite().SetScale(3.f, 3.f);
	m_DemoUnit->GetBaseSprite().SetLayerDepth(DRAW_DEPTH_ENTITY_0);
	m_DemoUnit->SetRenderState(true);
}

void Mode_Game_Scene::Release()
{
	//Release backgrounds
	for (auto& a : m_Backgrounds)
	{
		delete a;
		a = nullptr;
	}

	delete m_DemoUnit;
	m_DemoUnit = nullptr;
}

void Mode_Game_Scene::Enter()
{

}

bool Mode_Game_Scene::Exit()
{
	return true;
}

void Mode_Game_Scene::Update(GameTimer& gt)
{
	m_DemoUnit->Update(gt);
}

void Mode_Game_Scene::Render(PassData& data)
{
	//Get Game
	Game* game = Game::GetGame();

	/////////////////////
	/// Render Pass 0 ///
	///  Backgrounds  ///
	/////////////////////

	//Start pass
	data.m_Spritebatches[SpritebatchDefinitions::MAIN_SB]->Begin(
		game->GetCommandList().Get(),
		DirectX::SpriteSortMode_FrontToBack
	);

	//Render backgrounds
	for (auto& a : m_Backgrounds)
		a->Draw(*data.m_Spritebatches[SpritebatchDefinitions::MAIN_SB], data.m_Heap);

	//End pass
	data.m_Spritebatches[SpritebatchDefinitions::MAIN_SB]->End();

	/////////////////////
	/// Render Pass 1 ///
	///	    Scene     ///
	/////////////////////

	//Start pass
	data.m_Spritebatches[SpritebatchDefinitions::MAIN_SB]->Begin(
		game->GetCommandList().Get(),
		DirectX::SpriteSortMode_FrontToBack
	);

	m_DemoUnit->Render(*data.m_Spritebatches[SpritebatchDefinitions::MAIN_SB], data.m_Heap);

	//End pass
	data.m_Spritebatches[SpritebatchDefinitions::MAIN_SB]->End();

	/////////////////////
	/// Render Pass 2 ///
	///	     UIs      ///
	/////////////////////

	//Start pass
	data.m_Spritebatches[SpritebatchDefinitions::MAIN_SB]->Begin(
		game->GetCommandList().Get(),
		DirectX::SpriteSortMode_FrontToBack
	);



	//End pass
	data.m_Spritebatches[SpritebatchDefinitions::MAIN_SB]->End();

}

void Mode_Game_Scene::ProcessKey(char key)
{
	//Find out if the key is a registered action key, and get the index of that key and pass it where required
	unsigned option = m_GPManager->GetControlScheme().GetIndexOfMatchedKey(std::toupper(key));

	//Quick fix, converting OOR unsigned to char changes it to 0, causing false positives
	if (option == 0xFFFFFFFF)
		return;

}

