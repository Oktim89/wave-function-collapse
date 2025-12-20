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

sf::Vector3i Enemy::spawn(int (*matrix)[60])
{
  //int(*matrix)[60] = matrix;
  int x  = 0;
  int y = 0;
  do
  {
    x = rand() % 60;
    y = rand() % 60;
  } while (matrix[x][y] != 0);
  spawned = true;
  std::cout << "Enemy spawned on a tile" << std::endl;
  type = -1; // Placeholder for enemy type
  return sf::Vector3i(type, x, y);
}

int Enemy::getHealth() 
{
	return health;
}
int Enemy::getDamage() 
{
	return damage;
}