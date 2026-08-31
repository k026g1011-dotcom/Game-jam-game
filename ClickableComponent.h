#pragma once
#include "Vector2Int.h"
#include "Vector2.h"
#include "GameTypes.h"	
#include <string>
#include <Novice.h>
class ClickableComponent
{
public:
	ClickableComponent();
	ClickableComponent(ButtonType id, Vector2Int pos,int width,int height, int gh);
	virtual ~ClickableComponent() = default;
	ClickableComponent* GetUpNeighbor();
	ClickableComponent* GetDownNeighbor();
	ClickableComponent* GetLeftNeighbor();
	ClickableComponent* GetRightNeighbor();
	ButtonType GetId();
	bool IsIntersect(Vector2Int pos);
	void SetGh(int gh);
	void Draw();
	void SetSelected(bool value);
	bool IsSelected();
private:
	bool m_isSelected=false;
	Vector2Int m_pos;
	int m_width;
	int m_height;
	int m_gh;
	ButtonType m_id;
	ClickableComponent* m_upNeighbor=nullptr;
	ClickableComponent* m_downNeighbor = nullptr;
	ClickableComponent* m_leftNeighbor = nullptr;
	ClickableComponent* m_rightNeighbor = nullptr;
};

