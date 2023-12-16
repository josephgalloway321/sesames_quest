#include <raylib.h>
#include "../header/game.hpp"


Game::Game(int SCREEN_WIDTH, int SCREEN_HEIGHT) {
  this -> SCREEN_WIDTH = SCREEN_WIDTH;
  this -> SCREEN_HEIGHT = SCREEN_HEIGHT;
  is_time_example = false; 
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
    if(is_time_example == false && timer_example.is_time_for_event(5.0)) {
      is_time_example = true;
      timer_draw_rect.reset_timer();
    }
    else if(is_time_example && timer_draw_rect.is_time_for_event(5.0)) {
      is_time_example = false;
      timer_example.reset_timer();
    }

    // When it's time to draw rect, draw it for 3 seconds
    if(is_time_example) {
      DrawRectangle(50, 50, 100, 100, RED);
    }
    else {
      DrawRectangle(50, 50, 100, 100, WHITE);
    }

    sesame.sitting();
    // No keys held down
    // After 5 seconds of sitting, meow once
    /*
    if(timer_to_start_meow(5.0).is_time_for_event()) {
      //is_time_to_meow = true;
      sesame.meowing();
      //timer_meow_duration(2.0);  // Begin timer for meow duration
    }
    else {
      sesame.sitting();
    }
    */

    /*
    if(is_time_to_meow) {
      sesame.meowing();
    }
    else {
      sesame.sitting();
    }
    */
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
