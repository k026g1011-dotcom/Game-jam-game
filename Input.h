#pragma once
class Game;
class Input
{
public:
	Input();
	Input(Game* game, char(&keysArg)[256], char(&preKeysArg)[256]);
	void Update();
private:
	Game* m_game=nullptr;
	char* m_keys = nullptr;
	char* m_preKeys = nullptr;
};

