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
void EnemyFlying::Move(int enemy) 
{
  switch (enemy)
  {
	  case BAT:
	{
	  std::cout << "Bat flutters its wings and flies." << std::endl;
	  break;
    }
	default:
	{
	  std::cout << "Unknown flying enemy flies!" << std::endl;
	  break;
    }
  }
}