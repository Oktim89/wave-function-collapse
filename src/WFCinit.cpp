#include "WFCinit.h"

WFCinit::WFCinit()
{
  srand(time(NULL));
}

WFCinit::~WFCinit() {}

bool WFCinit::init()
{
  red.setSize(sf::Vector2f(50, 50));
  blue.setSize(sf::Vector2f(50, 50));
  green.setSize(sf::Vector2f(50, 50));
  blank.setSize(sf::Vector2f(50, 50));

  red.setFillColor(sf::Color::Red);
  blue.setFillColor(sf::Color::Blue);
  green.setFillColor(sf::Color::Green);
  blank.setFillColor(sf::Color::White);

  grid.resize(DIM * DIM);
  for (Cel_l& sell : grid)
  {
    sell.collapsed = false;
    sell.options   = {
      Tile::Blank, Tile::Red, Tile::Blue, Tile::Green
    };
  }

  w = w / DIM;
  h = h / DIM;

  return true;
}
void WFCinit::scan()
{
  lowest_e           = INT_MAX;
  lowestEntropyIndex = -1;


  for (int i = 0; i < DIM; i++)
  {
    for (int j = 0; j < DIM; j++)
    {
      Cel_l& current_cell = grid[index(i, j)];
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
void WFCinit::collapse()
{
  if (lowestEntropyIndex == -1)
  {
    // reset()
  }


  Cel_l& cell      = grid[lowestEntropyIndex];
  Tile chosen = cell.options[(rand() % cell.options.size())];
  // for (int i = 0; i < sizeof(dx) / sizeof(dx[0]); i++)
  //{
  //   int x  = dx[i];
  //   int y  = dy[i];
  //   int in = random+ index(x, y);
  //   if (in < 0 || in >= DIM * DIM)
  //   {
  //     continue;
  //   }
  //   Cel_l& neighbour = grid[in];
  //   if (contains(neighbour.options, chosen)){
  //     srand(time(NULL));
  //     if (cell.options.size() > 1)
  //     {
  //       removeElement(cell.options, chosen);
  //     }
  //     chosen = cell.options[rand() % cell.options.size()];
  //   }

  //}

 cell.options.clear();
  cell.options.push_back(chosen);
  cell.collapsed = true;
}

void WFCinit::propogte()
{
  std::vector<int> queue;
  queue.push_back(lowestEntropyIndex);
  if (!queue.empty())
  {
    int q = queue.front();
    queue.erase(queue.begin());
    Cel_l& current_cell = grid[q];
    Tile forbidden = current_cell.options.front();
    for (int i = 0; i < sizeof(dx) / sizeof(dx[0]); i++)
    {
      int x  = dx[i];
      int y  = dy[i];
      int in = q + index(x, y);
      if (in < 0 || in >= DIM * DIM)
      {
        continue;
      }
      Cel_l& neigbour = grid[in];
      int n_size     = neigbour.options.size();
      if (neigbour.options.size() > 1)
      {
        removeElement(neigbour.options, forbidden);
      }

      if (neigbour.options.size() == 1)
      {
        queue.push_back(in);
        neigbour.collapsed = true;
        if (neigbour.options.front() == current_cell.options.front())
        {
          reset();
          std::cout << "Reset called \n";
        }
      }
    }
  }
}
void WFCinit::update()
{
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
        Cel_l& current_cell = grid[index(i, j)];
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
      }
    }
  }
}

void WFCinit::render(sf::RenderWindow& window)
{
  for (int y = 0; y < DIM; y++)
  {
    for (int x = 0; x < DIM; x++)
    {
      Cel_l& cell = grid[index(x, y)];

      Tile drawType = cell.collapsed ? cell.options[0] : Tile::Blank;

      sf::RectangleShape& shape = getShape(drawType);
      shape.setPosition(x * w, y * h);
      shape.setSize({ w, h });
      shape.setOutlineThickness(1.f);
      shape.setOutlineColor(sf::Color(50, 50, 50)); // dark grey

      window.draw(shape);
    }
  }
}

int WFCinit::index(int x, int y)
{
  return x + y * DIM;
}

sf::RectangleShape& WFCinit::getShape(Tile type)
{
  switch (type)
  {
    case Tile::Red:
    {
      return red;
    }
    break;

    case Tile::Blue:
    {
      return blue;
    }
    break;
    case Tile::Green:
    {
      return green;
    }
    break;
    case Tile::Blank:
    {
      return blank;
    }
    break;
    default:
      return blank;
  }
}
void WFCinit::removeElement(std::vector<Tile>& vec, Tile value)
{
  vec.erase(std::remove(vec.begin(), vec.end(), value), vec.end());
}

void WFCinit::reset()
{
  for (Cel_l& sell : grid)
  {
    sell.collapsed = false;
    sell.options   = {
      Tile::Blank, Tile::Red, Tile::Blue, Tile::Green
    };
  }

}

bool WFCinit::contains(const std::vector<Tile>& v, Tile value)
{
  return std::find(v.begin(), v.end(), value) != v.end();
}
