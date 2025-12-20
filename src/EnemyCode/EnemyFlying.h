#pragma once
#include "Enemy.h"
// Flying enemy class
// Inherits from Enemy class and contains specific attributes and methods for flying enemies
class EnemyFlying : public Enemy
{
	public:
		EnemyFlying(int health, int damage);
		~EnemyFlying();
		void Attack();
		void Fly();

       private:
};
