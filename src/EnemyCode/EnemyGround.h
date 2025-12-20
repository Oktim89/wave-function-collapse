#pragma once
#include <SFML/Graphics.hpp>
#include < iostream>
// Ground-based enemy class
// Inherits from Enemy class and contains specific attributes and methods for ground enemies
class EnemyGround
{
	public:
		EnemyGround();
		~EnemyGround();
		void Attack(int enemy);
        void Move();
	private:
	 int health;
     int damage;
};
