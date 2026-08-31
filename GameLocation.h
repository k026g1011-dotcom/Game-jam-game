#pragma once
#include"Grid.h"
#include"Player.h"
#include <string>
class Game;
class GameLocation
{
private:
	std::string m_name;
	Grid m_map;
	Game* m_game;
	std::vector<Character*> m_characters;
	int m_collectedStars;
	int m_leftedColorSwaps;
	bool m_isRedBlockInBase=false;
	bool m_isGreenBlockInBase = false;
	bool m_isBlueBlockInBase = false;
	bool m_isLevelCleared = false;
	int m_mainColor=WHITE;
	int m_spareColor = WHITE;
	//vector<>
public:
	GameLocation();
	GameLocation(std::string name,Game* game, const char(&map)[MapConfig::MapRows][MapConfig::MapCols + 1]);
	Grid* GetMap();
	std::string GetName();
	void Initialize();
	void SetBaseActiveForColor(BlockTypes color);
	void RegisterCharacter(Character* character);
	void RedBlockInBase();
	void GreenBlockInBase();
	void BlueBlockInBase();
	void AddStar();
	void Update();
	void Draw();
	void InitializePlayer();
	void InitializeStar();
	void InitializeBlocks();
	int GetBackgroundColor();
	int GetStars();
	int GetTokens();
	int GetMainColor();
	int GetSpareColor();
	void SetMainColor(int color);
	void SetSpareColor(int color);
	void SwapMainAndSpareColors();
	void ChangeFloorColor();
	Character* GetCharacterAt(Vector2Int tile);
};

