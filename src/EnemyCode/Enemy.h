#pragma once
#include <SFML/Graphics.hpp>

// Parent class for all enemies
// Contains common attributes and methods for enemies
// Indivual enemy types will inherit from this class and implement unique behaviors
class Enemy
{
	public:
	Enemy(int health, int damage);
	~Enemy();
	void attack();
	void takeDamage(int amount); 
	int getHealth();
    int getDamage();
    sf::Vector3i spawn(int (*matrix)[60]);

	private:
	int health;
    int damage;
    int type;
    bool spawned = false;

};
