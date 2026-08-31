#pragma once
#include "GameTypes.h"
class Game;
class AudioPlayer
{
private:
	int m_musicSH=0;
	int m_stepsSoundSH[3];
	int m_blockSettedSH = 0;
	int m_levelClearedSH = 0;
	int m_starPickedUpSH = 0;
	int m_buttonSelected = 0;
	int m_buttonPressed = 0;
	int m_startButtonPressed = 0;
	int m_noiseBgmHS = 0;
	int m_kinescopBgmHS = 0;
	int m_currentBGMSH = 0;
	int m_currentStep = 0;
	int m_twistedMetal = 0;
	Game* m_game = nullptr;
public:
	AudioPlayer(Game* game);
	void Play(Music sound);
	void PlayBGM();
	void StopBGM();
	void SetBGM(Music sound);
};

