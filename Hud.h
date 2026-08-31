#pragma once
class Game;
class Hud
{
public:
	Hud();
	Hud(Game* game);
	void RequireTutor(bool value);
	void Update();
	void Draw();
	int GetStarGH();
private:
	Game* m_game;
	int m_swapToWhiteGh;
	int m_swapToRedGh;
	int m_swapToGreenGh;
	int m_swapToBlueGh;
	int m_swapColorsGh;
	int m_starGh;
	int m_tokenGh;
	int m_currentColorGh;
	int m_spareColorGh;
	int m_colorsOutlineGh;
	int m_retryGH;
	int m_tutorGH;
	bool m_isTutorNeeded;
};

