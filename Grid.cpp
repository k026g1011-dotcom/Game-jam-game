#include "Grid.h"
#include "MapConfigs.h"
#include <Novice.h>
#include "Utils.h"
Grid::Grid()
{

}
Grid::Grid(const char(&map)[MapConfig::MapRows][MapConfig::MapCols + 1], int gh)
{
	m_tiles.clear();
	for (int y = 0;y < MapConfig::MapRows;y++) {
		for (int x = 0;x < MapConfig::MapCols;x++) {
			Vector2Int pos = { x,y };
			Tile tile(pos, TileType::None, gh);
			if (map[MapConfig::MapRows-1-y][x] == MapConfig::FloorChar|| map[MapConfig::MapRows - 1 - y][x] == MapConfig::PlayerChar || map[MapConfig::MapRows - 1 - y][x] == MapConfig::RedBlockChar || map[MapConfig::MapRows - 1 - y][x] == MapConfig::GreenBlockChar || map[MapConfig::MapRows - 1 - y][x] == MapConfig::BlueBlockChar || map[MapConfig::MapRows - 1 - y][x] == MapConfig::StarChar)
			{
				tile.SetType(TileType::Floor);
				if (map[MapConfig::MapRows - 1 - y][x] == MapConfig::PlayerChar)
				{
					m_playerInitPos = pos;
				}
				if (map[MapConfig::MapRows - 1 - y][x] == MapConfig::RedBlockChar)
				{
					m_redBlockInitPos = pos;
				}
				if (map[MapConfig::MapRows - 1 - y][x] == MapConfig::GreenBlockChar)
				{
					m_greenBlockInitPos = pos;
				}
				if (map[MapConfig::MapRows - 1 - y][x] == MapConfig::BlueBlockChar)
				{
					m_blueBlockInitPos = pos;
				}
				if (map[MapConfig::MapRows - 1 - y][x] == MapConfig::StarChar)
				{
					m_starInitPos = pos;
				}
			}
			else if (map[MapConfig::MapRows - 1 - y][x] == MapConfig::RedBaseChar || map[MapConfig::MapRows - 1 - y][x] == MapConfig::GreenBaseChar || map[MapConfig::MapRows - 1 - y][x] == MapConfig::BlueBaseChar)
			{
				tile.SetType(TileType::Base);
				if (map[MapConfig::MapRows - 1 - y][x] == MapConfig::RedBaseChar)
				{
					tile.SetColor(RED);
				}
				if (map[MapConfig::MapRows - 1 - y][x] == MapConfig::GreenBaseChar)
				{
					tile.SetColor(GREEN);
				}
				if (map[MapConfig::MapRows - 1 - y][x] == MapConfig::BlueBaseChar)
				{
					tile.SetColor(BLUE);
				}
			}
			else if (map[MapConfig::MapRows - 1 - y][x] == MapConfig::WallChar)
			{
				tile.SetType(TileType::Wall);
			}
			//Novice::ConsolePrintf("x: %d, y: %d type: %c", pos.x, pos.y,map[pos.y][pos.x]);
			m_tiles.insert({ pos,tile });
			
		}
	}
	for (auto& v : m_tiles)
	{
		Vector2Int pos = v.first;
		Vector2Int topRightEdge = Vector2Int(MapConfig::MapRows, MapConfig::MapCols);
		v.second.SetNeighbors(m_tiles[pos.AddClamp(Vector2Int::Up,Vector2Int::Zero, topRightEdge)], m_tiles[pos.AddClamp(Vector2Int::Down, Vector2Int::Zero, topRightEdge)], m_tiles[pos.AddClamp(Vector2Int::Left, Vector2Int::Zero, topRightEdge)], m_tiles[pos.AddClamp(Vector2Int::Right, Vector2Int::Zero, topRightEdge)]);
	}
}
Vector2 Grid::TilePosToGlobal(Vector2 pos)
{
	Vector2 globalPos = { (pos.x+0.5f) * MapConfig::TileWidth,(pos.y + 0.5f) * MapConfig::TileHeight};
	return globalPos;
}
void Grid::Draw()
{
	for (auto& v : m_tiles)
	{
		v.second.Draw();
	}
	if (m_tiles.contains(Vector2Int::Zero))
	{
		m_tiles[Vector2Int::Zero].Draw();
	}
}
Vector2Int Grid::GetPlayerInitPos()
{
	return m_playerInitPos;
}
Vector2Int Grid::GetStarInitPos()
{
	return m_starInitPos;
}
/*Tile* Grid::GetTileAt(Vector2 pos)
{
	Vector2 tilePos=Utils::Global
}*/
Tile* Grid::GetTileAt(Vector2Int pos)
{
	return &m_tiles[pos];
}
Vector2Int Grid::GetBlockInitPos(BlockTypes color)
{
	Vector2Int result = Vector2Int(-1000, -1000);
	switch(color)
	{
	case BlockTypes::Red:
		result = m_redBlockInitPos;
		break;
	case BlockTypes::Green:
		result = m_greenBlockInitPos;
		break;
	case BlockTypes::Blue:
		result = m_blueBlockInitPos;
		break;
	}
	return result;
}
void Grid::SetFloorColor(int color)
{
	for (auto& v : m_tiles)
	{
		if (v.second.GetType() == TileType::Floor)
		{
			v.second.SetColor(color);
		}
		
	}
}