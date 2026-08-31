#pragma once
#include "Grid.h"
#include "MapConfigs.h"
#include "Player.h"
#include "GameLocation.h"
#include "Block.h"
#include "Star.h"
#include "Ui.h"
#include "Input.h"
#include "AudioPlayer.h"
class Game
{
private:
	int m_gridTexture;
	GameLocation* m_currentLocation;
	Input m_input;
	Player m_player;
	Block m_redBlock;
	Block m_greenBlock;
	Block m_blueBlock;
	Star m_star;
	GameLocation m_firstStage;
	GameLocation m_secondStage;
	GameLocation m_thirdStage;
	GameLocation m_fourthStage;
	GameLocation m_fifthStage;
	GameLocation m_testStage;
	Ui m_ui;
	AudioPlayer m_audioPlayer;
public:
	Game(char(&keysArg)[256], char(&preKeysArg)[256]);
	Player* GetPlayer();
	AudioPlayer* GetAudioPlayer();
	GameLocation* GetCurrentLocation();
	int GetGridGh();
	void Draw();
	void Update();
	Block* GetBlock(BlockTypes which);
	Star* GetStar();
	void RunStage(int stage);
	Ui* GetUi();
	void Instantiate();
};

