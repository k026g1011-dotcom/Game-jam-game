#pragma once
#include "GameMenu.h"
#include "LevelSelectMenu.h"
#include "TitleMenu.h"
#include "ClearMenu.h"
#include "Hud.h"
class Game;
class Ui
{
public:
	Ui();
	Ui(Game* game);
	void Update();
	void Draw();
	void ShowTitleMenu();
	void ShowLevelSelectMenu();
	void CloseCurrentMenu();
	void ShowClearMenu(int value);
	Game* GetGame();
	GameMenu* GetCurrentMenu();
	void RequireTutor(bool value);
	Hud* GetHud();
private:
	LevelSelectMenu m_levelSelectMenu;
	TitleMenu m_titleMenu;
	ClearMenu m_clearMenu;
	GameMenu* m_currentMenu=nullptr;
	Game* m_game = nullptr;

	Hud m_hud;
};

