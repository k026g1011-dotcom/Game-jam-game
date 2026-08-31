#pragma once
#include <numbers>
#include "Square.h"
#include "Vector2.h"
struct Square
{
	Vector2 position;
	//Vector2 faceDirection;
	Vector2 direction;
	Vector2 faceDirection;
	float height;
	float width;
	Vector2 GetTopLeft();
	Vector2 GetTopRight();
	Vector2 GetBottomRight();
	Vector2 GetBottomLeft();
	void SetFaceDir(Vector2 faceDir);
};

