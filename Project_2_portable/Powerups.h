#ifndef POWERUPS_H
#define POWERUPS_H
#include "SFML\Graphics.hpp"
class Powerups {
public:
	float _Speed = 0;
	Powerups() {};
	virtual ~Powerups() {};
	virtual void move() = 0;
	virtual int tick(int x, int y, int score, sf::FloatRect rect) = 0;
	virtual int collide(int x, int y, int score, sf::FloatRect rect) = 0;
	virtual int setscore(int score) = 0;
	virtual sf::Sprite Getsprite() = 0;
	bool isactive;
};
#endif