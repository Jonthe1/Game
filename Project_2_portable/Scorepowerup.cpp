#include "Scorepowerup.h"
#include "SFML\Graphics.hpp"
#include <iostream>
using namespace std;
Scorepowerup::Scorepowerup(sf::Texture& text) : Powerups(), _Texture(text) {
	_Sprite.setTexture(_Texture);
	_Sprite.setTextureRect(sf::IntRect(0, 0, 100, 200));
	_Sprite.setScale(0.5f, 0.5f);
	isactive = true;
	_Speed = 0.05;
	setrandompos(); // set spawnposition
}
Scorepowerup::~Scorepowerup() {

}
void Scorepowerup::move() {
	//cout << _Sprite.getPosition().y << endl;
	if (_Sprite.getPosition().y >= 700)
	{
		isactive = false;
	}
	else {
		_Sprite.move(0, _Speed);
	}
}
int Scorepowerup::tick(int x, int y, int score, sf::FloatRect rect) {
	int score1 = collide(x, y, score, rect);
	move();
	return score1;
}
int Scorepowerup::collide(int x, int y, int score, sf::FloatRect rect) {
	int score1 = 0;
	if (_Sprite.getGlobalBounds().intersects(rect)) {
		score1 = setscore(score);
		isactive = false;
		return score1;
	}
	else {
		return score;
	}
}
int Scorepowerup::setscore(int score) {
	score = score + 200;
	return score;
}
void Scorepowerup::setrandompos() {
	int x = rand() % 1200;
	int y = 0;
	_Sprite.setPosition(x - 32, y - 32);
}
sf::Sprite Scorepowerup::Getsprite() {
	return _Sprite;
};