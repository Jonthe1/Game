#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"


Player::Player() //Constructor
{
	//Player
	_Sprite.setPosition(600 - 32, 350 - 32); //Set Sprite Position (Centre)
	_Sprite.setScale(0.5f, 0.5f); //Sprite Scale
	_Sprite.setTextureRect(sf::IntRect(0,0,96,96)); //Crop Sprite Sheet (Default Crop)
	_Speed = 0.10; //Player MovementSpeed
	_projectileSpeed = 0.15; //Player projectilespeed
	attackSpeed = 0.2; //player attackspeed
	_SpeedBoost = 0.15; // Player movementspeed when boost
	hp = 100; //set player HP to 100
	score = 0; //set player startscore to 0
	//direction = 1; //original direction. 

	//TEXT FOR PLAYER
	//HP
	_Text.setString("health: " + to_string(hp));
	_Text.setPosition(0, 0);
	_Text.setCharacterSize(40);
	_Text.setFillColor(sf::Color::Red);
	_Text.setOutlineColor(sf::Color::Red);

	//Score
	_Text2.setString("Score: " + to_string(score));
	_Text2.setPosition(900, 0);
	_Text2.setCharacterSize(40);
	_Text2.setFillColor(sf::Color::Red);
	_Text2.setOutlineColor(sf::Color::Red);
}

Player::~Player() //Destructor
{
}

//PLAYER MOVEMENT
void Player::moveUp()
{
	_Source.y = Up; //Set '_Source.y' Equal To 'Up' (_Direction Enum)
	if (_Sprite.getPosition().y <= 0) {
		_Sprite.move(0, 0); //Move Player Sprite
	}
	else{
		_Sprite.move(0, -_Speed);
	}
		_Sprite.setTextureRect(sf::IntRect(_Source.y * 96, 0, 96, 96)); //Crop Sprite Sheet
		//direction = 1;
}

void Player::moveDown(int y)
{
	_Source.y = Down; //Set '_Source.y' Equal To 'Up' (_Direction Enum)
	if (_Sprite.getPosition().y + _Sprite.getLocalBounds().height - 50 >= y) {
		_Sprite.move(0, 0); //Move Player Sprite
	}
	else {
		_Sprite.move(0, _Speed);
	}
	_Sprite.setTextureRect(sf::IntRect(_Source.y * 96, 0, 96, 96)); //Crop Sprite Sheet
	//direction = 2;
}

void Player::moveRight(int x)
{
	_Source.y = Right; //Set '_Source.y' Equal To 'Up' (_Direction Enum)
	if (_Sprite.getPosition().x + _Sprite.getLocalBounds().width - 50 >= x) {
		_Sprite.move(0, 0); //Move Player Sprite
	}
	else {
		_Sprite.move(_Speed, 0); //Move Player Sprite
	}
	_Sprite.setTextureRect(sf::IntRect(_Source.y * 96, 0, 96, 96)); //Crop Sprite Sheet
	//direction = 4;
}


void Player::moveLeft()
{
	_Source.y = Left; //Set '_Source.y' Equal To 'Up' (_Direction Enum)
	if (_Sprite.getPosition().x <= 0) {
		_Sprite.move(0, 0); //Move Player Sprite
	}
	else {
		_Sprite.move(-_Speed, 0); //Move Player Sprite
	}
	_Sprite.setTextureRect(sf::IntRect(_Source.y * 96, 0, 96, 96)); //Crop Sprite Sheet
	//direction = 3;
}

void Player::setSpeed(float TEMP_Speed) //Sets movementspeed when sprinting and not sprinting. 
{
	_Speed = TEMP_Speed;
}

void Player::setTextObjectsScore(int i) { //Sets new score 
	if (i == 1) {
		score = score + 100;
	}
	_Text2.setString("Score: " + to_string(score));
}

void Player::setTextObjectsHealth(int x) { //sets player HP if hit by bullet or collision with fighter
	if (x == 1) {
		hp = hp - 5;
	}
	else {
		hp = hp - 10;
	}
	_Text.setString("Health: " + to_string(hp));
};