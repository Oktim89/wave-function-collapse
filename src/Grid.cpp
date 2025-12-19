#include "Grid.h"
#include <iostream>
Grid::Grid() {}
Grid::~Grid() {}
bool Grid::init()
{

 
   for (int i = 0; i < X - 1; i++)
  {
    for (int j = 0; j < Y - 1; j++)
    {
      grid[i][j] = 0;
      std::cout << grid[i][j];
    }
    std::cout << std::endl;
  }


	return true;
}