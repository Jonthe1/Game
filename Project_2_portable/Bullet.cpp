#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bullet.h"

Bullet::Bullet(sf::Texture& text, int type, bool enemybullet) : type(type), Enemybullet(enemybullet)//Constructor
{
	_Sprite.setTexture(text);
	_Sprite.setPosition(600 - 32, 350 - 32); //Set Sprite Position (Centre)
	_Sprite.setScale(1.0f, 1.0f); //Sprite Scale
	_Sprite.setTextureRect(sf::IntRect(0, 0, 8, 8));
};
Bullet::~Bullet() {
};

/*
void Bullet::dir(Player& player, Bullet& bullet) { // Update directions of bullets for different directions (Uncomment in main and in bullet.h file )
	bullet.direction = player.direction;
};*/

void Bullet::fire(int x, int y) { //fire front
	Enemybullet = false;
	_Sprite.setPosition(x + 21.5, y - 5);
};

void Bullet::fire1(int x, int y) { //fire left
	Enemybullet = false;
	_Sprite.setPosition(x + 32 , y + 21.5);

};

void Bullet::fire2(int x, int y) { //fire right
	Enemybullet = false;
	_Sprite.setPosition(x + 32, y + 21.5);
};

void Bullet::enemyfire(int x, int y) {
	Enemybullet = true;
	_Sprite.setPosition(x + 21.5, y + 45);
}

void Bullet::updateDir(float _Speed, int type) {//up
	if (type == 1) { //Center*/
			_Sprite.move(0, -_Speed);
    }
	else if (type == 2) { // left 
			_Sprite.move(-_Speed, -_Speed);
	}
	else if (type == 3) { // right
			_Sprite.move(_Speed, -_Speed);
	}
	else { // Down ( ENEMY FIRE ) 
		_Sprite.move(0, _Speed);
	}
}

int Bullet::checkColl(int x, int y) {
	gooners = false;
	if (_Sprite.getPosition().y <= 0) { //UP
		gooners = true;
	}
	if (_Sprite.getPosition().y + _Sprite.getLocalBounds().height - 50 >= y) { //DOWN
		gooners = true;
	}
	if (_Sprite.getPosition().x + _Sprite.getLocalBounds().width - 50 >= x) { //RIGHT
		gooners = true;
	}
	if (_Sprite.getPosition().x <= 0) { //LEFT
		gooners = true;
	}
	return gooners;
}