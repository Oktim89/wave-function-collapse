
#include "Game.h"
#include <iostream>
#include <string>
#include <cmath>

Game::Game(sf::RenderWindow& game_window) : window(game_window)
{
  srand(time(NULL));
}

Game::~Game() {}

bool Game::init()
{
  birds_in_scene[birds_count];
  bird1.init(0);
  bird2.init(1);
  bird3.init(2);
  bird4.init(3);
  bird5.init(4);
  bird6.init(5);
 
  
  
  birds_in_scene[0] = bird1;
  birds_in_scene[1] = bird2;
  birds_in_scene[2] = bird3;
  birds_in_scene[3] = bird4;
  birds_in_scene[4] = bird5;
  birds_in_scene[5] = bird6;
  
  
  speed = 5;
  y_speed = 1;
  back.setSize(sf::Vector2f(
    window.getSize().x, window.getSize().y));
  back.setFillColor(sf::Color(0, 0, 0, 255));

 if (!abs_texture.loadFromFile("../Data/Images/ball.png"))
  {
   std::cout << "ability texture not found" << std::endl;
 }
  abs.setTexture(abs_texture);
 abs.setScale(0.5, 0.5);
  abs.setPosition(500, 300);

 
  in_menu = true;
  if (!background_texture.loadFromFile("../Data/Images/background.png"))
  {
    std::cout << "backgrounfd texture not found" << std::endl;
  }
  background.setTexture(background_texture);

  if (!bird_texture.loadFromFile("../Data/Images/bird.png"))
  {
    std::cout << "Bird texture not found" << std::endl;
  }

  bird.setTexture(bird_texture);
  bird.setPosition(500, 550);

  if (!font.loadFromFile("../Data/Fonts/OpenSans-Bold.ttf"))

  {
    std::cout << "Font not found" << std::endl;
  }
  title_text.setString("Whack-a-mole");
  title_text.setFont(font);
  title_text.setCharacterSize(100);
  title_text.setFillColor(sf::Color(255, 255, 255, 255));

  title_text.setPosition(
    window.getSize().x / 2 - title_text.getGlobalBounds().width / 2,
    window.getSize().y / 2 - title_text.getGlobalBounds().height / 2);

  // Menu Title Text
  menu_text.setString("Welcome to whack-a-mole. Please select an option: ");
  menu_text.setFont(font);
  menu_text.setCharacterSize(20);
  menu_text.setFillColor(sf::Color(255, 255, 0, 128));
  menu_text.setPosition(
    window.getSize().x / 2 - menu_text.getGlobalBounds().width / 2,
    window.getSize().y / 10);

  play_option.setString(">Play<");
  play_option.setFont(font);
  play_option.setCharacterSize(20);
  play_option.setFillColor(sf::Color(255, 255, 0, 255));
  play_option.setPosition(
    window.getSize().x / 2 - menu_text.getGlobalBounds().width / 2,
    window.getSize().y / 5);

  quit_option.setString("Quit");
  quit_option.setFont(font);
  quit_option.setCharacterSize(20);
  quit_option.setFillColor(sf::Color(255, 255, 0, 255));
  quit_option.setPosition(
    window.getSize().x / 2 + menu_text.getGlobalBounds().width / 2 - 70,
    window.getSize().y / 5);


  // score

  score_text.setString("Score:"+ std::to_string(score));
  score_text.setFont(font);
  score_text.setCharacterSize(50);
  score_text.setFillColor(sf::Color(255, 255, 255, 255));
  score_text.setPosition(window.getSize().x * 0.7,window.getSize().y* 0.1 );
  //timer
  time_remaining = initial_time;
  timer_text.setString("Time:" + std::to_string(score));
  timer_text.setFont(font);
  timer_text.setCharacterSize(50);
  timer_text.setFillColor(sf::Color(255, 255, 255, 255));
  timer_text.setPosition(window.getSize().x * 0.1, window.getSize().y * 0.1);
  //timer_text.setString("Time: " + std::to_string((int)time_remaining));


  //Game Over
  gameover_text.setString("GAME OVER !! Press Enter to >Retry<");
  gameover_text.setFont(font);
  gameover_text.setCharacterSize(30);
  gameover_text.setFillColor(sf::Color(255, 255, 255, 255));

  gameover_text.setPosition(
    window.getSize().x / 2 - gameover_text.getGlobalBounds().width / 2,
    window.getSize().y / 2 - gameover_text.getGlobalBounds().height / 2);
 

  //highscore
  highscore_text.setString("Highscore: ");
  highscore_text.setFont(font);
  highscore_text.setCharacterSize(50);
  highscore_text.setFillColor(sf::Color(255, 255, 255, 255));

  highscore_text.setPosition(
    window.getSize().x / 2 - menu_text.getGlobalBounds().width / 2 + 20,
    window.getSize().y / 10);

  return true;
}

// UPDATE FUNCTION
void Game::update(float dt)
{
  if (!in_menu && !game_over)
  {
    abs.move(speed, y_speed);
    t           = clock.getElapsedTime().asSeconds();
    sf::Uint8 r = static_cast<sf::Uint8>(std::sin(t * 3.0f) * 127 + 128);
    sf::Uint8 g = static_cast<sf::Uint8>(std::sin(t * 3.0f + 2) * 127 + 128);
    sf::Uint8 b = static_cast<sf::Uint8>(std::sin(t * 3.0f + 4) * 127 + 128);
    abs.setColor(sf::Color(r, g, b));
    timer_running = true;

    abs_spawner -= dt;
    if (abs_spawner <= 0)
    {
     
      abs.setPosition(rand() % 2000, (rand() %300) + 100);
      abs_time = abs_time + 3.f;
      abs_spawner = abs_time;
      speed += 5;
      y_speed += 1;
    }
    spawn_time -= dt;
    if (spawn_time <= 0.f)
    {
      
      spawn();
      spawn_time = 2.f;
    }
    if (timer_running)
    {
      
      time_remaining -= dt;
      spawn_time -= dt;
      if (time_remaining <= 0.f)
      {
        time_remaining = 0.f;
        timer_running  = false;
        // game over: return to menu (or change this to any other behavior)
        game_over = true;
        respawn();
      }
      timer_text.setString("Time: " + std::to_string((int)time_remaining));
    }
    if (score >= 0)
    {
      score_text.setString("Score:" + std::to_string(score));
    }
    
    
    for (int i = 0; i < birds_count; i++)
    {
      birds_in_scene[i].reverse_bird(window, dt);
     
      if (i == 3)
      {
        
        //birds_in_scene[i].setSpeed(rand() % 300, rand() % 300);
        hl_rect.setPosition(birds_in_scene[i].getSprite().getPosition());


      }
      if (i == 5)
      {
        hl_rect_2.setPosition(birds_in_scene[i].getSprite().getPosition());
      }
    }
    
    if (abs_timer_running)
    {
      abs_timer -= dt;
      if (abs_timer <= 0.f)
      {
        abs_timer_running = false;
        abs_timer         = 2.f;
        std::for_each(
          birds_in_scene,
          birds_in_scene + birds_count,
          [](Bird& b) { b.setSpeed(50 + rand() % 10, 10 + rand() % 10); });

      }
      
    }
  }
 
  
}

void Game::render()
{
  if (in_menu)
  {
    window.draw(menu_text);
    window.draw(title_text);
    window.draw(play_option);
    window.draw(quit_option);
    
  }
  else
  {
    window.draw(background);
    window.draw(hl_rect);
    window.draw(hl_rect_2);
    window.draw(score_text);
    window.draw(timer_text);
    window.draw(abs);

    for (int i = 0; i < birds_count; i++)
    {
      birds_in_scene[i].getSprite().setScale(0.35, 0.35);
      window.draw(birds_in_scene[i].getSprite());
      if (i == 3)
      {
       
        hl_rect.setSize(sf::Vector2f(
          birds_in_scene[i].getSprite().getLocalBounds().width/2,
          birds_in_scene[i].getSprite().getLocalBounds().height/2));
        hl_rect.setFillColor(sf::Color(255, 0, 0, 128));

        hl_rect_2.setSize(sf::Vector2f(
          birds_in_scene[i].getSprite().getLocalBounds().width / 2,
          birds_in_scene[i].getSprite().getLocalBounds().height / 2));
        hl_rect_2.setFillColor(sf::Color(255, 0, 0, 128));

      }
      
    }
  
    //bird.setScale(0.25, 0.25);
    
   
  }
  if (game_over)
  {
    
    window.draw(back);
    
    if (score <10)
    {
      gameover_text.setString("You Lose get more than 10 to win!! Press Enter to >Retry<");
      gameover_text.setPosition(
        window.getSize().x / 2 - gameover_text.getGlobalBounds().width / 2 - 10,
        window.getSize().y / 2 - gameover_text.getGlobalBounds().height / 2);
    }
    else
    {
      gameover_text.setString("You Win!! Press Enter "
                              "to >Retry<");
      gameover_text.setPosition(
        window.getSize().x / 2 - gameover_text.getGlobalBounds().width / 2 - 10,
        window.getSize().y / 2 - gameover_text.getGlobalBounds().height / 2);
    
    }

    if (score > highscore)
    {
      highscore = score;
      highscore_text.setString(" New Highscore:" + std::to_string(highscore));
    }
    else
    {
      highscore_text.setString(" Highscore:" + std::to_string(highscore));
    }
    window.draw(gameover_text);
    window.draw(highscore_text);
    
  }
}

void Game::mouseClicked(sf::Event event)
{
  // get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);
  
  // check if in bounds of bird Sprite
  for (int i = 0; i < birds_count; i++)
  {
    if (collisionCheck( click,birds_in_scene[i].getSprite()))
    {
      
      
        birds_in_scene[i].setSpeed(0.f, 0.f);
      
      
      
      if (i==3 || i==5)
      {
        if (score > 0)
        {
          score--;
        }
       
       

      
      
       
      }
      else
      {
        score += birds_in_scene[i].getPoints();
       
      }
      break;
    }
  
  }
  
  if (collisionCheck(click, abs))
  {
    abs_timer_running = true;
    for (int i = 0; i < birds_count; i++)
    {
      birds_in_scene[i].setSpeed(0, 0);
    }
  
  } 
  
  
  
}

void Game::keyPressed(sf::Event event)
{
  if (
    (event.key.code == sf::Keyboard::Left) ||
    (event.key.code == sf::Keyboard::Right))
  {
    play_selected = !play_selected;
    if (play_selected)
    {
      play_option.setString(">Play<");
      quit_option.setString("Quit");
    }
    else
    {
      play_option.setString("Play");
      quit_option.setString(">Quit<");
    }
  }
  else if (event.key.code == sf::Keyboard::Enter)
  {
    if (play_selected)
    {
      in_menu = false;
    }
    else
    {
      window.close();
    }
  }

  if ((event.key.code == sf::Keyboard::Enter) && game_over)
  {
    game_over = false;
    score     = 0;
    

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
  
  
   for (int i = 0; i < birds_count; i++)
  {
     if (birds_in_scene[i].getSprite().getPosition().y > 900)
     {
       birds_in_scene[i].incrementSpeed();
      
      
       birds_in_scene[i].getSprite().setPosition(
         rand() % (window.getSize().x -
                   (int)birds_in_scene[i].getSprite().getGlobalBounds().width),
         rand() %
           (window.getSize().y -
            (int)birds_in_scene[i].getSprite().getGlobalBounds().height - 100));
     }
     
  }
}

void Game:: respawn() {
  for (int i = 0; i < birds_count; i++)
  {
    
       
      birds_in_scene[i].getSprite().setPosition(
        rand() % (window.getSize().x -
                  (int)birds_in_scene[i].getSprite().getGlobalBounds().width),
        rand() %
          (window.getSize().y -
           (int)birds_in_scene[i].getSprite().getGlobalBounds().height - 100));
    //birds_in_scene[i].setSpeed(rand() % 20,rand() % 5);
      timer_running = false;
      time_remaining = 20.f;
      
  }

}
  // remember time 5 birds diff intervals each with seperate score.