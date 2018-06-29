#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"

class Player: public Entity
{
public: 
	Player(); //Constructor
	~Player(); //Destructor

	//PLAYER MOVEMENT FUNCTIONS
	void moveUp();
	void moveDown(int y);
	void moveRight(int x);
	void moveLeft();
	void setSpeed(float TEMP_Speed);
	void setTextObjectsScore(int i);
	void setTextObjectsHealth(int x);
	virtual int checkColl(int x, int y) { return 0; };
	float _SpeedBoost;
	sf::Text _Text;
	sf::Text _Text2;
	int score;
	private:

};
#endif
