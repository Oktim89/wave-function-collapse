#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
struct Grid
{
  bool collapsed = false;
  int options[3] = { 0, 1, 2 };

};
class WFC
{
 public:
  WFC();
  ~WFC();
  bool init();
  std::vector<Grid> grid;
  int DIM = 2;
  sf::RectangleShape red;
  sf::RectangleShape blue;
  sf::RectangleShape green;

};
