#ifndef EXPLOSION_H
#define EXPLOSION_H
#include <SFML\Graphics.hpp>
class Explosion {
public:
	sf::Sprite _Sprite;
	Explosion(int x, int y, sf::Texture& Text);
	~Explosion();
	sf::Clock Clock;
private:
};
#endif