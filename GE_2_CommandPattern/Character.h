#pragma once
#include <iostream>

class Character
{
public:
	Character();
	~Character();

	void jump();
	void moveLeft();
	void moveRight();
	void goProne();
};


Character::Character()
{

}

Character::~Character()
{

}


void Character::jump()
{
	printf("Jumping \n");
}

void Character::moveLeft()
{
	printf("Left \n");
}

void Character::moveRight()
{
	printf("Right \n");
}

void Character::goProne()
{
	printf("Crouch \n");
}