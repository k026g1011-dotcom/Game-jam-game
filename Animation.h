#pragma once
#include "Frame.h"
#include <vector>
#include "AnimationConfig.h"
#include"GameTypes.h"
class Animation
{
public:
	Animation();
	Animation(Animations id,int animationDuration, const int(&animation)[AnimationConfig::FrameCount]);
	int GetAnimationTimer();
	void Update();
	void ResetAnimationTimer();
	int GetCurrentFrame();
	int GetCurrentSpriteFrame();
	void SetCurrentFrame(int value);
	void NextFrame();
	Animations GetId();
private:
	std::vector<int> m_frames;
	Animations m_id;
	int m_currentFrame;
	int m_animationDuration;
	int m_frameDuration;
	int m_timer;
};

