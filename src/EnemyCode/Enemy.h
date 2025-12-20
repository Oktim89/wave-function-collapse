#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "EnemyGround.h"
#include "EnemyFlying.h"

// Enemy class
// Container Class for different enemy types
// Allows Enemy logic to be handled in one place,
// while specific enemy behaviors are delegated to their respective classes
class Enemy
{
	public:
	Enemy();
	~Enemy();
	void attack(int enemy);
    void checkIfAttackPossible(int (*matrix)[60]);
	void takeDamage(int amount); 
    sf::Vector3i spawn(int (*matrix)[60]);

	private:
	//int health;
    //int damage;
    int type;
    bool spawned = false;
    enum EnemyTypes
    {
      SLIME = -1
    };

	EnemyGround enemyGround;
    EnemyFlying enemyFlying;

};
