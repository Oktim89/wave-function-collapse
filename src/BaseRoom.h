#pragma once

#include <SFML/Graphics.hpp>
class BaseRoom
{
 public:
  BaseRoom();
  ~BaseRoom();
  bool init();
  void update(float dt);
  void render();



 private:

};
