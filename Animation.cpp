#include "Animation.h"
#include "Frame.h"
#include <vector>
Animation::Animation()
{
	m_id = Animations::None;
	m_currentFrame=0;
	m_animationDuration=0;
	m_frameDuration=0;
	m_timer=0;
	m_frames.clear();
}
Animation::Animation(Animations id, int animationDuration, const int(&animation)[AnimationConfig::FrameCount])
{
	m_id = id;
	m_frames.clear();
	for (int i = 0;i < AnimationConfig::FrameCount;i++)
	{
		if (animation[i] >= 0)
		{
			m_frames.push_back(animation[i]);
		}
	}
	m_currentFrame = 0;
	m_animationDuration = animationDuration;
	m_frameDuration = static_cast<int>(m_frames.size()==0?0:( animationDuration / static_cast<int>(m_frames.size())));
	m_timer = 0;
}
Animations Animation::GetId()
{
	return m_id;
}
int Animation::GetAnimationTimer()
{
	return m_timer;
}
void Animation::Update()
{
	m_timer++;
	if (m_timer > m_frameDuration)
	{
		NextFrame();
		ResetAnimationTimer();
	}
}
void Animation::ResetAnimationTimer()
{
	m_timer = 0;
}
int Animation::GetCurrentFrame()
{
	return m_currentFrame;
}
int Animation::GetCurrentSpriteFrame()
{
	if (m_currentFrame >= static_cast<int>(m_frames.size())|| m_currentFrame<0)
	{
		return -1;
	}
	return m_frames[m_currentFrame];
}
void Animation::SetCurrentFrame(int value)
{
	if (value >= static_cast<int>(m_frames.size()))
	{
		return;
	}
	m_currentFrame = value;
}
void Animation::NextFrame()
{
	m_currentFrame = static_cast<int>(m_frames.size())==0?0:((m_currentFrame + 1) % static_cast<int>(m_frames.size()));
}