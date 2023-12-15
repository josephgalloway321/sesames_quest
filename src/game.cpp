#include <raylib.h>
#include "../header/game.hpp"

Game::Game() {
  screen_width = 1800;
  screen_height = 1012;
}

Game::~Game() {
  
}

int Game::get_screen_width() {
  return screen_width;
}

int Game::get_screen_height() {
  return screen_height;
}
