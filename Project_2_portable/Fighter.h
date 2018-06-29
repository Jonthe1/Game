#ifndef FIGHTER_H
#define FIGHTER_H
#include "Entity.h"
#include <SFML\Graphics.hpp>

class Fighter: public Entity {
public:
	Fighter();
	~Fighter();
	void dir(int hitwall);
	virtual int checkColl(int x, int y);
	int Destroy(int x, int y);
	bool dead = false;
	void randomnspawnerEnemies(); // Randomspawner for enemies
private:
	int hitwall = 0;
};
#endif