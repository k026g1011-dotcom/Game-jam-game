#pragma once
#include "Vector2.h"
struct Vector2;
struct Vector2Int
{
	int x;
	int y;
	static const Vector2Int Zero;
	static const Vector2Int One;
	static const Vector2Int Up;
	static const Vector2Int Down;
	static const Vector2Int Left;
	static const Vector2Int Right;
	Vector2Int operator+(const Vector2Int& other) const
	{
		return { x + other.x,y + other.y };
	}
	Vector2Int operator-(const Vector2Int& other) const
	{
		return { x + other.x,y + other.y };
	}
	Vector2Int operator*(const int other) const
	{
		return { x * other,y * other };
	}
	bool operator==(const Vector2Int& other) const
	{
		return { x == other.x && y == other.y };
	}
	float GetLength();

	Vector2Int AddClamp(Vector2Int add, Vector2Int LeftBottomEdge, Vector2Int RightTopEdge);
	Vector2Int GetNormal();

	Vector2Int Rotate(const float angle)const;

	int Cross(const Vector2Int& other)const;
	Vector2 ToFloat();
};
#include <functional> // Обязательно для std::hash

namespace std {
	template <>
	struct hash<Vector2Int> {
		size_t operator()(const Vector2Int& v) const noexcept {
			// 1. Хэшируем отдельные float компоненты стандартным методом
			size_t h1 = std::hash<int>{}(v.x);
			size_t h2 = std::hash<int>{}(v.y);

			// 2. Смешиваем их с помощью золотого сечения (классический алгоритм из Boost)
			// Это защищает от ситуации, когда Vector2Int(1, 2) и Vector2Int(2, 1) дают одинаковый хэш
			return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
		}
	};
}

