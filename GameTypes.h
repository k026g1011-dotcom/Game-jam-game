#pragma once
enum class Music
{
	NoiseBGM,
	KinescopBGM,
	StepsSound,
	TwistedMetal,
	BlockSetted,
	StarPickedUp,
	Cleared,
	StartButton,
	TurnOffButton,
	Button,
	ButtonSelected
};
enum class Animations
{
	PlayerIdle,
	PlayerWalk,
	PlayerPush,
	BlockIdle,
	StarIdle,
	None
};
enum class ButtonType
{
	StartButton,
	BackButton,
	FirstStageButton,
	SecondStageButton,
	ThirdStageButton,
	FourthStageButton,
	FifthStageButton,
	TitleButton,
	CreditsButton,
	BackFromCreditsButton,
	None
};
enum class TileType
{
	Wall,
	Floor,
	Base,
	None
};
enum class Directions
{
	Up,
	Right,
	Down,
	Left
};
enum class BlockTypes
{
	Red,
	Green,
	Blue,
	Count
};