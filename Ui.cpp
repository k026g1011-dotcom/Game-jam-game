#include "Ui.h"
#include "Game.h"
#include "LevelSelectMenu.h"
#include "TitleMenu.h"
#include "Hud.h"
#include "GameMenu.h"
Ui::Ui()
{

}
Ui::Ui(Game* game) :
	m_levelSelectMenu(game),
	m_titleMenu(game),
	m_clearMenu(game),
	m_hud(game)
{
/*	m_titleMenu.RegisterComponents();
	m_levelSelectMenu.RegisterComponents();*/
	
	m_game = game;
	
}
Hud* Ui::GetHud()
{
	return &m_hud;
}
void Ui::ShowTitleMenu()
{
	m_game->GetAudioPlayer()->StopBGM();
	m_currentMenu = &m_titleMenu;
	m_currentMenu->RegisterComponents();
}
void Ui::RequireTutor(bool value)
{
	m_hud.RequireTutor(value);
}
void Ui::ShowLevelSelectMenu()
{
	Novice::ConsolePrintf("Showing levelSelect menu \n");
	m_currentMenu = &m_levelSelectMenu;
	m_currentMenu->RegisterComponents();
	m_game->GetAudioPlayer()->StopBGM();
	m_game->GetAudioPlayer()->SetBGM(Music::NoiseBGM);
	m_game->GetAudioPlayer()->PlayBGM();
}
void Ui::ShowClearMenu(int value)
{
	Novice::ConsolePrintf("Showing levelClear menu \n");
	m_clearMenu.SetStars(value);
	m_currentMenu = &m_clearMenu;
	m_currentMenu->RegisterComponents();
	m_game->GetAudioPlayer()->StopBGM();
	m_game->GetAudioPlayer()->SetBGM(Music::NoiseBGM);
	m_game->GetAudioPlayer()->PlayBGM();
	m_game->GetAudioPlayer()->Play(Music::Cleared);
}
void Ui::CloseCurrentMenu()
{
	m_game->GetAudioPlayer()->StopBGM();
	m_currentMenu = nullptr;
}
Game* Ui::GetGame()
{
	return m_game;
}
GameMenu* Ui::GetCurrentMenu()
{
	return m_currentMenu;
}
void Ui::Update()
{
	m_hud.Update();
	if (m_currentMenu != nullptr)
	{
		m_currentMenu->Update();
	}
}
void Ui::Draw()
{
	if (m_currentMenu != nullptr)
	{
		m_currentMenu->Draw();
	}
	else
	{
		m_hud.Draw();
	}
}
/*	m_hud.Draw();
	Novice::ScreenPrintf(900, 0, "is current menu null: %s", m_currentMenu == nullptr ? "true" : "false");*/