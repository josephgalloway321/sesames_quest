#include <raylib.h>
#include "../header/game.hpp"


Game::Game(int SCREEN_WIDTH, int SCREEN_HEIGHT) {
  this -> SCREEN_WIDTH = SCREEN_WIDTH;
  this -> SCREEN_HEIGHT = SCREEN_HEIGHT;
  is_time_to_meow = false; 
  seconds_until_meow = 12;
  seconds_meow_duration = 4;
  is_sesame_inside_screen = true;
}

Game::~Game() {
}

void Game::test() {
  int position_x_sesame = sesame.get_sesame_position_x();
  int position_y_sesame = sesame.get_sesame_position_y();
  DrawCircle(position_x_sesame, position_y_sesame, 5.0, GREEN);
}

void Game::check_if_sesame_inside_screen() {
  int position_x = sesame.get_sesame_position_x();
  int position_y = sesame.get_sesame_position_y();
  if(position_x > 0 && position_x < SCREEN_WIDTH && position_y > 0 && position_y < SCREEN_HEIGHT) {
    is_sesame_inside_screen = true;
  }
  else{
    DrawRectangle(300, 300, 200, 200, RED);
    is_sesame_inside_screen = false;
  }
}

void Game::handle_keyboard_input() {
  // Handle keys held down and check if Sesame is outside screen
  if(IsKeyDown(KEY_LEFT) && is_sesame_inside_screen) {
    timer_until_meow.reset_timer();
    sesame.walk_left();
  }
  else if(IsKeyDown(KEY_DOWN) && is_sesame_inside_screen) {
    timer_until_meow.reset_timer();
    sesame.walk_down();
  }
  else if(IsKeyDown(KEY_RIGHT) && is_sesame_inside_screen) {
    timer_until_meow.reset_timer();
    sesame.walk_right();
  }
  else if(IsKeyDown(KEY_UP) && is_sesame_inside_screen) {
    timer_until_meow.reset_timer();
    sesame.walk_up();
  }
  else {
    // No keys held down
    // After 5 seconds of sitting, meow once
    if(is_time_to_meow == false && timer_until_meow.is_time_for_event(seconds_until_meow)) {
      is_time_to_meow = true;
      timer_meow_duration.reset_timer();  // Start meow duration timer to hold meow
    }
    else if(is_time_to_meow && timer_meow_duration.is_time_for_event(seconds_meow_duration)) {
      is_time_to_meow = false;
      timer_until_meow.reset_timer();
    }

    // When it's time to meow, meow for seconds_meow_duration
    if(is_time_to_meow) {
      sesame.meowing();
    }
    else {
      sesame.sitting();
    }    
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
