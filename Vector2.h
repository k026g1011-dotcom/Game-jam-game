#pragma once
#include "Vector2Int.h"
struct Vector2Int;
struct Vector2
{
	float x;
	float y;
	static const Vector2 Zero;
	static const Vector2 One;
	static const Vector2 Up;
	static const Vector2 Down;
	static const Vector2 Left;
	static const Vector2 Right;
	Vector2 operator+(const Vector2& other) const
	{
		return { x + other.x,y + other.y };
	}
	Vector2 operator-(const Vector2& other) const
	{
		return { x - other.x,y - other.y };
	}
	Vector2 operator*(const float other) const
	{
		return { x * other,y * other };
	}
	bool operator==(const Vector2& other) const
	{
		return { x == other.x&&y == other.y };
	}
	float GetLength();
	
	Vector2 AddClamp(Vector2 add, Vector2 LeftBottomEdge, Vector2 RightTopEdge);
	Vector2 GetNormal();
	Vector2 Rotate(const float angle)const;
	float Cross(const Vector2& other)const;
	Vector2Int ToInt();
};
#include <functional> // Обязательно для std::hash

namespace std {
	template <>
	struct hash<Vector2> {
		size_t operator()(const Vector2& v) const noexcept {
			// 1. Хэшируем отдельные float компоненты стандартным методом
			size_t h1 = std::hash<float>{}(v.x);
			size_t h2 = std::hash<float>{}(v.y);

			// 2. Смешиваем их с помощью золотого сечения (классический алгоритм из Boost)
			// Это защищает от ситуации, когда Vector2(1, 2) и Vector2(2, 1) дают одинаковый хэш
			return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
		}
	};
}

