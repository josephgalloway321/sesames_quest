#include <raylib.h>
#include "../header/game.hpp"


Game::Game(int SCREEN_WIDTH, int SCREEN_HEIGHT) {
  this -> SCREEN_WIDTH = SCREEN_WIDTH;
  this -> SCREEN_HEIGHT = SCREEN_HEIGHT;
}

Game::~Game() {
  
}

void Game::handle_keyboard_input() {
  // Handle keys held down
  if(IsKeyDown(KEY_LEFT)) {
    sesame.walk_left();
  }
  else if(IsKeyDown(KEY_DOWN)) {
    sesame.walk_down();
  }
  else if(IsKeyDown(KEY_RIGHT)) {
    sesame.walk_right();
  }
  else if(IsKeyDown(KEY_UP)) {
    sesame.walk_up();
  }
  else {
    // No keys held down
    sesame.sitting();
  }

  // Handle keys pressed
  int key_pressed = GetKeyPressed();
  switch(key_pressed) {
    case KEY_SPACE: {
      toggle_full_screen_window(SCREEN_WIDTH, SCREEN_HEIGHT);
    }
    default:
      break;
  }
}

void Game::toggle_full_screen_window(int window_width, int window_height) {
  if(!IsWindowFullscreen()) {
    int monitor = GetCurrentMonitor();
    SetWindowSize(GetMonitorWidth(monitor), GetMonitorHeight(monitor));
    ToggleFullscreen();
  }
  else {
    ToggleFullscreen();
    SetWindowSize(window_width, window_height);
  }
}
