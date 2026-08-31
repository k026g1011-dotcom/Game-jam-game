#include "Tile.h"
#include "Vector2.h"
#include "GameTypes.h"
#include <Novice.h>
#include "MapConfigs.h"
#include "Utils.h"
Tile::Tile()
{
	m_position = Vector2Int::Zero;
	m_type = TileType::None;
	m_neighborUp = nullptr;
	m_neighborDown = nullptr;
	m_neighborLeft = nullptr;
	m_neighborRight = nullptr;
	m_color = WHITE;
	m_gh = 0;
}
Tile::Tile(Vector2Int position, TileType type,int gh)
{
	m_position = position;
	m_type = type;
	m_neighborUp = nullptr;
	m_neighborDown = nullptr;
	m_neighborLeft = nullptr;
	m_neighborRight = nullptr;
	m_color = WHITE;
	m_gh = gh;
}
bool Tile::IsPassable()
{
	if (m_type == TileType::Floor|| m_type == TileType::Base)
	{
		return true;
	}
	return false;
}
void Tile::SetNeighbors(Tile& up, Tile& down, Tile& left, Tile& right)
{
	m_neighborDown = &down;
	m_neighborUp = &up;
	m_neighborLeft = &left;
	m_neighborRight = &right;
}
Tile* Tile::GetNeighbor(Vector2Int witch)
{
	if (witch == Vector2Int::Up)
	{
		return m_neighborUp;
	}
	if (witch == Vector2Int::Down)
	{
		return m_neighborDown;
	}
	if (witch == Vector2Int::Left)
	{
		return m_neighborLeft;
	}
	if (witch == Vector2Int::Right)
	{
		return m_neighborRight;
	}
	return nullptr;
}
void Tile::SetColor(int value)
{
	m_color = value;
}
int Tile::GetColor()
{
	return m_color;
}
Vector2 Tile::GetGlobalPosition()
{
	return Utils::TileToGlobal(m_position);
}
Vector2Int Tile::GetPositionInt()
{
	return m_position;
}
void Tile::SetType(TileType value)
{
	m_type = value;
}
TileType Tile::GetType()
{
	return m_type;
}
Vector2Int Tile::GetSpritePos()
{
	Vector2Int result = Vector2Int::Zero;
	switch (m_type)
	{
	case TileType::Wall:
		result = Vector2Int(static_cast<int>(MapConfig::TileWidth), 0);
		break;
	case TileType::Floor:
		result = Vector2Int(2* static_cast<int>(MapConfig::TileWidth), 0);
		break;
	case TileType::Base:
		result = Vector2Int(3 * static_cast<int>(MapConfig::TileWidth), 0);
		break;
	default:
		break;
	}
	return result;
}
void Tile::Draw()
{
	//Novice::DrawSprite(m_position.x * static_cast<int>(MapConfig::TileWidth), MapConfig::kWindowHeight - m_position.y * static_cast<int>(MapConfig::TileHeight), m_gh, 1.0f, 1.0f, 0.0f, m_color);
	Vector2Int rectPos = GetSpritePos();
	int xOffset = static_cast<int>(MapConfig::kWindowWidth / 2 - MapConfig::MapCols * MapConfig::TileWidth / 2);
	int YOffset = static_cast<int>(MapConfig::kWindowHeight / 2 - MapConfig::MapRows * MapConfig::TileHeight / 2);
	Novice::DrawQuad(
		m_position.x * static_cast<int>(MapConfig::TileWidth)+ xOffset,
		MapConfig::kWindowHeight - (m_position.y+1) * static_cast<int>(MapConfig::TileHeight)- YOffset,
		m_position.x * static_cast<int>(MapConfig::TileWidth) + static_cast<int>(MapConfig::TileWidth)+xOffset,
		MapConfig::kWindowHeight - (m_position.y + 1) * static_cast<int>(MapConfig::TileHeight) - YOffset,
		m_position.x * static_cast<int>(MapConfig::TileWidth) + xOffset,
		MapConfig::kWindowHeight - (m_position.y) * static_cast<int>(MapConfig::TileHeight) - YOffset,
		m_position.x * static_cast<int>(MapConfig::TileWidth) + static_cast<int>(MapConfig::TileWidth) + xOffset,
		MapConfig::kWindowHeight - (m_position.y) * static_cast<int>(MapConfig::TileHeight) - YOffset,
		rectPos.x,
		rectPos.y,
		static_cast<int>(MapConfig::TileWidth),
		static_cast<int>(MapConfig::TileHeight),
		m_gh,
		m_color);
}