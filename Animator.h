#pragma once
#include <unordered_map>
#include <string>
#include "GameTypes.h"
class Character;
class Animation;
class Animator
{
private:
	std::unordered_map<Animations, Animation*> m_animations;
	Animation* m_currentAnimation=nullptr;
	int m_spriteWidth;
	int m_spriteHeight;
	Character* m_owner=nullptr;


public:
	Animator();
	Animator(Character* m_owner);
	void AddAnimation(Animations animationName, Animation* animation);
	void SetDimensions(int srcWidth, int srcHeight);
	Animation* GetCurrentAnimation();
	void Play(Animations animationName);
	void Draw();
	void Update();
	void RegisterCharacter(Character* character);
};

