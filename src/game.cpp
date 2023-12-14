#include <raylib.h>
#include "../header/game.hpp"

Game::Game() {

}

Game::~Game() {

}

int Game::get_screen_width() const {
  return SCREEN_WIDTH;
}

int Game::get_screen_height() const {
  return SCREEN_HEIGHT;
}
