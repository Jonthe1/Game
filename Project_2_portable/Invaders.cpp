#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Entity.h"
#include "Bullet.h"
#include "TextDisplay.h"
#include <vector>
#include <ostream>
#include "Fighter.h"
#include <string>

using namespace std;
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

//Load Font
sf::Font Font;
if (!Font.loadFromFile("ARIAL.TTF"))
std::cout << "Texture Error FONT" << std::endl;


//Create Player
class Player Player1;

//Create bullets
//Playerbullets
class Bullet bullet1;
//Enemybullets
class Bullet bullet2;

//Create Fighter
class Fighter Fighter1;

//Create Textobjects
class TextDisplay Health;

//LoadTexturesToObjects
Player1._Sprite.setTexture(PlayerTexture); //Player
bullet1._Sprite.setTexture(BulletTexture); //Bullet
Fighter1._Sprite.setTexture(FighterTexture); //Fighter
bullet2._Sprite.setTexture(BulletTexture); //Fighter Bullets

										   //Load Font to text object
Player1._Text.setFont(Font);
Player1._Text2.setFont(Font);


//Create player bullet vectors
vector<Bullet>::const_iterator iter;
vector<Bullet> bulletArray;

//Create Fighter vectors
vector<Fighter>::const_iterator iter1;
vector<Fighter> fighterArray;

//Create Fighter bullet vectors
vector<Bullet>::const_iterator iter2;
vector<Bullet> FbulletArray;

//TESTBULLETARRAY
vector<Bullet>::const_iterator iter3;
vector<Bullet> TESTbulletArray;


cout << "message" << endl;
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
	sf::Time Framerate = clock3.getElapsedTime();
	sf::Time elapsedSpawn = enemySpawnClock.getElapsedTime();
	//DELETE OBJECTS 
	counter = 0;
	for (iter = bulletArray.begin(); iter != bulletArray.end(); iter++) {
		if (bulletArray[counter].Destroy(window.getSize().x, window.getSize().y) == true || bulletArray[counter].destroy == true) {
			bulletArray.erase(iter);
			break;
		}
		counter++;
	}

	/*	counter = 0;
	for (iter2 = FbulletArray.begin(); iter2 != FbulletArray.end(); iter2++) {
	if (FbulletArray[counter].Destroy(window.getSize().x, window.getSize().y) == true) {
	FbulletArray.erase(iter2);
	break;
	}
	counter++;
	}*/

	counter = 0;
	for (iter1 = fighterArray.begin(); iter1 != fighterArray.end(); iter1++) {
		if (fighterArray[counter].Destroy(window.getSize().x, window.getSize().y) == true || fighterArray[counter].dead == true) {
			fighterArray.erase(iter1);
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
		bullet1.TESTfire();
		TESTbulletArray.push_back(bullet1);
		cout << "testbullets: " << TESTbulletArray.size() << "-------------------------------" << endl;
	}

	//FIREBUTTON
	if (elapsed1.asSeconds() >= Player1.attackSpeed)
	{
		clock.restart();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			if (bulletArray.size()) {
				bullet1.dir(Player1, bullet1);
				bullet1.fire(Player1._Sprite.getPosition().x, Player1._Sprite.getPosition().y);
				bulletArray.push_back(bullet1);
			}
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
		if (fighterArray.size() <= 3) {
			Fighter1.randomnspawnerEnemies();
			fighterArray.push_back(Fighter1);
		}
		enemySpawnClock.restart();
		/*cout <<"fighter :"<< fighterArray.size() << endl;
		cout << "fighterbullets :" << FbulletArray.size() << endl;
		cout << "playerbullets :" << bulletArray.size() << endl;
		cout << "----------------------------------------------------" << endl;*/
	}
	//Enemy bullets
	if (elapsed2.asSeconds() >= Fighter1.attackSpeed)
	{
		clock2.restart();
		counter = 0;
		for (iter1 = fighterArray.begin(); iter1 != fighterArray.end(); iter1++) {
			bullet1.enemyfire(fighterArray[counter]._Sprite.getPosition().x, fighterArray[counter]._Sprite.getPosition().y);
			bulletArray.push_back(bullet1);
			counter++;
		}
	}

	//Player Bullets Collide With Fighter
	counter = 0;
	for (iter = bulletArray.begin(); iter != bulletArray.end(); iter++)
	{
		counter1 = 0;
		if (!bulletArray[counter].Enemybullet) {
			for (iter1 = fighterArray.begin(); iter1 != fighterArray.end(); iter1++) {
				if (bulletArray[counter]._Sprite.getGlobalBounds().intersects(fighterArray[counter1]._Sprite.getGlobalBounds())) {
					bulletArray[counter].destroy = true;
					fighterArray[counter1].dead = true;
					Player1.setTextObjects();
					break;
				}
				counter1++;
			}
		}
		counter++;
		//cout << counter << endl;
	}
	//Draw objects-----------------------------------------------------
	window.draw(background);
	//Draw bullets-----------------------------------------------------
	counter = 0;
	for (iter = bulletArray.begin(); iter != bulletArray.end(); iter++)
	{
		if (!bulletArray[counter].Enemybullet) {
			bulletArray[counter].updateDir(Player1._projectileSpeed);
			window.draw(bulletArray[counter]._Sprite);
		}
		else {
			bulletArray[counter].enemyUpdateDir(Fighter1._projectileSpeed);
			window.draw(bulletArray[counter]._Sprite);
		}
		counter++;
	}

	//Draw Fighters --------- ------------ ------------ ---------- --------
	counter = 0;
	for (iter1 = fighterArray.begin(); iter1 != fighterArray.end(); iter1++) {
		fighterArray[counter].dir(fighterArray[counter].checkColl(window.getSize().x, window.getSize().y));
		window.draw(fighterArray[counter]._Sprite);
		counter++;
	}
	//Draw fighter Bullets------------- ------------- ---------------- ------------- -----------
	/*counter = 0;
	for (iter2 = FbulletArray.begin(); iter2 != FbulletArray.end(); iter2++) {
	//if (bulletArray[counter].Enemybullet) {
	FbulletArray[counter].enemyUpdateDir(Fighter1._projectileSpeed);
	window.draw(FbulletArray[counter]._Sprite);
	//	}
	counter++;
	}*/
	window.draw(Player1._Sprite); //Draw Player Sprite
	window.draw(Player1._Text);
	window.draw(Player1._Text2);

	counter = 0;
	for (iter3 = TESTbulletArray.begin(); iter3 != TESTbulletArray.end(); iter3++) {
		window.draw(TESTbulletArray[counter]._Sprite);
		counter++;
	}
	window.display(); //Display Window
	cout << 1.0 / Framerate.asSeconds() << endl;
	clock3.restart().asSeconds();
}