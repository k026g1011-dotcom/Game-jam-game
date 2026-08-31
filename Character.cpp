#include "Character.h"
#include "Vector2.h"
#include "Square.h"
#include <Novice.h>
#include "Game.h"
#include "Utils.h"

Character::Character()
{
	m_isMoving = false;
	m_speed = 1.0f;//MapConfig::TileHeight/60.0f;
	radius = 0;
	color = WHITE;
	animationTimer = 0;
	currentFrame = 0;
	m_body = Square(Vector2::Zero, Vector2{0.0f,-1.0f}, Vector2{ 0.0f,-1.0f }, 32.0f, 32.0f);
	m_gh = 0;//Novice::LoadTexture("./resources/images/characters/Player.png");
	rotationSpeed = 0.01f;
}
Character::Character(Game* game)
{
	m_isMoving = false;
	rotationSpeed = 0.01f;
	m_speed = 1.0f;//MapConfig::TileHeight/60.0f;
	radius = 0;
	color = WHITE;
	animationTimer = 0;
	currentFrame = 0;
	m_body = Square(Vector2::Zero, Vector2{ 0.0f,-1.0f }, Vector2{ 0.0f,-1.0f }, 32.0f, 32.0f);
	m_gh = 0;//Novice::LoadTexture("./resources/images/characters/Player.png");
	m_game = game;
	m_animator = Animator();
}
void Character::RegisterAnimator()
{
	m_animator.RegisterCharacter(this);
}
Game* Character::GetGame()
{
	return m_game;
}
Animator* Character::GetAnimator()
{
	return &m_animator;
}
void Character:: Move()
{
	if (m_body.direction == Vector2::Zero)
	{
		return;
	}
	m_body.position = m_body.position + (m_body.direction)*m_speed;
}
void Character::Draw()
{
	//Novice::ConsolePrintf("PLAYER DRAW");
	//Novice::ScreenPrintf(0, 0, "Player's pos is x: %f, y: %f", m_body.position.x, m_body.position.y);
	//Novice::ScreenPrintf(0, 15, "Player's dir is x: %f, y: %f", (m_targetPos - m_body.position).x, (m_targetPos - m_body.position).y);
/*	Novice::ScreenPrintf(0, 15, "Player's pos on screen is x1: %f, y1: %f, x2: %f, y2: %f, x3: %f, y3: %f, x4: %f, y4: %f", body.GetTopLeft().x,
		body.GetTopLeft().y,
		body.GetTopRight().x,
		body.GetTopRight().y,
		body.GetBottomLeft().x,
		body.GetBottomLeft().y,
		body.GetBottomRight().x,
		body.GetBottomRight().y);*/
/*	Novice::ScreenPrintf(0, 15, "Player's pos on screen is x1: %d, y1: %d, x2: %d, y2: %d, x3: %d, y3: %d, x4: %d, y4: %d", Utils::GlobalToLocal(body.GetTopLeft()).x,
		Utils::GlobalToLocal(body.GetTopLeft()).y,
		Utils::GlobalToLocal(body.GetTopRight()).x,
		Utils::GlobalToLocal(body.GetTopRight()).y,
		Utils::GlobalToLocal(body.GetBottomLeft()).x,
		Utils::GlobalToLocal(body.GetBottomLeft()).y,
		Utils::GlobalToLocal(body.GetBottomRight()).x,
		Utils::GlobalToLocal(body.GetBottomRight()).y);*/
	//Novice::ScreenPrintf(0, 30, "test %f", (MapConfig::kWindowWidth - MapConfig::MapCols * MapConfig::TileWidth));
	if (m_isOnScreen)
	{
		m_animator.Draw();
		/*Novice::DrawQuad
		(
			Utils::GlobalToLocal(m_body.GetTopLeft()).x,
			Utils::GlobalToLocal(m_body.GetTopLeft()).y,
			Utils::GlobalToLocal(m_body.GetTopRight()).x,
			Utils::GlobalToLocal(m_body.GetTopRight()).y,
			Utils::GlobalToLocal(m_body.GetBottomLeft()).x,
			Utils::GlobalToLocal(m_body.GetBottomLeft()).y,
			Utils::GlobalToLocal(m_body.GetBottomRight()).x,
			Utils::GlobalToLocal(m_body.GetBottomRight()).y,
			0, 0,
			static_cast<int>(m_body.width), static_cast<int>(m_body.height),
			m_gh,
			color
		);*/
	}
	
	//Novice::DrawEllipse(static_cast<int>(GetPos().x), static_cast<int>(GetPos().y), static_cast<int>(GetRadius()), static_cast<int>(GetRadius()), 0.0f, RED, kFillModeWireFrame);
}
void Character::SetDirection(Vector2 value)
{
	m_body.direction = value;
	if (m_body.direction.x < -1)
	{
		m_body.direction.x = -1;
	}
	if (m_body.direction.x > 1)
	{
		m_body.direction.x = 1;
	}
	if (m_body.direction.y < -1)
	{
		m_body.direction.y = -1;
	}
	if (m_body.direction.y > 1)
	{
		m_body.direction.y = 1;
	}
}
Vector2 Character::GetDirection()
{
	return m_body.direction;
}
Vector2 Character::GetPos()
{
	return m_body.position;
}
Vector2 Character::GetTarget()
{
	return m_targetPos;
}
void Character::SetTarget(Vector2Int targetPos)
{
	m_targetTilePos = targetPos;
	m_targetPos=Utils::TileToGlobal(targetPos);
}
void Character::SetTilePos(Vector2Int tilePos)
{
	Novice::ConsolePrintf(" position setted at x: %d y: %d", tilePos.x, tilePos.y);
	m_tilePos = tilePos;
	SetPos(Utils::TileToGlobal(tilePos));
}
void Character::SetPos(Vector2 value)
{
	m_body.position = value;
}
void Character::SetFaceDir(Vector2 value)
{
	m_body.faceDirection = value;
}
void Character::SetRadius(float value)
{
	radius = value;
}
float Character::GetRadius()
{
	return radius;
}
void Character::SetColor(int value)
{
	color = value;
}
int Character::GetColor()
{ 
	return color;
}
void Character::SetGh(int value)
{
	m_gh = value;
}
void Character::Update()
{
	if (m_isOnScreen)
	{
		m_animator.Update();
		if (!(m_targetPos.ToInt() == m_body.position.ToInt()))
		{
			m_isMoving = true;
			m_body.direction = (m_targetPos - m_body.position).GetNormal();
		}
		else if(m_isMoving)
		{
			SetTilePos(m_targetTilePos);
			m_body.direction = Vector2::Zero;
			m_animator.Play(Animations::PlayerIdle);
			m_isMoving = false;
		}
		if (m_isMoving)
		{
			Move();
		}
	}
}
Square Character::GetBody()
{
	return m_body;
}
int Character::GetGh()
{
	return m_gh;
}
bool Character::IsMoving()
{
	return m_isMoving;
}
bool Character::IsOnScreen()
{
	return m_isOnScreen;
}
void Character::SetOnScreen()
{
	m_isOnScreen = true;
}
void Character::RemoveFromScreen()
{
	m_isOnScreen = false;
}
Vector2Int Character::GetTilePos()
{
	return m_tilePos;
}