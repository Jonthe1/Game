#ifndef SCOREPOWERUP_H
#define SCOREPOWERUP_H
#include "SFML\Graphics.hpp"
#include "Powerups.h"
class Scorepowerup: public Powerups {
public:
	Scorepowerup(sf::Texture& text);
	virtual ~Scorepowerup();
	virtual void move();
	virtual int collide(int x, int y, int score, sf::FloatRect rect);
	virtual int tick(int x, int y, int score, sf::FloatRect rect);
	virtual int setscore(int score);
	virtual sf::Sprite Getsprite();
private:
	void setrandompos();
	sf::Sprite _Sprite;
	sf::Texture _Texture;
};
#endif
