#include "WFC.h"


WFC::WFC()
{
  srand(time(NULL));
}

WFC::~WFC() {}

bool WFC::init()
{
  red.setSize(sf::Vector2f(50, 50));
  blue.setSize(sf::Vector2f(50, 50));
  green.setSize(sf::Vector2f(50, 50));
  blank.setSize(sf::Vector2f(50, 50));
  black.setSize(sf::Vector2f(50, 50));

  red.setFillColor(sf::Color::Red);
  blue.setFillColor(sf::Color::Blue);
  green.setFillColor(sf::Color::Green);
  blank.setFillColor(sf::Color::White);
  black.setFillColor(sf::Color::Black);
 

  grid.resize(DIM * DIM);
  for (Cell& sell : grid)
  {
    sell.collapsed = false;
    sell.options   = {
      TileType::Red, TileType::Blue, TileType::Green
    };
  }
  
  


  w = w / DIM;
  h = h / DIM;

  return true;
}

void WFC::scan()
{
  lowest_e = INT_MAX;
  possible_pos.clear();

  for (int i = 0; i < DIM * DIM; i++)
  {
    Cell& cell = grid[i];
    if (cell.collapsed)
      continue;

    int entropy = cell.options.size();
    if (entropy < lowest_e)
    {
      lowest_e = entropy;
      possible_pos.clear();
      possible_pos.push_back(i);
    }
    else if (entropy == lowest_e)
    {
      possible_pos.push_back(i);
    }
  }
}

void WFC::collapse()
{
  if (possible_pos.empty())
  {
    finished = true;
    return;
  }

  int chosenIndex = possible_pos[rand() % possible_pos.size()];
  Cell& cell      = grid[chosenIndex];

  TileType chosen = cell.options[rand() % cell.options.size()];
  cell.options    = { chosen };
  cell.collapsed  = true;

  propagate(chosenIndex);
}


void WFC::propagate(int startIndex)
{
  std::vector<int> queue;
  queue.push_back(startIndex);

  while (!queue.empty())
  {
    int q = queue.back();
    queue.pop_back();

    int cx = q % DIM;
    int cy = q / DIM;

    TileType forbidden = grid[q].options[0];

    for (int d = 0; d < 4; d++)
    {
      int nx = cx + dx[d];
      int ny = cy + dy[d];

      if (nx < 0 || ny < 0 || nx >= DIM || ny >= DIM)
        continue;

      int ni          = index(nx, ny);
      Cell& neighbour = grid[ni];

      if (neighbour.collapsed)
        continue;

      int before = neighbour.options.size();
      removeElement(neighbour.options, forbidden);

      if (neighbour.options.empty())
      {
        reset();
        return;
      }

      if (neighbour.options.size() < before)
      {
        queue.push_back(ni);
      }

      if (neighbour.options.size() == 1)
      {
        neighbour.collapsed = true;
        queue.push_back(ni);
      }
    }
  }
}

void WFC::update()
{
  
  if (!finished)
  {
    scan();
    collapse();

    finished = true;
    for (Cell& cell : grid)
    {
      if (!cell.collapsed)
      {
        finished = false;
        break;
      }
    }
  }
 
}

void WFC::render(sf::RenderWindow& window)
{
  for (int y = 0; y < DIM; y++)
  {
    for (int x = 0; x < DIM; x++)
    {
      Cell& cell = grid[index(x, y)];

      TileType drawType = cell.collapsed ? cell.options[0] : TileType::Blank;

      sf::RectangleShape& shape = getShape(drawType);
      shape.setPosition(x * w, y * h);
      shape.setSize({ w, h });
      shape.setOutlineThickness(1.f);
      shape.setOutlineColor(sf::Color(50, 50, 50)); // dark grey

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
    case TileType::Black:
    {
      return black;
    }
    break;
    default:
      return blank;
  }
}
void WFC::removeElement(std::vector<TileType>& vec, TileType value)
{
  vec.erase(std::remove(vec.begin(), vec.end(), value), vec.end());
}

void WFC::reset() {
  for (Cell& sell : grid)
  {
    sell.collapsed = false;
    sell.options   = {
       TileType::Red, TileType::Blue, TileType::Green
    };
  }
  possible_pos.clear();


}


bool WFC::contains(const std::vector<TileType>& v, TileType value)
{
  return std::find(v.begin(), v.end(), value) != v.end();
}
