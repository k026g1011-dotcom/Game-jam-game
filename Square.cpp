#define _USE_MATH_DEFINES
#include <numbers>
#include <Math.h>
#include "Square.h"
#include "Vector2.h"
Vector2 Square::GetTopLeft()
{
	float angle = atan2f(faceDirection.y, faceDirection.x) + static_cast<float>(M_PI / 2);
	Vector2 Result
	{
		position.x - width / 2 * cosf(angle) + height / 2 * sinf(angle),
		position.y - height / 2 * cosf(angle) - width / 2 * sinf(angle)
	};
	return Result;
};
Vector2 Square::GetTopRight()
{
	float angle = atan2f(faceDirection.y, faceDirection.x) + static_cast<float>(M_PI / 2);
	Vector2 Result
	{
		position.x + width / 2 * cosf(angle) + height / 2 * sinf(angle),
		position.y - height / 2 * cosf(angle) + width / 2 * sinf(angle)
	};
	return Result;
};
Vector2 Square::GetBottomRight()
{
	float angle = atan2f(faceDirection.y, faceDirection.x) + static_cast<float>(M_PI / 2);
	Vector2 Result
	{
		position.x + width / 2 * cosf(angle) - height / 2 * sinf(angle),
		position.y + height / 2 * cosf(angle) + width / 2 * sinf(angle)
	};
	return Result;
};
Vector2 Square::GetBottomLeft()
{
	float angle = atan2f(faceDirection.y, faceDirection.x) + static_cast<float>(M_PI / 2);
	Vector2 Result
	{
		position.x - width / 2 * cosf(angle) - height / 2 * sinf(angle),
		position.y + height / 2 * cosf(angle) - width / 2 * sinf(angle)
	};
	return Result;
};
void Square::SetFaceDir(Vector2 faceDir)
{
	faceDirection = faceDir;
}