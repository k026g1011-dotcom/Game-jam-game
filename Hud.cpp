#include "Hud.h"
#include "Ui.h"
#include "Game.h"
Hud::Hud()
{
	m_swapToWhiteGh= Novice::LoadTexture("./resources/images/Ui/Hud/ChangeToWhite.png");
	m_swapToRedGh = Novice::LoadTexture("./resources/images/Ui/Hud/ChangeToRed.png");
	m_swapToGreenGh = Novice::LoadTexture("./resources/images/Ui/Hud/ChangeToGreen.png");
	m_swapToBlueGh = Novice::LoadTexture("./resources/images/Ui/Hud/ChangeToBlue.png");
	m_swapColorsGh = Novice::LoadTexture("./resources/images/Ui/Hud/Swap.png");
	m_starGh = Novice::LoadTexture("./resources/images/Ui/Hud/Star.png");
	m_tokenGh = Novice::LoadTexture("./resources/images/Ui/Hud/Token.png");
	m_currentColorGh = Novice::LoadTexture("./resources/images/Ui/Hud/CurrentCollor.png");
	m_spareColorGh = Novice::LoadTexture("./resources/images/Ui/Hud/SpareCollor.png");
	m_colorsOutlineGh = Novice::LoadTexture("./resources/images/Ui/Hud/ColorsOutline.png");
	m_retryGH= Novice::LoadTexture("./resources/images/Ui/Hud/Retry.png");
	m_tutorGH = Novice::LoadTexture("./resources/images/Ui/Hud/Tutor.png");
	m_isTutorNeeded = false;
}
Hud::Hud(Game* game) :Hud()
{
	m_game = game;
}
void Hud::RequireTutor(bool value)
{
	m_isTutorNeeded = value;
}
void Hud::Update()
{

}
int Hud::GetStarGH()
{
	return m_starGh;
}
void Hud::Draw()
{
	for (int i = 0;i < m_game->GetCurrentLocation()->GetStars();i++)
	{
		Novice::DrawSprite(0 + i * 64, 0, m_starGh, 1.0f, 1.0f, 0.0f, WHITE);
	}
	for (int i = 0;i < m_game->GetCurrentLocation()->GetTokens();i++)
	{
		Novice::DrawSprite(0 + i * 64, 64, m_tokenGh, 1.0f, 1.0f, 0.0f, WHITE);
	}
	Novice::DrawSprite(0, 272, m_retryGH, 1.0f, 1.0f, 0.0f, WHITE);
	Novice::DrawSprite(0, 336, m_swapToWhiteGh, 1.0f, 1.0f, 0.0f, WHITE);
	Novice::DrawSprite(0, 400, m_swapToRedGh, 1.0f, 1.0f, 0.0f, WHITE);
	Novice::DrawSprite(0, 464, m_swapToGreenGh, 1.0f, 1.0f, 0.0f, WHITE);
	Novice::DrawSprite(0, 528, m_swapToBlueGh, 1.0f, 1.0f, 0.0f, WHITE);
	Novice::DrawSprite(0, 592, m_swapColorsGh, 1.0f, 1.0f, 0.0f, WHITE);
	Novice::DrawSprite(576, 592,m_colorsOutlineGh, 1.0f, 1.0f, 0.0f, WHITE);
	Novice::DrawSprite(576, 592, m_currentColorGh, 1.0f, 1.0f, 0.0f, m_game->GetCurrentLocation()->GetMainColor());
	Novice::DrawSprite(640, 592,m_spareColorGh, 1.0f, 1.0f, 0.0f, m_game->GetCurrentLocation()->GetSpareColor());
	if (m_isTutorNeeded)
	{
		Novice::DrawSprite(0, 0, m_tutorGH, 1.0f, 1.0f, 0.0f, WHITE);
	}
}