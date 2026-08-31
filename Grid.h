#pragma once
#include "Vector2.h"
#include "Tile.h"
#include <unordered_map>
#include "MapConfigs.h"
class Grid
{
private:
	std::unordered_map<Vector2Int, Tile> m_tiles;
	Vector2Int m_playerInitPos;
	Vector2Int m_redBlockInitPos;
	Vector2Int m_greenBlockInitPos;
	Vector2Int m_blueBlockInitPos;
	Vector2Int m_starInitPos;
public:
	Grid();
	Grid(const char(&map)[MapConfig::MapRows][MapConfig::MapCols + 1],int gh);
	//Tile* GetTileAt(Vector2 pos);
	Tile* GetTileAt(Vector2Int pos);
	Vector2 TilePosToGlobal(Vector2 pos);
	void Draw();
	Vector2Int GetPlayerInitPos();
	Vector2Int GetStarInitPos();
	Vector2Int GetBlockInitPos(BlockTypes color);
	void SetFloorColor(int color);
};

