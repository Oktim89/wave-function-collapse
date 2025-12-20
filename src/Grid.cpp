#include "Grid.h"
#include <iostream>
#include <algorithm>

Grid::Grid() {
  srand(time(NULL));
}
Grid::~Grid() {}
bool Grid::init()
{

 
   for (int i = 0; i < X - 1; i++)
  {
    for (int j = 0; j < Y - 1; j++)
    {
      grid[i][j] = 1;
    
    }
    std::cout << std::endl;
  }


	return true;
}



sf::FloatRect Grid::generateRoom()
{
  int roomWidth = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;
  int roomHeight = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;
  int x_gridPos = rand() % (int(X) - roomWidth - 1) + 1;
  int y_gridPos = rand() % (int(Y) - roomHeight - 1) + 1;
  return sf::FloatRect(x_gridPos, y_gridPos, roomWidth, roomHeight);
}

bool Grid::placeRoom(sf::FloatRect newRoom)
{

    for (int i = newRoom.left - 1; i < newRoom.left + newRoom.width + 1; i++)
  {
    for (int j = newRoom.top - 1; j < newRoom.top + newRoom.height + 1; j++)
    {
      if (grid[i][j] == 0)
      {
        return false;
      }
    }
  }
    for (int i = newRoom.left; i < newRoom.left + newRoom.width; i++)
  {
    for (int j = newRoom.top; j < newRoom.top + newRoom.height; j++)
    {
      grid[i][j] = 0;
    }
  }
  return true;
}

void Grid::connectRooms(
  sf::FloatRect room1, sf::FloatRect room2, int hallway_width)
{
  // start from center of room1 to center of room2
    int x1 = room1.left + room1.width / 2;
  int y1 = room1.top + room1.height / 2;
  int x2 = room2.left + room2.width / 2;
  int y2 = room2.top + room2.height / 2;
  if (rand() % 2 == 0)
  {
      //
    for (int x = std::min(x1, x2); x <= std::max(x1, x2); x++)
    {
      for (int w = -hallway_width / 2; w <= hallway_width / 2; w++)
      {
        grid[x][y1 + w] = 0;
      }
    }
    for (int y = std::min(y1, y2); y <= std::max(y1, y2); y++)
    {
      for (int w = -hallway_width / 2; w <= hallway_width / 2; w++)
      {
        grid[x2 + w][y] = 0;
      }
    }
  }
  else
  {
    for (int y = std::min(y1, y2); y <= std::max(y1, y2); y++)
    {
      for (int w = -hallway_width / 2; w <= hallway_width / 2; w++)
      {
        grid[x1 + w][y] = 0;
      }
    }
    for (int x = std::min(x1, x2); x <= std::max(x1, x2); x++)
    {
      for (int w = -hallway_width / 2; w <= hallway_width / 2; w++)
      {
        grid[x][y2 + w] = 0;
      }
    }
  }
}

void Grid::generateDungeon() {
    for (int i = 0; i < MAXROOMS; i++) {
        sf::FloatRect newRoom = generateRoom();
        if (placeRoom(newRoom)) {
            if (roomCount > 0) {
                connectRooms(rooms[roomCount - 1], newRoom);
            }
            rooms.push_back(newRoom);
            roomCount++;
        }
    }
    printGrid();

}

void Grid::printGrid() {

    for (int i = 0; i < X - 1; i++)
  {
    for (int j = 0; j < Y - 1; j++)
    {
      std::cout << grid[i][j];
    }
    std::cout << std::endl;
  }
}

