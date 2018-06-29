#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Entity.h"
#include "Bullet.h"
#include <vector>
#include <ostream>
#include "Fighter.h"
#include <string>
#include "Explosion.h"
#include "Powerups.h"
#include "Nscorepowerup.h"
#include "Scorepowerup.h"

using namespace std;

int main()
{
	//Variables
	int counter = 0;
	int counter1 = 0;
	int counter2 = 0;
	int counter3 = 0;


	//CLOCKS AND TIMERS
	sf::Clock clock;
	sf::Clock clock2;
	sf::Clock enemySpawnClock;
	sf::Clock clock3;
	sf::Clock clockpowerup;

	//Window
	sf::RenderWindow window(sf::VideoMode(1200, 700), "Testing");
	window.setKeyRepeatEnabled(false);
	window.setTitle("SFML SHTU-Game-ProgrammingAssignment");

	//Load Background texture
	sf::Texture BackgroundTexture;
	if (!BackgroundTexture.loadFromFile("Background.png"))
		std::cout << "Texture Error" << std::endl;
	sf::Sprite background(BackgroundTexture);
	background.setScale(3.0f, 2.0f);
	//background.setRotation(90);

	//Load Player Texture
	sf::Texture PlayerTexture;
	if (!PlayerTexture.loadFromFile("SpriteShip.png"))
		std::cout << "Texture Error" << std::endl;

	//Load Bullet Texture
	sf::Texture BulletTexture;
	if (!BulletTexture.loadFromFile("Bullet.png"))
		std::cout << "Texture Error" << std::endl;

	//Load Fighter Texture 
	sf::Texture FighterTexture;
	if (!FighterTexture.loadFromFile("alien.png"))
		std::cout << "Texture Error" << std::endl;

	//Load explosion Texture
	sf::Texture ExplosionTexture;
	if (!ExplosionTexture.loadFromFile("explosion_5.png"))
		std::cout << "Texture Error" << std::endl;

	//Load coin texture
	sf::Texture Cointexture;
	if (!Cointexture.loadFromFile("coinsprite.png"))
		std::cout << "Texture Error" << std::endl;

	//Load mine texture
	sf::Texture MineTexture;
	if (!MineTexture.loadFromFile("spacestation.png"))
		std::cout << "Texture Error" << std::endl;
	//Load Font
	sf::Font Font;
	if (!Font.loadFromFile("ARIAL.TTF"))
		std::cout << "Texture Error FONT" << std::endl;
	

	//Create Player
	class Player Player1;

	//Create bullets
	//Playerbullets
	class Bullet bullet1(BulletTexture, 1, false);
	class Bullet bullet2(BulletTexture, 2, false);
	class Bullet bullet3(BulletTexture, 3, false);
	class Bullet enemybullet(BulletTexture, 4, true);

	//Create Fighter
	class Fighter Fighter1;

	//LoadTexturesToObjects
	Player1._Sprite.setTexture(PlayerTexture); //Player
	Fighter1._Sprite.setTexture(FighterTexture); //Fighter

	//Load Font to text object
	Player1._Text.setFont(Font);
	Player1._Text2.setFont(Font);
	

	//Create player bullet vectors
	vector<Bullet>::const_iterator iter;
	vector<Bullet> bulletArray;

	//Create Fighter vectors
	vector<Fighter>::const_iterator iter1;
	vector<Fighter> fighterArray;

	//TESTBULLETARRAY
	vector<Bullet>::const_iterator iter3;
	vector<Bullet> TESTbulletArray;

	//EXPLOASIONVECTOR
	vector<Explosion>::const_iterator iterexp;
	vector<Explosion> Explosionvector;

	typedef std::vector<Powerups*> powerupvector;
	powerupvector powerups1;

	// Local variables for position of player
	int pposx;
	int pposy;
	sf::FloatRect globalbounds;
	//Local score variable
	int score;

	//Game Loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				window.close();
		}
		window.clear(); //Clear Window

		//Give value to local variables for player position
		globalbounds = Player1._Sprite.getGlobalBounds();
		pposx = Player1._Sprite.getPosition().x;
		pposy = Player1._Sprite.getPosition().y;

		//TIMERS
		sf::Time elapsed1 = clock.getElapsedTime();
		sf::Time elapsed2 = clock2.getElapsedTime();
		sf::Time Framerate = clock3.getElapsedTime();
		sf::Time elapsedSpawn = enemySpawnClock.getElapsedTime();
		sf::Time poweruptime = clockpowerup.getElapsedTime();

		//DELETE OBJECTS 
		counter = 0;
		for (iter = bulletArray.begin(); iter != bulletArray.end(); iter++) {
			if (bulletArray[counter].checkColl(window.getSize().x, window.getSize().y) == true || bulletArray[counter].destroy == true) {
				bulletArray.erase(iter);
				break;
			}
			counter++;
		}
		
		counter = 0;
		for (iter1 = fighterArray.begin(); iter1 != fighterArray.end(); iter1++) {
			if (fighterArray[counter].Destroy(window.getSize().x, window.getSize().y) == true || fighterArray[counter].dead == true) {
				Explosionvector.push_back(Explosion(fighterArray[counter]._Sprite.getPosition().x, fighterArray[counter]._Sprite.getPosition().y, ExplosionTexture));
				fighterArray.erase(iter1);
				break;
			}
			counter++;
		}

		//PLAYER MOVEMENT------------------------------------------------
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { //Move Up
			Player1.moveUp();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { //Move Down
			Player1.moveDown(window.getSize().y);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { //Move Right
			Player1.moveRight(window.getSize().x);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { //Move Left
			Player1.moveLeft();
		}

		//firebutton
		if (elapsed1.asSeconds() >= Player1.attackSpeed)
		{
			clock.restart();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				if (bulletArray.size()) {
					//bullet1.dir(Player1, bullet1); // Update directions of bullets for different directions (Uncomment in bullet.h and in bullet.cpp file )
					bullet1.fire(pposx, pposy);
					bulletArray.push_back(bullet1);
					bullet2.fire1(pposx, pposy);
					bulletArray.push_back(bullet2);
					bullet3.fire2(pposx, pposy);
					bulletArray.push_back(bullet3);
				}
			}
		}

		//Player SPRINT
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
			Player1.setSpeed(0.15);
		}
		else {
			Player1.setSpeed(0.10);
		}
		//End player movement----------------------------------------------

		//POWERUPS
		if (poweruptime.asSeconds() >= 1) {
			clockpowerup.restart();
			powerups1.push_back(new Nscorepowerup(MineTexture));
			powerups1.push_back(new Scorepowerup(Cointexture));
		}

		//ENEMY------------------------------------------------------------
		//Enemy spawns
		if (elapsedSpawn.asSeconds() >= 3) {
			if (fighterArray.size() <= 3) {
				Fighter1.randomnspawnerEnemies();
				fighterArray.push_back(Fighter1);
			}
			enemySpawnClock.restart();
		}

		//Enemy bullets
		if (elapsed2.asSeconds() >= Fighter1.attackSpeed)
		{
			clock2.restart();
			counter = 0;
			for (iter1 = fighterArray.begin(); iter1 != fighterArray.end(); iter1++) {
				enemybullet.enemyfire(fighterArray[counter]._Sprite.getPosition().x, fighterArray[counter]._Sprite.getPosition().y);
				bulletArray.push_back(enemybullet);
				counter++;
			}
		}

		//COLLISIONS ---------------------------------------------------------------------------------------------------------------------------
		//Player Bullets Collide With Fighter
		if (Framerate.asMilliseconds() >= 30) {
			if (Framerate.asMilliseconds() >= 1) {
				clock3.restart();
				counter = 0;
				for (iter = bulletArray.begin(); iter != bulletArray.end(); iter++)
				{
					counter1 = 0;
					if (!bulletArray[counter].Enemybullet) {
						for (iter1 = fighterArray.begin(); iter1 != fighterArray.end(); iter1++) {
							if (bulletArray[counter]._Sprite.getGlobalBounds().intersects(fighterArray[counter1]._Sprite.getGlobalBounds())) {
								bulletArray[counter].destroy = true;
								fighterArray[counter1].dead = true;
								Player1.setTextObjectsScore(1);
								break;
							}
							counter1++;
						}
					}
					counter++;
				}
			}

			//Enemy Bullets Collide With Player
			if (Framerate.asMilliseconds() >= 1) {
				clock3.restart();
				counter = 0;
				for (iter = bulletArray.begin(); iter != bulletArray.end(); iter++)
				{
					if (bulletArray[counter].Enemybullet) {
						if (bulletArray[counter]._Sprite.getGlobalBounds().intersects(globalbounds)) {
							bulletArray[counter].destroy = true;
							Player1.setTextObjectsHealth(1);
							break;
						}
					}
					counter++;
				}
			}

			//Player collides with fighter
			if (Framerate.asMilliseconds() >= 1) {
				clock3.restart();
				counter = 0;
				for (iter1 = fighterArray.begin(); iter1 != fighterArray.end(); iter1++) {
					if (fighterArray[counter]._Sprite.getGlobalBounds().intersects(Player1._Sprite.getGlobalBounds())) {
						fighterArray[counter].dead = true;
						Player1.setTextObjectsHealth(0);
						Explosionvector.push_back(Explosion(fighterArray[counter]._Sprite.getPosition().x, fighterArray[counter]._Sprite.getPosition().y, ExplosionTexture));
						break;
					}
					counter++;
				}
			}
		}

		//if player is dead
		if (Player1.hp <= 0) {
			window.close();
		}

		//Draw objects-----------------------------------------------------
		window.draw(background);
		//Draw bullets-----------------------------------------------------
		counter = 0;
		for (iter = bulletArray.begin(); iter != bulletArray.end(); iter++)
		{
			if (!bulletArray[counter].Enemybullet) {
				bulletArray[counter].updateDir(Player1._projectileSpeed, bulletArray[counter].type);
				window.draw(bulletArray[counter]._Sprite);
			}
			else {
				bulletArray[counter].updateDir(Fighter1._projectileSpeed, bulletArray[counter].type);
				window.draw(bulletArray[counter]._Sprite);
			}
			counter++;
		}
		
		//Draw Fighters --------- ------------ ------------ ---------- --------
		counter = 0;
		for (iter1 = fighterArray.begin(); iter1 != fighterArray.end(); iter1++){
			fighterArray[counter].dir(fighterArray[counter].checkColl(window.getSize().x, window.getSize().y));
			window.draw(fighterArray[counter]._Sprite);
			counter++;
		}
		//DRAW EXPLOSIONS
		counter = 0;
		for (iterexp = Explosionvector.begin(); iterexp != Explosionvector.end(); iterexp++) {
			window.draw(Explosionvector[counter]._Sprite);
			sf::Time explotime = Explosionvector[counter].Clock.getElapsedTime();
			if (explotime.asSeconds() >= 1) {
				Explosionvector.erase(iterexp);
				break;
			}
			counter++;
		}
		//Draw powerups and tick them and destroy them if collision is detected
		for (powerupvector::size_type i = 0; i < powerups1.size(); i++) {
			window.draw(powerups1.at(i)->Getsprite());
			score = powerups1.at(i)->tick(pposx,pposy, Player1.score, globalbounds);
			if (powerups1.at(i)->isactive == false)
			{
				powerups1.erase(powerups1.begin() + i);
			}
			Player1.score = score;
		}
		Player1.setTextObjectsScore(0);

		window.draw(Player1._Sprite); //Draw Player Sprite
		window.draw(Player1._Text); //Draw player hp
		window.draw(Player1._Text2); //Draw player score

		window.display(); //Display Window
	}

	return 0;
}