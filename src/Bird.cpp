#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "Bird.h"
#include "Game.h"

Bird::Bird()
{
 
  srand(time(NULL));

}

Bird::~Bird() {

}

bool Bird::init(int index) {

   x_speed = 50 + rand()%10;
   y_speed = 10 + rand()%10;


  if (!sprite_texture.loadFromFile(path[index]))
  {
    std::cout << "Texture not found" << std::endl;
    return false;
  }
  points = index + 1;


  sprite.setTexture(sprite_texture);
  sprite.setPosition(rand()%900, rand()%450);
  
  return true;
}



sf::Sprite& Bird::getSprite()
{
  return sprite;
}



sf::Vector2f Bird::getSpeed()
{
  return sf::Vector2f(x_speed,y_speed);
}

int Bird::getPoints()
{
  return points;
}





void Bird::setSpeed(float x, float y) {

x_speed = x;
  y_speed = y;
}

void Bird::reverse_bird(sf::RenderWindow& window, float dt)
{
  boundaryCheck(window);
     if (
    (sprite.getPosition().x >
     (window.getSize().x - sprite.getGlobalBounds().width)) ||
    (sprite.getPosition().x < 0))
  {
    reverse = !reverse;
  }
  if (reverse == true)
  {
    sprite.setTextureRect(sf::IntRect(
      sprite.getLocalBounds().width,
      0,
      -sprite.getLocalBounds().width,
      sprite.getLocalBounds().height));
    sprite.move(-x_speed * dt, y_speed);
  }
  else
  {
    sprite.setTextureRect(sf::IntRect(
      0, 0, sprite.getLocalBounds().width, sprite.getLocalBounds().height));
    sprite.move(x_speed * dt, y_speed);
  }
  

   
}

void Bird::boundaryCheck(sf::RenderWindow& window)
{
  if (
    (sprite.getPosition().y >
     (window.getSize().y - sprite.getGlobalBounds().height) - 92) ||
    (sprite.getPosition().y < 10))
  {
    if (y_speed > 0)
    {
      // we have hit the bottom
      
      y_speed = -y_speed;
    }
    else
    {
      y_speed = -y_speed;
    }
  }

}

void Bird::incrementSpeed() {
  x_pool  = 40 + x_pool;
  y_pool  = 2 + y_pool;
  x_speed = x_pool;
  y_speed = y_pool;
  
std::cout << x_speed << std::endl;
}







