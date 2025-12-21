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
	case BABY_DRAGON:
	{
	  std::cout << "Baby Dragon breathes fire!" << std::endl;
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

int EnemyFlying::getHealth(int enemy) 
{
  switch (enemy)
  {
	case BAT:
	{
	  health = 15;
	  break;
	}
	case BABY_DRAGON:
	{
	  health = 35;
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

int EnemyFlying::getDamage(int enemy) 
{
  switch (enemy)
  {
	case BAT:
	{
	  damage = 5;
	  break;
	}
	case BABY_DRAGON:
	{
	  damage = 15;
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