#include "EnemyFlying.h"
EnemyFlying::EnemyFlying() {}
EnemyFlying::~EnemyFlying() {}
void EnemyFlying::Attack(int enemy) 
{
  switch (enemy)
  {
    case BAT:
	{
	  std::cout << "Bat swoops down to attack!" << std::endl;
	  break;
	}
	default:
	{
	  std::cout << "Unknown flying enemy attacks!" << std::endl;
	  break;
	}
  }
	
}
void EnemyFlying::Fly() 
{
	std::cout << "EnemyFlying soars through the skies." << std::endl;
}