#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <map>
#include <string>
enum class TileType
{
  Blank,
  Red,
  Blue,
  Green
};
struct Cell
{
  bool collapsed = false;
  std::vector<TileType> options;
};
class WFC
{
 public:
  WFC();
  ~WFC();
  bool init();
  void render(sf::RenderWindow& window);
  int index(int x, int y);
  sf::RectangleShape& getShape(TileType type);
  int num_tiles = 3;
  std::vector<Cell> grid;
  std::vector<sf::RectangleShape> tiles;
  int DIM = 2;
  sf::RectangleShape red;
  sf::RectangleShape blue;
  sf::RectangleShape green;
  sf::RectangleShape blank;
  Cell cell;
};




