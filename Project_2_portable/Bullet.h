#ifndef BULLET_H
#define BULLET_H
#include <SFML\Graphics.hpp>
#include "Entity.h"

class Bullet: public Entity {
public:
	Bullet(sf::Texture& text, int type, bool enemybullet);
	virtual ~Bullet();
	void fire(int x, int y); //Fire centre bullet
	void fire1(int x, int y); //Fire left bullet
	void fire2(int x, int y); //Fire right bullet
	void enemyfire(int x, int y); //fire enemy bullets
	//void dir(Player& player, Bullet& bullet); // Update directions of bullets for different directions (Uncomment in main and in bullet.cpp file )
	void updateDir(float _Speed, int type);
	virtual int checkColl(int x, int y);
	bool destroy = false;
	bool Enemybullet;
	int type;
private:
};
#endif