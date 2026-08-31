#pragma once
#include "Vector2.h"
#include "Vector2Int.h"
#include "MapConfigs.h"
namespace Utils
{
	Vector2 TileToGlobal(Vector2Int tilePos);
	Vector2Int GlobalToLocal(Vector2 globalPos);
	Vector2Int TileToLocal(Vector2Int tilePos);
};

