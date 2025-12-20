#include "EnemyGround.h"

EnemyGround::EnemyGround(){}

EnemyGround::~EnemyGround() {}

void EnemyGround::Attack(int enemy) 
{
	if (enemy == -1) // SLIME
	{
		std::cout << "EnemyGround attacks with a slime hit!" << std::endl;
    }
}

void EnemyGround::Move() 
{
	std::cout << "EnemyGround moves on the ground." << std::endl;
}