#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Entity.h"
#include "Bullet.h"
#include <vector>
#include <ostream>
#include "Fighter.h"
#include "Engine.h"
using namespace std;

Engine::Engine() {
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

	//Window
	sf::RenderWindow window(sf::VideoMode(1200, 700), "Testing");
	window.setKeyRepeatEnabled(false);
	window.setTitle("SFML SHTU-Game-ProgrammingAssignment");

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
	if (!FighterTexture.loadFromFile("SpriteShip.png"))
		std::cout << "Texture Error" << std::endl;

	//Create Player
	class Player Player1;

	//Create bullet
	class Bullet bullet1;

	//Create Fighter
	class Fighter Fighter1;

	//LoadTexturesToObjects
	Player1._Sprite.setTexture(PlayerTexture); //Player
	bullet1._Sprite.setTexture(BulletTexture); //Bullet
	Fighter1._Sprite.setTexture(FighterTexture); //Fighter

												 //Create bullet vectors
	vector<Bullet>::const_iterator iter;
	vector<Bullet> bulletArray;
	//Create Fighter vectors
	vector<Fighter>::const_iterator iter1;
	vector<Fighter> fighterArray;

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

						//TIMERS
		sf::Time elapsed1 = clock.getElapsedTime();
		sf::Time elapsed2 = clock2.getElapsedTime();
		sf::Time elapsed3 = clock3.getElapsedTime();
		sf::Time elapsedSpawn = enemySpawnClock.getElapsedTime();

		//DELETE OBJECTS 
		counter = 0;
		for (iter = bulletArray.begin(); iter != bulletArray.end(); iter++) {
			if (bulletArray[counter].Destroy(bullet1._Sprite.getPosition().x, bullet1._Sprite.getPosition().y) == true) {
				bulletArray.erase(iter);
				break;
			}
			counter++;
		}

		//PLAYER MOVEMENT------------------------------------------------
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { //Move Up
			Player1.moveUp();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { //Move Down
			Player1.moveDown(window.getSize().y);

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { //Move Right
			Player1.moveRight(window.getSize().x);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { //Move Left
			Player1.moveLeft();
		}


		//FIREBUTTON
		if (elapsed1.asSeconds() >= Player1.attackSpeed)
		{
			clock.restart();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				bullet1.dir(Player1, bullet1);
				bullet1.fire(Player1._Sprite.getPosition().x, Player1._Sprite.getPosition().y);
				bulletArray.push_back(bullet1);
			}
		}

		//Player SPRINT
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
			Player1.setSpeed(0.15, sf::milliseconds(50));
		}
		else {
			Player1.setSpeed(0.10, sf::milliseconds(80));
		}
		//End player movement----------------------------------------------

		//ENEMY------------------------------------------------------------
		if (elapsedSpawn.asSeconds() >= 3) {
			Fighter1.randomnspawner();
			fighterArray.push_back(Fighter1);
			enemySpawnClock.restart();
		}
		//Draw objects-----------------------------------------------------
		//Draw bullets-----------------------------------------------------
		counter = 0;
		for (iter = bulletArray.begin(); iter != bulletArray.end(); iter++)
		{
			bulletArray[counter].updateDir();
			window.draw(bulletArray[counter]._Sprite);
			counter++;
		}

		//Draw Fighters --------- ------------ ------------ ---------- --------
		counter = 0;
		for (iter1 = fighterArray.begin(); iter1 != fighterArray.end(); iter1++) {
			fighterArray[counter].dir();
			window.draw(fighterArray[counter]._Sprite);
			counter++;
		}

		window.draw(Player1._Sprite); //Draw Player Sprite
		window.display(); //Display Window

	}

	//return 0;
}

Engine::~Engine() {

};