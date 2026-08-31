#pragma once
#include "Vector2.h"
#include "GameTypes.h"
class Tile
{
private:
	Vector2Int m_position;
	TileType m_type;
	Tile* m_neighborUp;
	Tile* m_neighborDown;
	Tile* m_neighborLeft;
	Tile* m_neighborRight;
	int m_color;
	int m_gh;
	Vector2Int GetSpritePos();
public:
	Tile();
	Tile(Vector2Int position, TileType type,int gh);
	bool IsPassable();
	Tile* GetNeighbor(Vector2Int which);
	void SetNeighbors(Tile& up, Tile& down, Tile& left, Tile& right);
	void SetColor(int value);
	int GetColor();
	void SetType(TileType value);
	TileType GetType();
	Vector2 GetGlobalPosition();
	Vector2Int GetPositionInt();
	void Draw();
	
};

