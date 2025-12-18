#pragma once
#include <SFML/Graphics.hpp>



class Bird

{
 public:

  Bird();
  ~Bird();
  bool init(int index);
  sf::Sprite& getSprite();
  sf::Vector2f getSpeed();
  int getPoints();
 
  void setSpeed(float x, float y);
 void reverse_bird(sf::RenderWindow& window ,float dt);
  void boundaryCheck(sf::RenderWindow& window);
 void incrementSpeed();

  
  
  

 private:

 

  
  void spawn();
  std::string path[7] = {
    "../Data/Images/bird.png",        "../Data/Images/Cat_Right.png",
    "../Data/Images/Chick_Right.png", "../Data/Images/Fox_Right.png",
    "../Data/Images/Mouse_Right.png", "../Data/Images/Pig_Right.png",
    "../Data/Images/Rabbit_Right.png"
  };
  sf::Sprite sprite;
  sf::Texture sprite_texture;
  bool reverse  = false;
  float x_speed   = 50;
  float y_speed = 5;
  float x_pool    = 50;
  float y_pool    = 5;
  bool in_menu;
  int points;
  




  
};
