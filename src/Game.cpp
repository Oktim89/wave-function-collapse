
#include "Game.h"
#include <iostream>


Game::Game(sf::RenderWindow& game_window) : window(game_window)
{
  srand(time(NULL));
}

Game::~Game() {}

bool Game::init()
{

wfc.init();
  i_wfc.init();
  return true;
  
}

// UPDATE FUNCTION
void Game::update(float dt)
{
  timer += dt;
  if (timer >= 0.1f)
  {
    wfc.update();
    timer = 0;
  }
  
  //i_wfc.update();

  
  
  
 
  
}

void Game::render()
{
  wfc.render(window);
  //i_wfc.render(window);
  
  
}



void Game::mouseClicked(sf::Event event)
{
  // get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);
  
 
  
  
}

void Game::keyPressed(sf::Event event)
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
  {
    player.move(0.f, -speed * 0.16);
  
  }
    
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
  {
    player.move(0.f, speed * 0.16);
  }
    
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
  {
    player.move(-speed * 0.16, 0.f);
  }
    
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
  {
    player.move(speed *0.16, 0.f);
  }
 
 
}



bool Game::collisionCheck(sf::Vector2i click, sf::Sprite& sprite)
{
  if (
    (click.x >= sprite.getPosition().x) &&
    (click.x <= sprite.getPosition().x + sprite.getGlobalBounds().width))
  {
    if (
      (click.y >= sprite.getPosition().y) &&
      click.y <= sprite.getPosition().y + sprite.getGlobalBounds().height)
    {
      sprite.setPosition(1000, 1000);
 
     
      
      return true;
      
    }
  }
  return false;
}

void Game::spawn()
{
  
 
}


  // remember time 5 birds diff intervals each with seperate score.