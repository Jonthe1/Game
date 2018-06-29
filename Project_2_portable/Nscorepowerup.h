#ifndef NSCOREPOWERUP_H
#define NSCOREPOWERUP_H
#include "SFML\Graphics.hpp"
#include "Powerups.h"
class Nscorepowerup : public Powerups {
public:
	Nscorepowerup(sf::Texture& text);
	virtual ~Nscorepowerup();
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