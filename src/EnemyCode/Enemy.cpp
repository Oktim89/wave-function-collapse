#include "Enemy.h"
#include <iostream>

Enemy::Enemy() {}

Enemy::~Enemy() {}

void Enemy::takeDamage(int amount)
{
	//health -= amount;
	//if (health < 0) health = 0;
	//std::cout << "Enemy took " << amount << " damage, remaining health: " << health << std::endl;
}

void Enemy::checkIfAttackPossible(int (*matrix)[60])
{
	// Placeholder logic for checking if an attack is possible
	// In a real implementation, this would involve checking the player's position relative to the enemy
	// For now, this function checks if there is a tile in the matrix that is an enemy
  std::cout << "Checking if attack is possible based on the matrix." << std::endl;
  for (int i = 0; i < 60; i++)
  {
    for (int j = 0; j < 60; j++)
    {
      if (matrix[i][j] == SLIME)
      {
        attack(SLIME);
	  }
	}
  }
}

void Enemy::attack(int enemy) 
{
  if (type == SLIME)
  {
	enemyGround.Attack(SLIME);
  }
  else
  {
	enemyFlying.Attack();
  }
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