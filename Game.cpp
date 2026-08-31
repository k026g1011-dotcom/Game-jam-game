#include "Game.h"
#include "MapConfigs.h"
#include<Novice.h>
#include "Grid.h"
#include "Player.h"
#include "Ui.h"
Game::Game(char(&keysArg)[256], char(&preKeysArg)[256])
	: m_gridTexture(Novice::LoadTexture("./resources/images/grid/grid.png")),
	  m_currentLocation(nullptr),
	  m_input(this, keysArg, preKeysArg),
	  m_player(this),
	  m_redBlock(this, RED),
	  m_greenBlock(this, GREEN),
	  m_blueBlock(this, BLUE),
	  m_star(this),
	  m_firstStage("FirstStage", this, MapConfig::FirstLevel),
	  m_secondStage("SecondStage", this, MapConfig::SecondLevel),
	  m_thirdStage("ThirdStage", this, MapConfig::ThirdLevel),
	  m_fourthStage("FourthStage", this, MapConfig::FourthLevel),
	  m_fifthStage("FifthStage", this, MapConfig::FifthLevel),
	  m_testStage("TestStage", this, MapConfig::TestLevel),
	  m_ui(this),
	  m_audioPlayer(this)
{
}
void Game::Instantiate()
{
	m_player.Instantiate();
	m_greenBlock.Instantiate();
	m_redBlock.Instantiate();
	m_blueBlock.Instantiate();
	m_star.Instantiate();
	m_currentLocation = nullptr;
	m_ui.ShowTitleMenu();
}
Ui* Game::GetUi()
{
	return &m_ui;
}
void Game::Update()
{
	m_input.Update();
	m_ui.Update();
	if (m_currentLocation != nullptr)
	{
		m_currentLocation->Update();
	}


	//m_player.Update();
}
void Game::Draw()
{
	
	if (m_currentLocation != nullptr)
	{
		m_currentLocation->Draw();
	}
	m_ui.Draw();
	//Novice::ScreenPrintf(0,45,"isMoving %s", m_player.IsMoving() ? "true" : "false");
	//Novice::ScreenPrintf(0, 60, "target x: %f, y: %f", m_player.GetTarget().x, m_player.GetTarget().y);
}
int Game::GetGridGh()
{
	return m_gridTexture;
}
Player* Game::GetPlayer()
{
	return &m_player;
}
Star* Game::GetStar()
{
	return &m_star;
}
AudioPlayer* Game::GetAudioPlayer()
{
	return &m_audioPlayer;
}
Block* Game::GetBlock(BlockTypes color)
{
	Block* result = nullptr;
	switch (color)
	{
	case BlockTypes::Red:
		result = &m_redBlock;
		break;
	case BlockTypes::Green:
		result = &m_greenBlock;
		break;
	case BlockTypes::Blue:
		result = &m_blueBlock;
		break;
	}
	return result;
}
GameLocation* Game::GetCurrentLocation()
{
	return m_currentLocation;
}
void Game::RunStage(int stage)
{
	switch (stage)
	{
	case -1:
		m_currentLocation = nullptr;
		break;
	case 1:
		m_currentLocation = &m_firstStage;
		m_ui.RequireTutor(true);
		break;
	case 2:
		m_currentLocation = &m_secondStage;
		m_ui.RequireTutor(false);
		break;
	case 3:
		m_currentLocation = &m_thirdStage;
		m_ui.RequireTutor(false);
		break;
	case 4:
		m_currentLocation = &m_fourthStage;
		m_ui.RequireTutor(false);
		break;
	case 5:
		m_currentLocation = &m_fifthStage;
		m_ui.RequireTutor(false);
		break;
	default:
		m_currentLocation = &m_testStage;
		break;
	}
	if (m_currentLocation != nullptr)
	{
		m_audioPlayer.StopBGM();
		m_audioPlayer.SetBGM(Music::KinescopBGM);
		m_audioPlayer.PlayBGM();
		m_currentLocation->Initialize();

	}
	
}
