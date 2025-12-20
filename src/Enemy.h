#pragma once

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
    int spawn();

	private:
	int health;
    int damage;
    bool spawned = false;

};
