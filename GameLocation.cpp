
#include "GameLocation.h"
#include "Game.h"
#include"Grid.h"
#include"Player.h"
#include <string>
#include "Utils.h"
GameLocation::GameLocation()
{
	m_name = "NoLocation";
	m_map = Grid();
	m_game = nullptr;
	m_collectedStars = 0;
	m_leftedColorSwaps = 0;
	m_isRedBlockInBase = false;
	m_isGreenBlockInBase = false;
	m_isBlueBlockInBase = false;
	m_isLevelCleared = false;
};
GameLocation::GameLocation(std::string name, Game* game, const char(&map)[MapConfig::MapRows][MapConfig::MapCols + 1]) :m_game(game)
{
	m_name = name;
	m_map = Grid(map, m_game->GetGridGh());
	m_collectedStars = 0;
	m_leftedColorSwaps = 0;
	m_isRedBlockInBase = false;
	m_isGreenBlockInBase = false;
	m_isBlueBlockInBase = false;
	m_isLevelCleared = false;
}
Grid* GameLocation::GetMap()
{
	return &m_map;
}
std::string GameLocation::GetName()
{
	return m_name;
}
void GameLocation::Initialize()
{
	m_characters.clear();
	m_collectedStars = 0;
	m_leftedColorSwaps = 2;
	m_isRedBlockInBase = false;
	m_isGreenBlockInBase = false;
	m_isBlueBlockInBase = false;
	m_isLevelCleared = false;
	m_mainColor = WHITE;
	m_spareColor = WHITE;
	ChangeFloorColor();
	RegisterCharacter(m_game->GetPlayer());
	InitializePlayer();
	InitializeBlocks();
	InitializeStar();
}
void GameLocation::RegisterCharacter(Character* character)
{
	m_characters.push_back(character);
}
void GameLocation::RedBlockInBase()
{
	m_isRedBlockInBase = true;
}
void GameLocation::GreenBlockInBase()
{
	m_isGreenBlockInBase = true;
}
void GameLocation::BlueBlockInBase()
{
	m_isBlueBlockInBase = true;
}
void GameLocation::AddStar()
{
	if (m_collectedStars < 3)
	{
		m_collectedStars++;
	}
}
void GameLocation::Update()
{
	for (auto& character : m_characters)
	{
		character->Update();
	}
	if (m_game->GetPlayer()->GetTilePos() == m_game->GetStar()->GetTilePos())
	{
		m_game->GetAudioPlayer()->Play(Music::StarPickedUp);
		AddStar();
		m_game->GetStar()->SetTilePos(Vector2Int(-1000, -1000));
	}
	for (int i = 0;i < static_cast<int>(BlockTypes::Count);i++)
	{
		Block* block = m_game->GetBlock(static_cast<BlockTypes>(i));
		Tile* tile = m_map.GetTileAt(block->GetTilePos());
		if (tile->GetType() == TileType::Base && block->GetColor() == tile->GetColor())
		{
			SetBaseActiveForColor(static_cast<BlockTypes>(i));
			block->SetTilePos(Vector2Int(-1000, -1000 + i));
		}
	}
	
	if (m_isRedBlockInBase && m_isGreenBlockInBase && m_isBlueBlockInBase)
	{
		m_isLevelCleared = true;
	}
	if (m_isLevelCleared)
	{
		AddStar();
		if (m_leftedColorSwaps >= 0)
		{
			AddStar();
		}
		m_game->GetUi()->ShowClearMenu(m_collectedStars);
		//m_game->RunStage(-1);
		Initialize();
	}
}
void GameLocation::SetBaseActiveForColor(BlockTypes color)
{
	m_game->GetAudioPlayer()->Play(Music::BlockSetted);
	switch (color)
	{
	case BlockTypes::Red:
		RedBlockInBase();
		break;
	case BlockTypes::Green:
		GreenBlockInBase();
		break;
	case BlockTypes::Blue:
		BlueBlockInBase();
		break;
	}
}
void GameLocation::Draw()
{
	Novice::DrawBox(0, 0, MapConfig::kWindowWidth, MapConfig::kWindowHeight, 0.0f, BLACK, kFillModeSolid);
	m_map.Draw();
	Player* player = nullptr;
	for (auto& character : m_characters)
	{
		player = dynamic_cast<Player*>(character);
		if (player != nullptr)
		{
			
			player->Draw();
		}
		else
		{
			character->Draw();
		}
	}
	/*Novice::ScreenPrintf(500, 0, "is red in base: %s", m_isRedBlockInBase ? "true" : "false");
	Novice::ScreenPrintf(500, 15, "is green in base: %s", m_isGreenBlockInBase ? "true" : "false");
	Novice::ScreenPrintf(500, 30, "is blue in base: %s", m_isBlueBlockInBase ? "true" : "false");
	Novice::ScreenPrintf(500, 45, "is cleared: %s", m_isLevelCleared ? "true" : "false");
	Novice::ScreenPrintf(500, 60, "Stars: %d", m_collectedStars);
	Novice::ScreenPrintf(500, 75, "ColorSwaps: %d", m_leftedColorSwaps);
	Novice::ScreenPrintf(0, 600, "Main color: %d", m_mainColor);
	Novice::ScreenPrintf(200, 600, "Spare color: %d", m_spareColor);*/
}
Character* GameLocation::GetCharacterAt(Vector2Int tile)
{
	for (auto& character : m_characters)
	{
		if (character->GetTilePos() == tile)
		{
			return character;
		}
	}
	return nullptr;
}
void GameLocation::InitializePlayer()
{
	Player* player = nullptr;
	for (auto& character : m_characters)
	{
		player = dynamic_cast<Player*>(character);
		if (player != nullptr)
		{
			Novice::ConsolePrintf("PLAYER FOUNDED");
			player->SetTilePos(m_map.GetPlayerInitPos());
			player->SetTarget(m_map.GetPlayerInitPos());
			player->SetOnScreen();
		}
	}
	
}
void GameLocation::InitializeStar()
{
	Star* star = m_game->GetStar();

	if (star != nullptr)
	{
		RegisterCharacter(star);
		star->SetTilePos(m_map.GetStarInitPos());
		star->SetTarget(m_map.GetStarInitPos());
		star->SetOnScreen();
	}

}
void GameLocation::InitializeBlocks()
{
	for (int i = 0;i < static_cast<int>(BlockTypes::Count);i++)
	{
		Block* block = m_game->GetBlock(static_cast<BlockTypes>(i));
		if ( block!= nullptr)
		{
			RegisterCharacter(block);
			block->SetTilePos(m_map.GetBlockInitPos(static_cast<BlockTypes>(i)));
			block->SetTarget(m_map.GetBlockInitPos(static_cast<BlockTypes>(i)));
			block->SetOnScreen();
		}
	}
	
}
int GameLocation::GetBackgroundColor()
{
	return m_mainColor;
}
int GameLocation::GetStars()
{
	return m_collectedStars;
}
int GameLocation::GetTokens()
{
	return m_leftedColorSwaps;
}
int GameLocation::GetMainColor()
{
	return m_mainColor;
}
int GameLocation::GetSpareColor()
{
	return m_spareColor;
}
void GameLocation::SetMainColor(int color)
{
	m_mainColor = color;
	m_leftedColorSwaps--;
	ChangeFloorColor();

}
void GameLocation::SetSpareColor(int color)
{
	m_spareColor = color;

}
void GameLocation::SwapMainAndSpareColors()
{
	int colorTMP = m_mainColor;
	m_mainColor = m_spareColor;
	m_spareColor = colorTMP;
	ChangeFloorColor();
}
void GameLocation::ChangeFloorColor()
{
	m_game->GetAudioPlayer()->Play(Music::StartButton);
	m_map.SetFloorColor(m_mainColor);
	for (int i = 0;i < static_cast<int>(BlockTypes::Count);i++)
	{
		Block* block = m_game->GetBlock(static_cast<BlockTypes>(i));
		if (block != nullptr)
		{
			if (block->GetColor() == m_mainColor)
			{
				block->RemoveFromScreen();
			}
			else
			{
				block->SetOnScreen();
			}
		}
	}
}