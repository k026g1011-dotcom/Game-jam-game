#include "ClickableComponent.h"
#include <Novice.h>
#include <string>
ClickableComponent::ClickableComponent()
{
	m_id = ButtonType::None;
	m_pos = Vector2Int::Zero;
	m_width = 0;
	m_height = 0;
	m_gh = Novice::LoadTexture("./resources/images/Ui/PlaceHolder.png");
}
ClickableComponent::ClickableComponent(ButtonType id, Vector2Int pos, int width, int height, int gh)
{
	m_id = id;
	m_pos = pos;
	m_width = width;
	m_height = height;
	m_gh = gh;
}
bool ClickableComponent::IsSelected()
{
	return m_isSelected;
}
bool ClickableComponent::IsIntersect(Vector2Int pos)
{
	//Novice::ScreenPrintf(m_pos.x + static_cast<int>(m_width / 4), m_pos.y + static_cast<int>(m_height / 4)+15, "mouse pos x: %d y: %d", pos.x, pos.y);
	if (pos.x > m_pos.x && pos.x < m_pos.x + m_width)
	{
		if (pos.y > m_pos.y && pos.y < m_pos.y + m_height)
		{
			return true;
		}
	}
	return false;
}
void ClickableComponent::SetGh(int gh)
{
	m_gh = gh;
}
ButtonType ClickableComponent::GetId()
{
	return m_id;
}
ClickableComponent* ClickableComponent::GetUpNeighbor()
{
	return m_upNeighbor;
}
ClickableComponent* ClickableComponent::GetDownNeighbor()
{
	return m_downNeighbor;
}
ClickableComponent* ClickableComponent::GetLeftNeighbor()
{
	return m_leftNeighbor;
}
ClickableComponent* ClickableComponent::GetRightNeighbor()
{
	return m_rightNeighbor;
}
void ClickableComponent::SetSelected(bool value)
{
	
	m_isSelected = value;
}
void ClickableComponent::Draw()
{
	int pad = m_isSelected? 5:0;
	Novice::DrawQuad(
		m_pos.x-pad,
		m_pos.y-pad,
		m_pos.x + m_width+ pad,
		m_pos.y- pad,
		m_pos.x-pad,
		m_pos.y + m_height+ pad,
		m_pos.x + m_width+ pad,
		m_pos.y + m_height+ pad,
		0, 0,
		m_width, m_height,
		m_gh,
		WHITE
	);
	//Novice::ScreenPrintf(m_pos.x + static_cast<int>(m_width / 4), m_pos.y + static_cast<int>(m_height / 4), "is selected %s", m_isSelected ? "true" : "false");
}