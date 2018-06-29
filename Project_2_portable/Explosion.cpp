#include "SFML\Graphics.hpp"
#include "Explosion.h"

Explosion::Explosion(int x, int y, sf::Texture& Text) {
	_Sprite.setTexture(Text);
	_Sprite.setPosition(x, y);
	_Sprite.setScale(1.0f, 1.0f); //Sprite Scale
	_Sprite.setTextureRect(sf::IntRect(0, 0, 91, 91)); //Crop Sprite Sheet (Default Crop)
}
Explosion::~Explosion() {

}