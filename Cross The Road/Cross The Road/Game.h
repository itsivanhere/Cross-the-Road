#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<SFML/Window.hpp>
#include"User.h"
#include"Mobil2.h"
#include"Penghalang.h"
#include"Lawan.h"
#include"Koin1.h"
#include"Mobil1.h"
#include<ctime>
#include<vector>
#include<sstream>
#include<fstream>

class Game
{
private:
	//variablel
	sf::RenderWindow *window;
	sf::VideoMode videoMode;
	sf::Event ev;
	sf::Clock timeAnimation;
	sf::Font font;
	sf::Text textPoint;
	sf::Text highscoreText;
	sf::SoundBuffer bufferselect;
	sf::SoundBuffer buffertoingame;
	sf::Sound soundselect;
	sf::Sound soundtoingame;
	sf::Music musicMenu;
	sf::Music musicDizzy;

	float  coinSpawnTimer,coinSpawnTimerMax,powerupSpawnTimer,powerupSpawnTimerMax,enemySpawnTimer,enemySpawnTimerMax;
	int maxCoins,maxPowerup,maxEnemy,Points;

	//backgrounds
	sf::Sprite background;
	sf::Texture backgroundTexture;
	
	//mouse position
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	bool mouseheld;

	//file
	std::fstream file;

	//player
	User player;
	Sound letsgo;
	SoundBuffer bufferletsgo;
	Music musicRunning;
	int nyawa,nyawaasli;

	//coins
	std::vector<Koin1*>coins;
	Koin1* coin;

	//enemy
	std::vector<Lawan*>Enemies;
	Lawan* enemy;
	Sound mobil1Sound, mobil2Sound, penghalangSound;
	SoundBuffer bufferMobil1, bufferMobil2, bufferPenghalang;

	Time difficultyTimer;
	Clock timer;
	bool die;
	int highscore;
	
	//gui
	bool mainmenu, ingame,pause,lose,musicmenu,soundeffekt,info;
	Sprite spritestart,spritepause,spritePlayAgain,spriteBacktomenu,spriteInfo,spriteMusic,spriteSoundeffect,spriteGame;
	Texture pauseTexture,startTexture,playagainTexture,backtomenuTexture,infoTexture,musicTexture,soundeffectTexture;
	Clock pausetime;

	//coinsounds
	Sound coinSilver, coinGold, coinRuby;
	SoundBuffer bufferSilver, bufferGold, bufferRuby;

	//text info
	Text textInfo;
	std::stringstream infostring;

	//tes
	Text test;
	std::stringstream testing;

	//initializations
	void initWindow();
	void initVariables();
	void initBackground();
	void initText();
	void initGUI();
	void initSound();
	void initMusic();

public:
	Game();
	~Game();

	//PAM
	const bool isRunning()const;
	const bool isDead() const;

	//spawn
	void coinSpawn();
	void enemySpawn();

	//edit player
	void killPlayer();

	//event polling
	void pollEvents();
	
	//updates
	void update();
	void updateCoins();
	void updateText();
	void updateEnemies();
	void updateMousePosition();
	void updateGUI();

	//renders
	void render();
	void renderBackground();
	void renderCoins();
	void renderText();
	void renderEnemies();

	//save;
	void SaveHighscore();
	void LoadHighscore();
};

