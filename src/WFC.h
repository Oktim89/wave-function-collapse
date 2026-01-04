#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
enum class TileType
{
  Blank,
  Red,
  Blue,
  Green,
  Black
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
  void scan();
  void collapse();
  void render(sf::RenderWindow& window);
  void propagate(int chosenIndex);
  void update();
  int index(int x, int y);
  sf::RectangleShape& getShape(TileType type);
  void removeElement(std::vector<TileType>& vec, TileType value);
  bool contains(const std::vector<TileType>& v, TileType value);
  void reset();
  std::vector<Cell> grid;
  int DIM =10;
  int random = 0;
  std::vector<int> possible_pos;
  sf::RectangleShape red;
  sf::RectangleShape blue;
  sf::RectangleShape green;
  sf::RectangleShape blank;
  sf::RectangleShape black;
  float w                = 1080;
  float h                = 720;

  int lowest_e           = 0;
  int lowestEntropyIndex = 0;
  int dx[4]              = { 0, 1, 0, -1 };
  int dy[4]              = { -1, 0, 1, 0 };
  bool finished          = false;
};
