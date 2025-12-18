#ifndef WHACKAMOLESFML_GAME_H
#define WHACKAMOLESFML_GAME_H

#include <SFML/Graphics.hpp>
#include "Bird.h"


  class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event);
  sf::RenderWindow& window;
 
  

 private:
  bool collisionCheck(sf::Vector2i click, sf::Sprite& sprite);
  void spawn();

  void respawn();

  
  sf::Sprite background;
  sf::Texture background_texture;
  sf::Sprite bird;
  sf::Texture bird_texture;
  sf::Texture abs_texture;
  sf::Sprite abs;
  sf::Font font;
  sf::Text title_text;
  sf::Text menu_text;
  sf::Text play_option;
  sf::Text quit_option;
  sf::Text score_text;
  sf::Text timer_text;
  sf::Text gameover_text;
  sf::Text highscore_text;
  bool game_over = false;

  bool play_selected = true;
  Bird bird1;
  Bird bird2;
  Bird bird3;
  Bird bird4;
  Bird bird5;
  Bird bird6;
  int birds_count = 6;
  Bird birds_in_scene[6];
  sf::RectangleShape hl_rect;
  sf::RectangleShape hl_rect_2;
  sf::RectangleShape back;
  
  
  bool reverse  = false;
  float speed   = 200;
  float y_speed = 5;
  int score = 0;
  int highscore = 0;
  bool in_menu;
  bool timer_running   = false;
  float initial_time = 40.f;
  float time_remaining = 40.f;
  float spawn_time     = 2.f;
  sf::Clock clock;
  float t;
  bool abs_timer_running = false;
  float abs_timer = 2.f;
  float abs_spawner      = 5.f;
  float abs_time         = 5.f;
  
};

#endif // WHACKAMOLESFML_GAME_H
