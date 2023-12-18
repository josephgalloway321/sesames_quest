#include <raylib.h>
#include "../header/game.hpp"

Game::Game(int SCREEN_WIDTH, int SCREEN_HEIGHT) {
  this -> SCREEN_WIDTH = SCREEN_WIDTH;
  this -> SCREEN_HEIGHT = SCREEN_HEIGHT;
  is_time_to_meow_or_groom = false; 
  meow = false;
  groom = false;
  seconds_until_meow_groom = 12;
  seconds_meow_duration = 5;
  seconds_groom_duration = 6;
  font = LoadFont("C:/Users/josep/Documents/GitHub/sesames_quest/resources/font/monogram.ttf");
  srand(time(NULL));
}

Game::~Game() {
  UnloadFont(font);
}

void Game::check_if_sesame_inside_screen() {
  // Check if Sesame moves outside of the screen
  std::vector<std::vector<float>> coordinates = sesame.get_sesame_frame_coordinates();
  float position_top_left_x = coordinates[0][0];
  float position_top_left_y = coordinates[0][1];
  float position_bottom_right_x = coordinates[1][0];
  float position_bottom_right_y = coordinates[1][1];

  // If Sesame went out of bounds, track direction
  if(position_top_left_x <= 0) {
    // Moved too far left
    sesame.reverse_walk_left();
  }
  else if(position_top_left_y <= 0) {
    // Moved too far up
    sesame.reverse_walk_up();
  }
  else if(position_bottom_right_x >= SCREEN_WIDTH) {
    // Moved too far right
    sesame.reverse_walk_right();
  }
  else if(position_bottom_right_y >= SCREEN_HEIGHT) {
    // Moved too far down
    sesame.reverse_walk_down();
  }
}

void Game::handle_keyboard_input() {
  // Handle keys held down and check if Sesame is inside screen
  if(IsKeyDown(KEY_LEFT)) {
    timer_until_meow_or_groom.reset_timer();
    sesame.walk_left();
  }
  else if(IsKeyDown(KEY_DOWN)) {
    timer_until_meow_or_groom.reset_timer();
    sesame.walk_down();
  }
  else if(IsKeyDown(KEY_RIGHT)) {
    timer_until_meow_or_groom.reset_timer();
    sesame.walk_right();
  }
  else if(IsKeyDown(KEY_UP)) {
    timer_until_meow_or_groom.reset_timer();
    sesame.walk_up();
  }
  else if(IsKeyDown(KEY_P)) {
    timer_until_meow_or_groom.reset_timer();
    //sesame.grooming();
  }
  else {
    // No keys held down
    // After sitting w/o user input, meow or groom
    if(is_time_to_meow_or_groom == false && timer_until_meow_or_groom.is_time_for_event(seconds_until_meow_groom)) {
      is_time_to_meow_or_groom = true;
      // Decide to meow or groom
      int random_number = rand() % 2; // 0 = meow, 1 = groom
      if(random_number == 0) {
        meow = true;
        timer_meow_duration.reset_timer();  // Start meow duration timer to hold meow
      }  
      else {
        groom = true;
        timer_groom_duration.reset_timer();  // Start groom duration timer to hold groom
      }
    }
    else if(meow && timer_meow_duration.is_time_for_event(seconds_meow_duration)) {
      is_time_to_meow_or_groom = false;
      meow = false;
      timer_until_meow_or_groom.reset_timer();
    }
    else if(groom && timer_groom_duration.is_time_for_event(seconds_groom_duration)) {
      is_time_to_meow_or_groom = false;
      groom = false;
      timer_until_meow_or_groom.reset_timer();
    }

    if(meow) {
      sesame.meowing();
    }
    else if(groom) {
      sesame.grooming();
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

void Game::display_sesame_coordinates() {
  std::vector<std::vector<float>> coordinates = sesame.get_sesame_frame_coordinates();
  int position_top_left_x = (int)coordinates[0][0];
  int position_top_left_y = (int)coordinates[0][1];

  char pos_x[50];
  char pos_y[50];
  sprintf(pos_x, "%d", position_top_left_x);
  sprintf(pos_y, "%d", position_top_left_y);

  float background_width = 350;
  float background_height = 75;
  int margin = 10;
  float background_top_left_position_x = SCREEN_WIDTH - background_width - margin;
  float background_top_left_position_y = SCREEN_HEIGHT - background_height - margin;
  
  int padding = 10;
  float first_text_top_left_position_x = background_top_left_position_x + padding;
  float first_text_top_left_position_y = background_top_left_position_y + padding;

  DrawRectangleRounded({
    background_top_left_position_x,
    background_top_left_position_y, 
    background_width, background_height},
    0.3, 6, ORANGE);
  DrawTextEx(font, "Sesame x coordinate: ", {
                                             first_text_top_left_position_x, 
                                             first_text_top_left_position_y},
                                             20, 2, BLACK);
  DrawTextEx(font, pos_x, {750, 515}, 25, 2, BLACK);
  DrawTextEx(font, "Sesame y coordinate: ", {515, 545}, 20, 2, BLACK);
  DrawTextEx(font, pos_y, {750, 545}, 25, 2, BLACK);
}
