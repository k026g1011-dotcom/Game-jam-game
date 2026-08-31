#include "Vector2.h"
#include "Vector2Int.h"
#include "Math.h"
const Vector2 Vector2::Zero=Vector2(0.0f,0.0f);
const Vector2 Vector2::One = Vector2(1.0f, 1.0f);
const Vector2 Vector2::Up = Vector2(0.0f, 1.0f);
const Vector2 Vector2::Down = Vector2(0.0f, -1.0f);
const Vector2 Vector2::Left = Vector2(-1.0f, 0.0f);
const Vector2 Vector2::Right = Vector2(1.0f, 0.0f);
float Vector2::GetLength()
{
	return sqrtf(x * x + y * y);
}
Vector2 Vector2::AddClamp(Vector2 add, Vector2 LeftBottomEdge, Vector2 RightTopEdge)
{
	float xNew = x + add.x;
	float yNew = y + add.y;
	if (xNew < LeftBottomEdge.x)
	{
		xNew = LeftBottomEdge.x;
	}
	if(xNew>RightTopEdge.x)
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
Vector2 Vector2::GetNormal()
{
	float length = GetLength();
	if (length == 0)
	{
		length = 1;
	}
	Vector2 normal{ x / length,y / length };
	return normal;
}
Vector2 Vector2::Rotate(const float angle)const
{
	return{ x * cosf(angle) - y * sinf(angle),x * sinf(angle) + y * cosf(angle) };
}
float Vector2::Cross(const Vector2& other)const
{
	return{ x * other.y - y * other.x };
}
Vector2Int Vector2::ToInt()
{
	return Vector2Int{ static_cast<int>(x),static_cast<int>(y) };
}