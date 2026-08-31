#include "Input.h"
#include "Game.h"
Input::Input()
{

}
Input::Input(Game* game, char(&keysArg)[256], char(&preKeysArg)[256])
{
	m_game = game;
	m_keys = keysArg;
	m_preKeys = preKeysArg;
}
void Input::Update()
{
	if (m_game != nullptr)
	{
		if (m_game->GetUi()->GetCurrentMenu() != nullptr)
		{
			if (m_keys[DIK_W] && !m_preKeys[DIK_W])
			{
				m_game->GetUi()->GetCurrentMenu()->ToUpNeighbor();
			}
			if (m_keys[DIK_A] && !m_preKeys[DIK_A])
			{
				m_game->GetUi()->GetCurrentMenu()->ToLeftNeighbor();
			}
			if (m_keys[DIK_S] && !m_preKeys[DIK_S])
			{
				m_game->GetUi()->GetCurrentMenu()->ToDownNeighbor();
			}
			if (m_keys[DIK_D] && !m_preKeys[DIK_D])
			{
				m_game->GetUi()->GetCurrentMenu()->ToRightNeighbor();
			}
			if ((m_keys[DIK_RETURN] && !m_preKeys[DIK_RETURN])|| Novice::IsTriggerMouse(0))
			{
				m_game->GetUi()->GetCurrentMenu()->ClickReceived();
			}
		}
		if (m_game->GetCurrentLocation()!=nullptr&&m_game->GetUi()->GetCurrentMenu()==nullptr)
		{
			if (m_keys[DIK_W])
			{
				m_game->GetPlayer()->MoveInDirection(Directions::Up);
			}
			if (m_keys[DIK_A])
			{
				m_game->GetPlayer()->MoveInDirection(Directions::Left);
			}
			if (m_keys[DIK_S])
			{
				m_game->GetPlayer()->MoveInDirection(Directions::Down);
			}
			if (m_keys[DIK_D])
			{
				m_game->GetPlayer()->MoveInDirection(Directions::Right);
			}
			if (m_keys[DIK_R] && !m_preKeys[DIK_R])
			{
				m_game->GetAudioPlayer()->Play(Music::StartButton);
				m_game->GetCurrentLocation()->Initialize();
			}
			if (m_keys[DIK_1] && !m_preKeys[DIK_1])
			{
				m_game->GetCurrentLocation()->SetMainColor(WHITE);
			}
			if (m_keys[DIK_2] && !m_preKeys[DIK_2])
			{
				m_game->GetCurrentLocation()->SetMainColor(RED);
			}
			if (m_keys[DIK_3] && !m_preKeys[DIK_3])
			{
				m_game->GetCurrentLocation()->SetMainColor(GREEN);
			}
			if (m_keys[DIK_4] && !m_preKeys[DIK_4])
			{
				m_game->GetCurrentLocation()->SetMainColor(BLUE);
			}
			if (m_keys[DIK_5] && !m_preKeys[DIK_5])
			{
				m_game->GetCurrentLocation()->SwapMainAndSpareColors();
			}
		}
	}
}