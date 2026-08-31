#include "Vector2.h"
#include "Vector2Int.h"
#include "Math.h"
const Vector2Int Vector2Int::Zero = Vector2Int(0, 0);
const Vector2Int Vector2Int::One = Vector2Int(1, 1);
const Vector2Int Vector2Int::Up = Vector2Int(0, 1);
const Vector2Int Vector2Int::Down = Vector2Int(0, -1);
const Vector2Int Vector2Int::Left = Vector2Int(-1, 0);
const Vector2Int Vector2Int::Right = Vector2Int(1, 0);
float Vector2Int::GetLength()
{
	return sqrtf(static_cast<float>(x * x + y * y));
}
Vector2Int Vector2Int::AddClamp(Vector2Int add, Vector2Int LeftBottomEdge, Vector2Int RightTopEdge)
{
	int xNew = x + add.x;
	int yNew = y + add.y;
	if (xNew < LeftBottomEdge.x)
	{
		xNew = LeftBottomEdge.x;
	}
	if (xNew > RightTopEdge.x)
	{
		xNew = RightTopEdge.x;
	}
	if (yNew < LeftBottomEdge.y)
	{
		yNew = LeftBottomEdge.y;
	}
	if (yNew > RightTopEdge.y)
	{
		yNew = RightTopEdge.y;
	}
	return{ xNew,yNew };
}
Vector2Int Vector2Int::GetNormal()
{
	float length = GetLength();
	if (length == 0)
	{
		length = 1;
	}
	Vector2Int normal{ static_cast<int>(x / length),static_cast<int>(y / length) };
	return normal;
}
Vector2Int Vector2Int::Rotate(const float angle)const
{
	return{ static_cast<int>(x * cosf(angle) - y * sinf(angle)),static_cast<int>(x * sinf(angle) + y * cosf(angle))};
}
int Vector2Int::Cross(const Vector2Int& other)const
{
	return{ x * other.y - y * other.x };
}
Vector2 Vector2Int::ToFloat()
{
	return Vector2{ static_cast<float>(x),static_cast<float>(y) };
}