#include "Enemy.h"
#include <iostream>

Enemy::Enemy(int health, int damage) : health(health), damage(damage) {}

Enemy::~Enemy() {}

void Enemy::takeDamage(int amount)
{
	health -= amount;
	if (health < 0) health = 0;
	std::cout << "Enemy took " << amount << " damage, remaining health: " << health << std::endl;
}

void Enemy::attack() 
{
	std::cout << "Enemy attacks for " << damage << " damage!" << std::endl;
}

int Enemy::spawn(int tile) 
{
  if (!spawned)
  {
    if (tile == 0)
    {
      spawned = true;
      std::cout << "Enemy spawned on tile " << tile << std::endl;
      return 3;
	}
    return -1;
  }
  return -1;
}

int Enemy::getHealth() 
{
	return health;
}
int Enemy::getDamage() 
{
	return damage;
}