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

  w = w / DIM;
  h = h / DIM;

  return true;
}
void WFC::scan()
{
  lowest_e           = INT_MAX;
  lowestEntropyIndex = -1;

  for (int i = 0; i < DIM; i++)
  {
    for (int j = 0; j < DIM; j++)
    {
      Cell& current_cell = grid[index(i, j)];
      if (current_cell.collapsed)
      {
        continue;
      }
      int entropy = current_cell.options.size();
      if (entropy < lowest_e)
      {
        lowest_e           = entropy;
        lowestEntropyIndex = index(i, j);
      }
    }
  }
}
void WFC::collapse()
{
  if (lowestEntropyIndex == -1)
  {
    // reset()
  }
  Cell& cell = grid[lowestEntropyIndex];

  TileType chosen = cell.options[rand() % cell.options.size()];

  cell.options.clear();
  cell.options.push_back(chosen);
  cell.collapsed = true;
}

void WFC::propogte()
{
  std::vector<int> queue;
  queue.push_back(lowestEntropyIndex);
  if (!queue.empty())
  {
    int q = queue.front();
    queue.erase(queue.begin());
    Cell& current_cell = grid[q];
    TileType forbidden = current_cell.options.front();
    for (int i = 0; i < sizeof(dx) / sizeof(dx[0]); i++)
    {
      int x  = dx[i];
      int y  = dy[i];
      int in = q + index(x, y);
      if (in < 0 || in >= DIM * DIM)
      {
        continue;
      }
      Cell& neigbour = grid[in];
      int n_size     = neigbour.options.size();
      if (neigbour.options.size() > 1)
      {
        removeElement(neigbour.options, forbidden);
      }

      if (neigbour.options.size() == 1)
      {
        queue.push_back(in);
        neigbour.collapsed = true;
      }
    }
  }
}
void WFC::update()
{
  float w = 800 / DIM;
  float h = 800 / DIM;
  if (!finished)
  {
    scan();
    collapse();
    propogte();
    for (int i = 0; i < DIM; i++)
    {
      for (int j = 0; j < DIM; j++)
      {
        int in             = index(j, i);
        Cell& current_cell = grid[index(i, j)];
        if (current_cell.collapsed)
        {
          finished = true;
          continue;
        }
        else
        {
          finished = false;
          break;
        }
      }
      if (!finished)
      {
        std::cout << "lowest_e: " << lowest_e << std::endl;
        std::cout << "Lowest index" << lowestEntropyIndex << std::endl;
      }
    }
  }

  std::cout << "lowest_e: " << lowest_e << std::endl;
  std::cout << "Lowest index" << lowestEntropyIndex << std::endl;
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
    break;
    default:
      return blank;
  }
}
void WFC::removeElement(std::vector<TileType>& vec, TileType value)
{
  vec.erase(std::remove(vec.begin(), vec.end(), value), vec.end());
}
