#include <SFML/Graphics.hpp>
#include <iostream>
#include "Fighter.h"
using namespace std;

Fighter::Fighter() {
	_Sprite.setPosition(600 - 32, 350 - 32); //Set Sprite Position (Centre)
	_Sprite.setScale(0.5f, 0.5f); //Sprite Scale
	_Sprite.setTextureRect(sf::IntRect(0, 0, 114, 200)); //Crop Sprite Sheet (Default Crop)
	_Speed = 0.005; //Fighter movementspeed
	_projectileSpeed = 0.05; //Fighter bullet speed
	attackSpeed = 0.4; //Fighter attackspeed
};

Fighter::~Fighter() {
};

void Fighter::dir(int hitwall) { //fighter movements
	if (dead == true) {
	}
	else if (hitwall == 1) { //Move left
		_Sprite.move(-0.04, _Speed);
	}
	else { //Move right
		_Sprite.move(0.04, _Speed);
	}

}

int Fighter::checkColl(int x, int y) //Collision check for fighters
{
	if (_Sprite.getPosition().x + _Sprite.getLocalBounds().width - 50 >= x && hitwall != 1) { //RIGHT
		hitwall = 1;
	}
	if (_Sprite.getPosition().x <= 0 && hitwall != 2) { //LEFT
		hitwall = 2;
	}
	return hitwall;
}

int Fighter::Destroy(int x, int y) { //If fighter hits bottom of the screen
	gooners = false;
	if (_Sprite.getPosition().y + _Sprite.getLocalBounds().height - 120 >= y) { //DOWN
		gooners = true;
	}
	return gooners;
}

void Fighter::randomnspawnerEnemies()
{
	int x = rand() % 1200;
	int y = 0;
	_Sprite.setPosition(x - 32, y - 32);
};