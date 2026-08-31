#include "AudioPlayer.h"
#include <Novice.h>
AudioPlayer::AudioPlayer(Game* game)
{
	m_game = game;
	//m_blockSettedSH= Novice::LoadAudio("./resources/sounds/blockSetted.mp3");
	//m_starPickedUpSH= Novice::LoadAudio("./resources/sounds/blockSetted.mp3");
	//m_buttonPressed= Novice::LoadAudio("./resources/sounds/blockSetted.mp3");
	m_stepsSoundSH[0] = Novice::LoadAudio("./resources/sounds/footStep1.mp3");
	m_stepsSoundSH[1] = Novice::LoadAudio("./resources/sounds/footStep2.mp3");
	m_stepsSoundSH[2] = Novice::LoadAudio("./resources/sounds/footStep3.mp3");
	m_twistedMetal= Novice::LoadAudio("./resources/sounds/twistedMetal.mp3");
	m_blockSettedSH= Novice::LoadAudio("./resources/sounds/blockSetted.mp3");
	m_starPickedUpSH = Novice::LoadAudio("./resources/sounds/starPickedUp.mp3");
	m_noiseBgmHS= Novice::LoadAudio("./resources/sounds/noiseBGM.mp3");
	m_kinescopBgmHS = Novice::LoadAudio("./resources/sounds/kinescopBGM.mp3");
	m_levelClearedSH = Novice::LoadAudio("./resources/sounds/cleared.mp3");
	m_buttonSelected= Novice::LoadAudio("./resources/sounds/buttonSelected.mp3");
	m_buttonPressed= Novice::LoadAudio("./resources/sounds/buttonPressed.mp3");
	m_startButtonPressed= Novice::LoadAudio("./resources/sounds/startButtonPressed.mp3");

}
void AudioPlayer::Play(Music sound)
{
	switch (sound)
	{
	case Music::StepsSound:
		m_currentStep = (m_currentStep + 1) % 3;
		Novice::PlayAudio(m_stepsSoundSH[m_currentStep], false, 0.5f);
		break;
	case Music::TwistedMetal:
		Novice::PlayAudio(m_twistedMetal, false, 0.5f);
		break;
	case Music::BlockSetted:
		Novice::PlayAudio(m_blockSettedSH, false, 0.5f);
		break;
	case Music::StarPickedUp:
		Novice::PlayAudio(m_starPickedUpSH, false, 0.5f);
		break;
	case Music::Cleared:
		Novice::PlayAudio(m_levelClearedSH, false, 0.5f);
		break;
	case Music::ButtonSelected:
		Novice::PlayAudio(m_buttonSelected, false, 0.5f);
		break;
	case Music::Button:
		Novice::PlayAudio(m_buttonPressed, false, 0.5f);
		break;
	case Music::StartButton:
		Novice::PlayAudio(m_startButtonPressed, false, 0.5f);
		break;
	}
	
}
void AudioPlayer::PlayBGM()
{
	if (!Novice::IsPlayingAudio(m_musicSH))
	{
		m_musicSH=Novice::PlayAudio(m_currentBGMSH, true, 0.5f);
	}
	
}
void AudioPlayer::StopBGM()
{
	Novice::StopAudio(m_musicSH);
}
void AudioPlayer::SetBGM(Music sound)
{
	switch(sound)
	{
	case Music::NoiseBGM:
		m_currentBGMSH = m_noiseBgmHS;
		break;
	case Music::KinescopBGM:
		m_currentBGMSH = m_kinescopBgmHS;
		break;
	default:
		StopBGM();
		break;
	}

}