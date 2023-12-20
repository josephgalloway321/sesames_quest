#include <raylib.h>
#include "../header/game.hpp"

Game::Game(int SCREEN_WIDTH, int SCREEN_HEIGHT) {
  this -> SCREEN_WIDTH = SCREEN_WIDTH;
  this -> SCREEN_HEIGHT = SCREEN_HEIGHT;

  font = LoadFont("C:/Users/josep/Documents/GitHub/sesames_quest/resources/font/monogram.ttf");

  is_time_to_meow_or_groom = false; 
  meow = false;
  groom = false;
  seconds_until_meow_or_groom = 12;
  srand(time(NULL));

  current_time = 0;
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
    sesame.sleeping();
  }
  else if(IsKeyDown(KEY_O)) {
    timer_until_meow_or_groom.reset_timer();
    sesame.woken();
  }
  else {
    // No keys held down
    // After sitting w/o user input, meow or groom
    handle_meow_or_groom();
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

void Game::handle_meow_or_groom() {
  if(is_time_to_meow_or_groom == false && timer_until_meow_or_groom.is_time_for_event(seconds_until_meow_or_groom)) {
    is_time_to_meow_or_groom = true;
    // Decide to meow or groom
    int random_number = rand() % 2; // 0 = meow, 1 = groom
    if(random_number == 0) {
      meow = true;
    }  
    else {
      groom = true;
    }
  }
  else if(meow && sesame.get_sesame_meowing_current_frame() == 11) {
    is_time_to_meow_or_groom = false;
    meow = false;
    timer_until_meow_or_groom.reset_timer();
  }
  else if(groom && sesame.get_sesame_grooming_current_frame() == 0) {
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

  // TODO: Pass this variable from display_game_information as an argument
  int game_information_width = SCREEN_WIDTH - 1525;
  
  int margin = 10;
  float background_width = game_information_width - margin;
  float background_height = 60;
  
  float background_top_left_position_x = SCREEN_WIDTH - background_width - margin;
  float background_top_left_position_y = SCREEN_HEIGHT - background_height - margin;
  
  int padding_top_left = 8;
  float first_text_top_left_position_x = background_top_left_position_x + padding_top_left;
  float first_text_top_left_position_y = background_top_left_position_y + padding_top_left;

  int padding_between_first_and_second_text = 35;
  float second_text_top_left_position_x = background_top_left_position_x + padding_top_left;
  float second_text_top_left_position_y = background_top_left_position_y + padding_between_first_and_second_text;

  int padding_horizontal_between_text_score = 235;
  float first_score_top_left_position_x = first_text_top_left_position_x + padding_horizontal_between_text_score;
  float first_score_top_left_position_y = first_text_top_left_position_y;
  float second_score_top_left_position_x = second_text_top_left_position_x + padding_horizontal_between_text_score;
  float second_score_top_left_position_y = second_text_top_left_position_y;

  DrawRectangleRounded({
    background_top_left_position_x,
    background_top_left_position_y, 
    background_width, background_height},
    0.3, 6, ORANGE);
  DrawTextEx(font, "Sesame x coordinate (px): ", {first_text_top_left_position_x, first_text_top_left_position_y}, 15, 2, BLACK);
  DrawTextEx(font, pos_x, {first_score_top_left_position_x, first_score_top_left_position_y}, 15, 2, BLACK);
  DrawTextEx(font, "Sesame y coordinate (px): ", {second_text_top_left_position_x, second_text_top_left_position_y}, 15, 2, BLACK);
  DrawTextEx(font, pos_y, {second_score_top_left_position_x, second_score_top_left_position_y}, 15, 2, BLACK);
}


void Game::display_game_information() {
  //int game_information_width = SCREEN_WIDTH - 1525;

  // Draw title
  //DrawRectangleRounded({1525, 10, 285, 145}, 0.3, 6, PINK);
  DrawTextEx(font, "Sesame's", {1550, 10}, 60, 2, WHITE);
  DrawTextEx(font, "Quest", {1600, 75}, 60, 2, WHITE);

  // Draw best time
  DrawTextEx(font, "Best Time", {1575, 200}, 40, 2, WHITE);
  DrawRectangleRounded({1525, 250, 285, 70}, 0.3, 6, PINK);

  // Draw current time
  DrawTextEx(font, "Current Time", {1540, 400}, 40, 2, WHITE);
  DrawRectangleRounded({1525, 450, 285, 70}, 0.3, 6, PINK);

  // Draw text for player
  DrawRectangleRounded({1525, 600, 285, 250}, 0.3, 6, PINK);

  // Draw Sesame's coordinates
  display_sesame_coordinates();
}

void Game::show_apartment() {
  // Write logic determining which frame of apartment to show based on 
  // Sesame interacting with opening/closing doors

  apartment.show_laundry_kitchen_rooms();
  apartment.show_living_room();
  apartment.show_bathroom_closets();
  apartment.show_bedroom();
}

void Game::reset_game() {
  current_time = 0;
  sesame.reset_sesame_position();
}
