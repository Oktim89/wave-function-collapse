#pragma once
#include "Enemy.h"
// Ground-based enemy class
// Inherits from Enemy class and contains specific attributes and methods for ground enemies
class EnemyGround : public Enemy
{
	public:
		EnemyGround(int health, int damage);
		~EnemyGround();
		void Attack();
        void Move();
	private:
};
