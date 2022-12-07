#include "Game.h"


void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 300;
	this->window = new sf::RenderWindow(this->videoMode, "Cross The Road", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

void Game::initVariables()
{
	//coins
	coinSpawnTimerMax = 80.f;
	coinSpawnTimer = 0;
	maxCoins = 4;

	//points
	Points = 0;
	highscore = 0;
	
	//player
	die = 0; nyawaasli = 1; nyawa = nyawaasli;

	//enemy
	enemySpawnTimerMax = 70.f;
	enemySpawnTimer = 0;
	maxEnemy = 3;

	//menus
	mainmenu = 1;
	ingame = 0;
	pause = 0;
	lose = 0;

	//soundsbool
	musicmenu = 1;
	soundeffekt = 1;

	//mouse
	mouseheld = 0;

	//timer
	difficultyTimer = seconds(0);
}

void Game::initBackground()
{
	backgroundTexture.loadFromFile("images/background1.png");
	background.setTexture(backgroundTexture);
}

void Game::initText()
{
	(font.loadFromFile("fonts/Sandy House.ttf"));
	textPoint.setFont(font);
	textPoint.setOutlineColor(Color::Black);
	textPoint.setOutlineThickness(3.f);
	textPoint.setCharacterSize(40);
	textPoint.setPosition(10.f, 5.f);
	highscoreText.setFont(font);
	highscoreText.setOutlineColor(Color::Black);
	highscoreText.setOutlineThickness(3.f);
	highscoreText.setCharacterSize(35);
	highscoreText.setPosition(10.f, 35.f);
	LoadHighscore();
}

void Game::initGUI()
{
	startTexture.loadFromFile("images/play.png");
	spritestart.setTexture(startTexture);
	pauseTexture.loadFromFile("images/pause.png");
	spritepause.setTexture(pauseTexture);
	spritestart.setScale(0.400f, 0.400f);
	spritepause.setScale(0.150f, 0.150f);
	spritestart.setPosition(100.f, 375.f);
	spritepause.setPosition(240.f, 10.f);
	playagainTexture.loadFromFile("images/play.png");
	backtomenuTexture.loadFromFile("images/back.png");
	spritePlayAgain.setTexture(playagainTexture);
	spriteBacktomenu.setTexture(backtomenuTexture);
	spritePlayAgain.setScale(0.250f, 0.250f);
	spriteBacktomenu.setScale(0.200f, 0.220f);
	spritePlayAgain.setPosition(90.f, 450.f);
	spriteBacktomenu.setPosition(220.f, 520.f);
}

void Game::initSound()
{
	bufferselect.loadFromFile("sound effect/button1.ogg");
	soundselect.setBuffer(bufferselect);
	buffertoingame.loadFromFile("sound effect/button2.ogg");
	soundtoingame.setBuffer(buffertoingame);

	//coins
	bufferSilver.loadFromFile("sound effect/on.ogg");
	coinSilver.setBuffer(bufferSilver);
	coinSilver.setVolume(40);

	//enemy
	bufferMobil1.loadFromFile("sound effect/mobil1.wav");
	bufferPenghalang.loadFromFile("sound effect/penghalang.wav");
	bufferMobil2.loadFromFile("sound effect/mobil2.wav");
	mobil1Sound.setBuffer(bufferMobil1);
	mobil2Sound.setBuffer(bufferPenghalang);
	penghalangSound.setBuffer(bufferMobil2);
}

void Game::initMusic()
{
	musicMenu.openFromFile("sound effect/menu.wav");
	musicMenu.setLoop(true);
	musicMenu.setVolume(10);
	musicMenu.setLoopPoints(Music::TimeSpan(seconds(10), seconds(52)));
	musicRunning.openFromFile("sound effect/ingame.wav");
	musicRunning.setLoop(true);
	musicRunning.setVolume(10);
	musicDizzy.openFromFile("sound effect/complete.ogg");
	musicDizzy.setLoop(1);
}

Game::Game()
{
	this->initWindow();
	this->initBackground();
	this->initVariables();
	this->initText();
	this->initGUI();
	this->initSound();
	this->initMusic();
	this->musicMenu.play();
	std::cout << "Cross The Road Is Running!\n\n";
	std::cout << "Petunjuk untuk menggerakkan Player:\n";
	std::cout << "W - Arah Atas\n";
	std::cout << "A - Arah Kiri\n";
	std::cout << "S - Arah Bawah\n";
	std::cout << "D - Arah Kanan\n\n\n";
	std::cout << "Nama Kelompok:\n";
	std::cout << "Hugo Oliviera    - C14190075\n";
	std::cout << "Ivan Christopher - C14190193\n";
	std::cout << "Kevin Jonathan   - C14190207\n";
	std::cout << "Michael Albert   - C14190192\n";
}

Game::~Game()
{
	delete this->window;
	for (auto p : coins) {
		delete p;
	}
	for (auto e : Enemies)
	{
		delete e;
	}
}

const bool Game::isRunning() const
{
	return this->window->isOpen();
}

const bool Game::isDead() const
{
	return die;
}

void Game::coinSpawn()                                 
{
	if (!die) {
		if (coins.size() < maxCoins) {
			if (coinSpawnTimer > coinSpawnTimerMax) {
				coinSpawnTimer = 10.f;
				int type = rand() % 7;
				switch (type)
				{
				default:
					coin = new Koin1;
					coins.push_back(coin);
					break;
				}
			}
			else {
				coinSpawnTimer += 2.5f;
			}
		}
	}
}

// menentukan waktu muncul enemy dengan cara random
void Game::enemySpawn(){										
	if (!die) {
		if (Enemies.size() < maxEnemy) {
			if (enemySpawnTimer >= enemySpawnTimerMax) {
				enemySpawnTimer = 2.5f;
				int type = rand() % 4;
				switch (type)
				{
				case 0:
					enemy = new Mobil2;
					Enemies.push_back(enemy);
					enemy = new Mobil2;
					Enemies.push_back(enemy);
					break;
				case 1:
					enemy = new Mobil1;
					Enemies.push_back(enemy);
					enemy = new Mobil1;
					Enemies.push_back(enemy);
					enemy = new Mobil1;
					Enemies.push_back(enemy);

					break;
				case 2:
					enemy = new Penghalang;
					Enemies.push_back(enemy);
					break;

				default:
					break;
				}
			}
			else {
				enemySpawnTimer += 5.f;
			}
		}
	}
}

void Game::killPlayer()
{
	for (auto e : coins) {
		e->setDirection(0.f, 0.f);
	}
	
	player.getTexture().loadFromFile("images/dead.png");
	player.getIntRect().height = 641;
	player.getIntRect().left = 0;
	player.getIntRect().top = 0;
	player.getIntRect().width = 934;
	player.setMaxSize(14944);
	player.setplusWidth(934);
	player.getSprite().setTexture(player.getTexture());
	die = 1;
	musicRunning.stop();
}

void Game::update()
{
	this->pollEvents();

	//updates

	if (ingame) {
		player.update(die);
		updateCoins();
		updateText();
		updateEnemies();
	}
	if (mainmenu) {
		player.update(die);
		if (player.getSprite().getPosition().x != 70.f) {
			player.getSprite().setPosition(70.f, 180.f);
		}
		updateCoins();
		updateText();
		updateEnemies();
		timer.restart();
	}
	if (info) {
		player.update(die);
		updateCoins();
		updateText();
		updateEnemies();
	}
	if (lose) {
		
		player.update(die);
		player.getSprite().setPosition(0.f, 200.f);
		updateCoins();
		updateText();
		updateEnemies();
	}
	if (pause) {
		timer.restart();
	}
	updateGUI();
	updateMousePosition();

}

// update dari koin yang di dapatkan
void Game::updateCoins() 
{
	coinSpawn();
	for (auto e : coins)
	{
		e->update(die);
	}
	for (int i = 0; i < coins.size(); i++)
	{
		if (coins[i]->getSprite().getPosition().y > this->window->getSize().y) {
			coins.erase(coins.begin() + i);
		}
	}
	if (ingame) {
		for (int i = 0; i < coins.size(); i++)
		{
			if (player.getSprite().getGlobalBounds().intersects(coins[i]->getSprite().getGlobalBounds())) {
				switch (coins[i]->getType())
				{
				case 0:
					if (soundeffekt) {
						coinSilver.play();
					}
					Points += 1;
					coins.erase(coins.begin() + i);
					break;
				default:
					break;
				}
			}
		}
		if (Points > highscore) {
			highscore = Points;
			SaveHighscore();
		}
	}
}
void Game::updateText()
{
	// penulisan jumlah poin
	std::stringstream ss;
	ss << "Points : " << this->Points;         
	textPoint.setString(ss.str());
	ss.str("");
	ss << "Highscore: " << highscore;
	highscoreText.setString(ss.str());

	ss.str("");
}
void Game::updateEnemies()
{
	
	if (timer.getElapsedTime().asSeconds() >= 1) {
		difficultyTimer = difficultyTimer + seconds(1);
		timer.restart();
	}
	if (difficultyTimer.asSeconds() > 180) {
		maxEnemy = 5; 
	}
	else if (difficultyTimer.asSeconds() > 120.f) {
		maxEnemy = 4;
	}
	if (difficultyTimer.asSeconds() > 50.f)
	{
		 enemySpawnTimerMax = 20.f;
	}
	else if (difficultyTimer.asSeconds() > 30.f) {
		enemySpawnTimerMax = 20.f;
	}
	enemySpawn();
	for (auto e : Enemies)
	{
		e->update(die);
	}
	for (int i = 0; i < Enemies.size(); i++)
	{
		if (Enemies[i]->getSprite().getPosition().y > this->window->getSize().y) {
			Enemies.erase(Enemies.begin() + i);
		}
	}
	for (int i = 0; i < Enemies.size(); i++)
	{
		if (!mainmenu&&!info) {
			if (player.getSprite().getPosition().y - Enemies[i]->getSprite().getPosition().y < 50 
				&& player.getSprite().getGlobalBounds().intersects(Enemies[i]->getSprite().getGlobalBounds())
				&& player.getSprite().getPosition().y>Enemies[i]->getSprite().getPosition().y 
				&& Enemies[i]->getSprite().getPosition().x < player.getSprite().getPosition().x + 30.f
				) {
				switch (Enemies[i]->getType())
				{
				case 0:
					if (soundeffekt) {
						mobil1Sound.play();
					}
					break;
				case 1:
					if (soundeffekt) {
						mobil2Sound.play();
					}
					break;
				case 2:
					if (soundeffekt) {
						penghalangSound.play();
					}
					break;
				default:
					break;
				}
				Enemies.erase(Enemies.begin() + i);
				nyawa--;
				if (nyawa <= 0) {
					killPlayer();
					
					if (soundeffekt) {
						musicDizzy.play();
					}
					lose = 1;
					ingame = 0;
					player.getSprite().setScale(0.300f, 0.300f);
					player.getSprite().setPosition(100.f, 355.f);
					textPoint.setScale(2.f, 2.f);
					textPoint.setPosition(40.f, 100.f);
					spriteBacktomenu.setPosition(180.f, 450.f);
				}
			}
		}
	}
}
void Game::updateMousePosition()
{
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}
void Game::updateGUI()
{
	if (mainmenu) {
		if (Mouse::isButtonPressed(Mouse::Left)) {
			if (!mouseheld) {
				mouseheld = 1;
				if (spritestart.getGlobalBounds().contains(mousePosView)) {
					nyawa = nyawaasli;
					difficultyTimer = seconds(0);
					spritestart.setPosition(100.f, 225.f);
					if (soundeffekt) {
						musicRunning.play();
						soundtoingame.play();
						letsgo.play();
					}
					ingame = 1;
					mainmenu = 0;
					Points = 0;
					lose = 0;
					die = 0;
					player.getSprite().setPosition(60.f, 600.f - 100.5f);
					player.getSprite().setScale(0.123f, 0.123f);
					player.getTexture().loadFromFile("images/run.png");
					player.getIntRect().height = 643;
					player.getIntRect().left = 0;
					player.getIntRect().top = 0;
					player.getIntRect().width = 936;
					player.setMaxSize(9338);
					player.setplusWidth(936);
					player.getSprite().setTexture(player.getTexture());
					textPoint.setScale(1.f, 1.f);
					textPoint.setPosition(10.f, 5.f);
					this->Enemies.clear();
					this->coins.clear();
				}
			}
		}
		else {
			mouseheld = 0;
		}
	}
	if (ingame) {
		if (Mouse::isButtonPressed(Mouse::Left)) {
			if (!mouseheld) {
				mouseheld = 1;
				if (spritepause.getGlobalBounds().contains(mousePosView)) {
					if (soundeffekt) {
						soundselect.play();
						musicRunning.stop();
					}
					ingame = 0;
					pause = 1;
					pausetime.restart();
					spriteBacktomenu.setPosition(240.f, 540.f);
				}
			}
		}
		else {
			mouseheld = 0;
		}
	}
	if (pause) {
		if (Mouse::isButtonPressed(Mouse::Left)) {
			if (!mouseheld) {
				mouseheld = 1;
				if (spritestart.getGlobalBounds().contains(mousePosView)) {
					if (soundeffekt) {
						soundselect.play();
						musicRunning.play();
					}
					ingame = 1;
					pause = 0;
				}
				if (spriteBacktomenu.getGlobalBounds().contains(mousePosView)) {
					difficultyTimer = seconds(0);
					if (musicmenu) {
						musicMenu.stop();
					}
					if (musicmenu) {
						musicMenu.play();
					}
					if (soundeffekt) {
						soundselect.play();
					}
					spritestart.setPosition(100.f, 375.f);
					mainmenu = 1;
					Points = 0;
					lose = 0;
					pause = 0;
					die = 0;
					player.getSprite().setPosition(100.f, 225.f);
					player.getSprite().setScale(0.21f, 0.2f);
					player.getTexture().loadFromFile("images/spritesheet.png");
					player.getIntRect().height = 643;
					player.getIntRect().left = 0;
					player.getIntRect().top = 0;
					player.getIntRect().width = 936;
					player.setMaxSize(14040);
					player.setplusWidth(936);
					player.getSprite().setTexture(player.getTexture());
					textPoint.setScale(1.f, 1.f);
					textPoint.setPosition(10.f, 5.f);
					this->Enemies.clear();
					this->coins.clear();
				}
			}
		}
		else {
			mouseheld = 0;
		}
	}
	if (lose) {
		if (Mouse::isButtonPressed(Mouse::Left)) {
			if (!mouseheld) {
				mouseheld = 1;
				if (spritePlayAgain.getGlobalBounds().contains(mousePosView)) {
					nyawa = nyawaasli;
					difficultyTimer = seconds(0);
					if (soundeffekt) {
						soundtoingame.play(); letsgo.play(); musicRunning.play();
						musicDizzy.stop();
					}
					ingame = 1;
					mainmenu = 0;
					Points = 0;
					lose = 0;
					die = 0;
					player.getSprite().setPosition(60.f, 600.f - 100.5f);
					player.getSprite().setScale(0.123f, 0.123f);
					player.getTexture().loadFromFile("images/run.png");
					player.getIntRect().height = 643;
					player.getIntRect().left = 0;
					player.getIntRect().top = 0;
					player.getIntRect().width = 936;
					player.setMaxSize(9338);
					player.setplusWidth(936);
					player.getSprite().setTexture(player.getTexture());
					textPoint.setScale(1.f, 1.f);
					textPoint.setPosition(10.f, 5.f);
					this->Enemies.clear();
					this->coins.clear();
				}
				if (spriteBacktomenu.getGlobalBounds().contains(mousePosView)) {
					if (musicmenu) {
						musicMenu.stop();
					}
					if (musicmenu) {
						musicMenu.play();
					}
					if (soundeffekt) {
						soundselect.play(); musicDizzy.stop();
					}
					difficultyTimer = seconds(0);
					spritestart.setPosition(100.f, 375.f);
					mainmenu = 1;
					Points = 0;
					lose = 0;
					die = 0;
					player.getSprite().setPosition(100.f, 225.f);
					player.getSprite().setScale(0.21f, 0.2f);
					player.getTexture().loadFromFile("images/spritesheet.png");
					player.getIntRect().height = 643;
					player.getIntRect().left = 0;
					player.getIntRect().top = 0;
					player.getIntRect().width = 936;
					player.setMaxSize(14040);
					player.setplusWidth(936);
					player.getSprite().setTexture(player.getTexture());
					textPoint.setScale(1.f, 1.f);
					textPoint.setPosition(10.f, 5.f);
					this->Enemies.clear();
					this->coins.clear();
				}
			}
		}
		else {
			mouseheld = 0;
		}
	}
	if (info) {
		if (Mouse::isButtonPressed(Mouse::Left)) {
			if (!mouseheld) {
				mouseheld = 1;
				if (spriteBacktomenu.getGlobalBounds().contains(mousePosView)) {
					if (soundeffekt) {
						soundselect.play();
					}
					info = 0;
					mainmenu = 1;
					spriteBacktomenu.setPosition(240.f, 540.f);
				}
			}
		}
		else {
			mouseheld = 0;
		}
	}
}
void Game::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type) {
		case sf::Event::Closed:
			this->window->close();
			break;
		}
	}
}
void Game::render()
{
	this->window->clear();
	renderBackground();
	//render game
	if (ingame) {
		renderCoins();
		renderEnemies();
		player.render(*this->window);
		window->draw(this->spritepause);
		renderText();
	}
	if (mainmenu) {
		renderCoins();
		renderEnemies();
		player.render(*this->window);
		window->draw(this->spritestart);
		window->draw(this->spriteInfo);
		window->draw(this->spriteMusic);
		window->draw(this->spriteSoundeffect);
		window->draw(this->spriteGame);
	}
	if (lose) {
		renderCoins();
		renderEnemies();
		player.render(*this->window);
		renderText();
		window->draw(this->spriteBacktomenu);
		window->draw(this->spritePlayAgain);
	}
	if (pause) {
		renderCoins();
		renderEnemies();
		player.render(*this->window);
		window->draw(this->spriteBacktomenu);
		window->draw(this->spritestart);
		window->draw(this->spriteMusic);
		window->draw(this->spriteSoundeffect);
	}
	if (info) {
		renderCoins();
		renderEnemies();
		window->draw(textInfo);
		window->draw(spriteBacktomenu);
	}
	this->window->display();
}

void Game::renderBackground()
{
	this->window->draw(background);
}

void Game::renderCoins()
{
	for (auto e : coins)
	{
		e->render(*this->window);
	}
}

void Game::renderText()
{
	this->window->draw(textPoint);
	this->window->draw(highscoreText);
}

void Game::renderEnemies()
{
	for (auto e : Enemies)
	{
		e->render(*this->window);
	}
}

void Game::SaveHighscore()
{
	file.open("score/highscore.txt", std::ios::out);
	file << highscore;
	file.close();
}

void Game::LoadHighscore()
{
	file.open("score/highscore.txt", std::ios::in);
	file >> highscore;
	file.close();
}