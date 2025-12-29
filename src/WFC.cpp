#include "WFC.h"


WFC::WFC() {}

WFC::~WFC() {}


bool WFC::init() {
  red.setSize(sf::Vector2f(50, 50));
  blue.setSize(sf::Vector2f(50, 50));
  green.setSize(sf::Vector2f(50, 50));
  blank.setSize(sf::Vector2f(50, 50));

  red.setFillColor(sf::Color::Red);
  blue.setFillColor(sf::Color::Blue);
  green.setFillColor(sf::Color::Green);
  blank.setFillColor(sf::Color::White);

  tiles.push_back(blank);
  tiles.push_back(red);
  tiles.push_back(blue);
  tiles.push_back(green);
  
  
  grid.resize(DIM * DIM);
  for (Cell& sell : grid)
  {
    sell.collapsed = false;
    sell.options   = {
      TileType::Blank, TileType::Red, TileType::Blue, TileType::Green
    };
  }
  grid[index(0,0)].collapsed = true;
  grid[index(0, 0)].options[0] = TileType::Green;
  float w = 400 / DIM;
  float h = 400 / DIM;
  for (int i = 0; i < DIM; i++)
  {
    for (int j = 0; j < DIM; j++)
    {
      Cell& current_cell = grid[index(i, j)];
      if (current_cell.collapsed)
      {
        grid[index(i, j)].options.clear();
        grid[index(i, j)].options.push_back(TileType::Red);
        TileType inde = current_cell.options[0];
       
        

       

      }
      else
      {
        TileType index = current_cell.options[0];
        
      
      }
     
    }
  }

  for (Cell& cell : grid)
  {
    std::cout << cell.collapsed;
   
  }
  return true;
}
void WFC::render(sf::RenderWindow& window)
{
  float w = 400.f / DIM;
  float h = 400.f / DIM;

  for (int y = 0; y < DIM; y++)
  {
    for (int x = 0; x < DIM; x++)
    {
      Cell& cell = grid[index(x, y)];

      TileType drawType = cell.collapsed ? cell.options[0] : TileType::Blank;

      sf::RectangleShape& shape = getShape(drawType);
      shape.setPosition(x * w, y * h);
      shape.setSize({ w, h });

      window.draw(shape);
    }
  }
}



int WFC::index(int x, int y)
{
  return x + y * DIM;
}

sf::RectangleShape& WFC::getShape(TileType type)
{
    switch (type)
    {
      case TileType::Red:
      {
        return red;
      }
      break;

       
    case TileType::Blue:
      {
      return blue;
    }
      break;
    case TileType::Green:
    {
      return green;
    }
    break;
    case TileType::Blank:
    {
      return blank;
    }
    break; 
    default:
        return blank;
    }
}



