
#include "Game.h"
#include <iostream>


Game::Game(sf::RenderWindow& game_window) : window(game_window)
{
  srand(time(NULL));
}

Game::~Game() {}

bool Game::init()
{
  grid.init();
  grid.generateDungeon();
  sf::RectangleShape player(sf::Vector2f(20.f, 20.f));
  player.setFillColor(sf::Color::Magenta);
  player.setPosition(grid.getStartPosition());
  
  sf::View camera(sf::FloatRect(0.f, 0.f, 30.f, 30.f));
  camera.setCenter(player.getPosition());
  window.setView(camera);
  return true;
  
}

// UPDATE FUNCTION
void Game::update(float dt)
{
  

  // Update camera to follow player
  camera.setCenter(player.getPosition());
  
 
  
}

void Game::render()
{
  window.draw(player);
  window.setView(camera);
  grid.drawDungeon(window);
  
  
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