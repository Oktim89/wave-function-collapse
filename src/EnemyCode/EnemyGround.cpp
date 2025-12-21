#include "EnemyGround.h"

EnemyGround::EnemyGround(){}

EnemyGround::~EnemyGround() {}

void EnemyGround::Attack(int enemy) 
{
  switch (enemy)
  {
    case SLIME:
    {
      std::cout << "Slime attacks with a sticky slap!" << std::endl;
      break;
    }
    default:
    {
      std::cout << "Unknown ground enemy attacks!" << std::endl;
      break;
    }
  }
}

void EnemyGround::Move(int enemy)
{
    switch (enemy)
  {
    case SLIME:
    {
      std::cout << "Slime oozes forward slowly." << std::endl;
      break;
    }
    default:
    {
      std::cout << "Unknown ground enemy moves!" << std::endl;
      break;
    }
  }
}

int EnemyGround::getDamage(int enemy)
{
  switch (enemy)
  {
    case SLIME:
    {
      damage = 5;
      break;
    }
    case SKELETON:
    {
      damage = 10;
      break;
    }
    default:
    {
      damage = 0;
      break;
    }
  }
  return damage;
}
int EnemyGround::getHealth(int enemy)
{
  switch (enemy)
  {
    case SLIME:
    {
      health = 10;
      break;
    }
    case SKELETON:
    {
      health = 20;
      break;
    }
    default:
    {
      health = 0;
      break;
    }
  }
  return health;
}