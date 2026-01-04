#pragma once
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <iostream>
#include <vector>
enum class Tile
{
  Blank,
  Red,
  Blue,
  Green
};
struct Cel_l
{
  bool collapsed = false;
  std::vector<Tile> options;
};
class WFCinit
{
 public:
  WFCinit();
  ~WFCinit();
  bool init();
  void scan();
  void collapse();
  void render(sf::RenderWindow& window);
  void propogte();
  void update();
  void reset();
  int index(int x, int y);
  sf::RectangleShape& getShape(Tile type);
  void removeElement(std::vector<Tile>& vec, Tile value);
  bool contains(const std::vector<Tile>& v, Tile value);
  std::vector<Cel_l> grid;
  int DIM    = 10;
  int random = 0;
  sf::RectangleShape red;
  sf::RectangleShape blue;
  sf::RectangleShape green;
  sf::RectangleShape blank;
  float w = 1080;
  float h = 720;

  int lowest_e           = 0;
  int lowestEntropyIndex = 0;
  int dx[4]              = { 0, 1, 0, -1 };
  int dy[4]              = { -1, 0, 1, 0 };
  bool finished          = false;
};
