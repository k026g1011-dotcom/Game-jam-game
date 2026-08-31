#include "GameMenu.h"
#include <Novice.h>
#include "Game.h"
GameMenu::GameMenu()
{
	m_backGroundGh = 0;
}
GameMenu::GameMenu(Game* game)
{
	m_backGroundGh = 0;
	m_game = game;
}
void GameMenu::SetBackGroundGh(int gh)
{
	m_backGroundGh = gh;
}
void GameMenu::CloseMenu()
{
	m_game->GetUi()->CloseCurrentMenu();
}
void GameMenu::ClickReceived()
{

}

void GameMenu::ToUpNeighbor()
{
	if (m_selectedButton != nullptr)
	{
		if (m_selectedButton->GetUpNeighbor() != nullptr)
		{
			m_selectedButton = m_selectedButton->GetUpNeighbor();
		}
	}
	else
	{
		m_selectedButton = m_clickableComponents[0];
	}
}
void GameMenu::ToDownNeighbor()
{
	if (m_selectedButton != nullptr)
	{
		if (m_selectedButton->GetDownNeighbor() != nullptr)
		{
			m_selectedButton = m_selectedButton->GetDownNeighbor();
		}
	}
	else
	{
		m_selectedButton = m_clickableComponents[0];
	}
}
void GameMenu::ToLeftNeighbor()
{
	if (m_selectedButton != nullptr)
	{
		if (m_selectedButton->GetLeftNeighbor() != nullptr)
		{
			m_selectedButton = m_selectedButton->GetLeftNeighbor();
		}
	}
	else
	{
		m_selectedButton = m_clickableComponents[0];
	}
}
void GameMenu::ToRightNeighbor()
{
	if (m_selectedButton != nullptr)
	{
		if (m_selectedButton->GetRightNeighbor() != nullptr)
		{
			m_selectedButton = m_selectedButton->GetRightNeighbor();
		}
	}
	else
	{
		m_selectedButton = m_clickableComponents[0];
	}
}
ClickableComponent* GameMenu::GetSelectedButton()
{
	return m_selectedButton;
}
void GameMenu::SetSelectedButton(ClickableComponent* button)
{
	m_selectedButton = button;
}
Game* GameMenu::GetGame()
{
	return m_game;
}
void GameMenu::Update()
{
	int mouseX;
	int mouseY;
	Novice::GetMousePosition(&mouseX, &mouseY);
	for (auto& clickableComponent : m_clickableComponents)
	{
		if (clickableComponent != nullptr)
		{
			if(clickableComponent->IsIntersect(Vector2Int(mouseX, mouseY)))
			{
				m_selectedButton=clickableComponent;
				if(!clickableComponent->IsSelected())
				{
					m_game->GetAudioPlayer()->Play(Music::ButtonSelected);
					clickableComponent->SetSelected(true);
				}

				return;
			}
			else
			{
				m_selectedButton = nullptr;
				clickableComponent->SetSelected(false);
			}
		}
	}
	
}
void GameMenu::RegisterComponents()
{
	m_clickableComponents.clear();
}
void GameMenu::Draw()
{
	
	Novice::DrawSprite(0, 0, m_backGroundGh, 1.0f, 1.0f, 0.0f, WHITE);
	//Novice::ScreenPrintf(900, 15, "clickableComponents amount: %d", m_clickableComponents.size());
	for (auto& clickableComponent : m_clickableComponents)
	{
		if (clickableComponent != nullptr)
		{
			clickableComponent->Draw();
		}
	}
}
void GameMenu::RegisterClickableComponent(ClickableComponent* component)
{
	m_clickableComponents.push_back(component);
}
//Novice::ConsolePrintf("Adding clickable Component %d to list",static_cast<int>(component->GetId()));