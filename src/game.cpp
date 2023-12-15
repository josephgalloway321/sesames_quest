#include <raylib.h>
#include "../header/game.hpp"


Game::Game() {
  screen_width = 1800;
  screen_height = 1012;
}

Game::~Game() {
  
}

int Game::get_screen_width() const {
  return screen_width;
}

int Game::get_screen_height() const {
  return screen_height;
}

void Game::handle_keyboard_input() {
  int key_pressed = GetKeyPressed();

  switch(key_pressed) {
    case KEY_LEFT: {
      //sesame.walk_left();
    } break;
    
    case KEY_DOWN: {
      //sesame.walk_down();
    } break;

    case KEY_RIGHT: {
      //sesame.walk_right();
    } break;

    case KEY_UP: {
      //sesame.walk_up();
    } break;

    case 0: {
      //sesame.sitting();
    }

    default:
      break;
  }
}
