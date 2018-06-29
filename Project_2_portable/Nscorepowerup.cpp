#include "Nscorepowerup.h"
#include "SFML\Graphics.hpp"
Nscorepowerup::Nscorepowerup(sf::Texture& text) : Powerups(), _Texture(text) {
	_Sprite.setTexture(_Texture);
	_Sprite.setScale(0.1f, 0.1f);
	isactive = true;
	_Speed = 0.05;
	setrandompos(); // set spawnposition
}
Nscorepowerup::~Nscorepowerup() {

}
void Nscorepowerup::move() {
	if (_Sprite.getPosition().y <= 0)
	{
		isactive = false;
	}
	else {
		_Sprite.move(0, -_Speed);
	}
}
int Nscorepowerup::tick(int x, int y, int score, sf::FloatRect rect) {
	int score1 = collide(x, y, score, rect);
	move();
	return score1;
}
int Nscorepowerup::collide(int x, int y, int score, sf::FloatRect rect) {
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
int Nscorepowerup::setscore(int score) {
	score = score - 100;
	return score;
}
void Nscorepowerup::setrandompos() {
	int x = rand() % 1200;
	int y = 720;
	_Sprite.setPosition(x - 32, y - 32);
}
sf::Sprite Nscorepowerup::Getsprite() {
	return _Sprite;
};