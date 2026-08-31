#include "Animator.h"
#include "Animation.h"
#include "Vector2Int.h"
#include "Utils.h"
#include "Character.h"
#include <Novice.h>
#include <unordered_map>
#include <string>
Animator::Animator()
{
	m_spriteWidth = 0;
	m_spriteHeight = 0;
}
Animator::Animator(Character* character)
{
	m_owner = character;
	m_spriteWidth = 0;
	m_spriteHeight = 0;
}
void Animator::RegisterCharacter(Character* character)
{
	m_owner = character;
}
void Animator::SetDimensions(int srcWidth, int srcHeight)
{
	m_spriteWidth = srcWidth;
	m_spriteHeight = srcHeight;
}
void Animator::AddAnimation(Animations animationName, Animation* animation)
{
	m_animations.insert_or_assign(animationName, animation);
}
Animation* Animator::GetCurrentAnimation()
{
	return m_currentAnimation;
}
void Animator::Play(Animations animationName)
{
	if (m_animations.contains(animationName))
	{
		m_currentAnimation = m_animations.at(animationName);
		m_currentAnimation->SetCurrentFrame(0);
		m_currentAnimation->ResetAnimationTimer();
	}
	
}
void Animator::Update()
{
	if (m_currentAnimation != nullptr)
	{
		m_currentAnimation->Update();
	}
}
void Animator::Draw()
{
	if (m_owner == nullptr || m_currentAnimation == nullptr)
	{
		return;
	}

	int spriteFrame = m_currentAnimation->GetCurrentSpriteFrame();
	int columns = static_cast<int>(m_spriteWidth / m_owner->GetBody().width);
	if (spriteFrame < 0 || columns <= 0)
	{
		return;
	}

	int column = spriteFrame % columns;
	int raw = spriteFrame / columns;
	Vector2Int topLeftSrc = Vector2Int(column * static_cast<int>(m_owner->GetBody().width), raw * static_cast<int>(m_owner->GetBody().height));
	//Novice::ScreenPrintf(800, 600, "topLeftSrc x:%d y:%d", topLeftSrc.x, topLeftSrc.y);
	Novice::DrawQuad
	(
		Utils::GlobalToLocal(m_owner->GetBody().GetTopLeft()).x,
		Utils::GlobalToLocal(m_owner->GetBody().GetTopLeft()).y,
		Utils::GlobalToLocal(m_owner->GetBody().GetTopRight()).x,
		Utils::GlobalToLocal(m_owner->GetBody().GetTopRight()).y,
		Utils::GlobalToLocal(m_owner->GetBody().GetBottomLeft()).x,
		Utils::GlobalToLocal(m_owner->GetBody().GetBottomLeft()).y,
		Utils::GlobalToLocal(m_owner->GetBody().GetBottomRight()).x,
		Utils::GlobalToLocal(m_owner->GetBody().GetBottomRight()).y,
		topLeftSrc.x, topLeftSrc.y,
		//0,0,
		static_cast<int>(m_owner->GetBody().width), static_cast<int>(m_owner->GetBody().height),
		m_owner->GetGh(),
		m_owner->GetColor()
	);

}
