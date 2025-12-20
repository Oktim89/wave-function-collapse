#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
// Flying enemy class
// Inherits from Enemy class and contains specific attributes and methods for flying enemies
class EnemyFlying
{
	public:
		EnemyFlying();
		~EnemyFlying();
		void Attack();
		void Fly();

       private:
};
