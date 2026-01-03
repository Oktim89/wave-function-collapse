#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <string>
#include <vector>
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
  void scan();
  void collapse();
  void render(sf::RenderWindow& window);
  void propogte();
  void update();
  int index(int x, int y);
  sf::RectangleShape& getShape(TileType type);
  void removeElement(std::vector<TileType>& vec, TileType value);
  int num_tiles = 3;
  std::vector<Cell> grid;
  std::vector<sf::RectangleShape> tiles;
  int DIM = 20;
  sf::RectangleShape red;
  sf::RectangleShape blue;
  sf::RectangleShape green;
  sf::RectangleShape blank;
  Cell cell;
  float w                = 1080;
  float h                = 720;
  float entropy          = 0.f;
  int lowest_e           = 0;
  int lowestEntropyIndex = 0;
  int dx[4]              = { 0, 1, 0, -1 };
  int dy[4]              = { -1, 0, 1, 0 };
  bool finished          = false;
};
