#ifndef ENTITY_H
#define ENTITY_H
#include <SFML\Graphics.hpp>
using namespace std;

class Entity
{
public:
	int hp;
	float attackSpeed, _projectileSpeed, _Speed; //object attackspeed, speed of projectiles, and movementspeed
	Entity(); //Constructor
	virtual ~Entity(); //Destructor
	sf::Sprite _Sprite;
	sf::Vector2i _Source;
	virtual int checkColl(int x, int y) = 0;
	enum _Direction { Up, Left, Down, Right }; //Declare Direction Enumeration
	bool gooners = false; // Boolean used for identifying destroyd objects 
	//int direction = 0; //direction Up = 1, down = 2, left = 3, right = 4 used sprite update image
private:
	
protected:
};
#endif
