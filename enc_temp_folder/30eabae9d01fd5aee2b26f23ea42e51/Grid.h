#pragma once
#include <SFML/Graphics.hpp>
class Grid
{
 public:
  Grid();
  ~Grid();
  bool init();
  void update(float dt);
  void render();

 void Size(float X, float Y);
  float X_value = 0;
  float Y_value = 0;

  int grid[45][45];
  
private:
  float X = 45;
  float Y = 45;

};
