#pragma once
#include "Vector2.h"
#include "Square.h"
#include "Animator.h"
class Game;
class ProjectTile;
class ViewPort;
class Character
{
public:
	Character();
	Character(Game* game);
	virtual void Draw();
	void SetDirection(Vector2 value);
	
	Vector2 GetDirection();
	
	Vector2 GetPos();
	Animator* GetAnimator();
	void SetPos(Vector2 value);
	void SetFaceDir(Vector2 value);
	void SetTilePos(Vector2Int pos);
	void Move();
	void SetRadius(float value);
	float GetRadius();
	void SetColor(int value);
	int GetColor();
	void SetGh(int value);
	Game* GetGame();
	void SetTarget(Vector2Int target);
	Vector2 GetTarget();
	Vector2Int GetTilePos();
	void MoveToTarget();
	virtual void Update();
	Square GetBody();
	bool IsMoving();
	bool IsOnScreen();
	void SetOnScreen();
	void RemoveFromScreen();
	int GetGh();
	void RegisterAnimator();
private:
	bool m_isOnScreen=false;
	bool m_isMoving=false;
	int animationTimer;
	int currentFrame;
	float radius;
	float rotationSpeed;
	int color;
	Vector2Int m_tilePos;
	Vector2Int m_targetTilePos;
	Vector2 m_targetPos;
	Square m_body;
	float m_speed;
	int m_gh;
	Game* m_game=nullptr;
	Animator m_animator;
};

