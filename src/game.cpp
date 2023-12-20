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
  best_time = 0;
  start_time = 120;
  current_time = start_time;
  is_game_over = false;
  is_successful = false;
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

void Game::draw_sesame_coordinates(int game_information_width, int game_information_start_x) {
  std::vector<std::vector<float>> coordinates = sesame.get_sesame_frame_coordinates();
  int position_top_left_x = (int)coordinates[0][0];
  int position_top_left_y = (int)coordinates[0][1];

  char pos_x[50];
  char pos_y[50];
  sprintf(pos_x, "%d", position_top_left_x);
  sprintf(pos_y, "%d", position_top_left_y);
  
  int margin = 10;
  float background_width = game_information_width - 20;
  float background_height = 60;
  
  float background_top_left_position_x = game_information_start_x + margin;
  float background_top_left_position_y = SCREEN_HEIGHT - background_height - margin;
  
  int padding_horizontal_vertical_between_border_text = 8;
  float first_text_top_left_position_x = background_top_left_position_x + padding_horizontal_vertical_between_border_text;
  float first_text_top_left_position_y = background_top_left_position_y + padding_horizontal_vertical_between_border_text;

  int padding_vertical_between_first_and_second_text = 35;
  float second_text_top_left_position_x = background_top_left_position_x + padding_horizontal_vertical_between_border_text;
  float second_text_top_left_position_y = background_top_left_position_y + padding_vertical_between_first_and_second_text;

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

void Game::draw_title(int game_information_width, int game_information_start_x) {
  int title_font_size = 60;

  int margin_horizontal_title = 25;
  int margin_vertical_title = 10;
  float title_top_left_position_x = game_information_start_x + margin_horizontal_title;
  float title_top_left_position_y = margin_vertical_title;
  int margin_horizontal_second_title = 75;
  int margin_vertical_between_titles = 65;
  float second_title_top_left_position_x = game_information_start_x + margin_horizontal_second_title;
  float second_title_top_left_position_y = title_top_left_position_y + margin_vertical_between_titles;

  DrawTextEx(font, "Sesame's", {title_top_left_position_x, title_top_left_position_y}, title_font_size, 2, WHITE);
  DrawTextEx(font, "Quest", {
    second_title_top_left_position_x, 
    second_title_top_left_position_y}, 
    title_font_size, 2, WHITE);
}

void Game::draw_best_time(int game_information_width, int game_information_start_x) {
  int best_time_font_size = 40;

  int margin_horizontal_best_time_text = 60;
  int margin_vertical_best_time_text = 200;
  float best_time_text_top_left_position_x = game_information_start_x + margin_horizontal_best_time_text;
  float best_time_text_top_left_position_y = margin_vertical_best_time_text;
  
  int margin_horizontal_background_best_time = 10;
  int margin_vertical_between_background_best_time_text = 50;
  float background_best_time_top_left_position_x = game_information_start_x + margin_horizontal_background_best_time;
  float background_best_time_top_left_position_y = best_time_text_top_left_position_y + margin_vertical_between_background_best_time_text;
  float background_best_time_width = 285;
  float background_best_time_height = 70;

  DrawTextEx(
    font, 
    "Best Time", 
    {best_time_text_top_left_position_x, best_time_text_top_left_position_y}, 
    best_time_font_size, 2, WHITE);
  DrawRectangleRounded({
    background_best_time_top_left_position_x, 
    background_best_time_top_left_position_y, 
    background_best_time_width, 
    background_best_time_height}, 
    0.3, 6, PINK);
}

void Game::draw_current_time(int game_information_width, int game_information_start_x) {
  int current_time_font_size = 40;

  int margin_horizontal_current_time_text = 25;
  int margin_vertical_current_time_text = 400;
  float current_time_text_top_left_position_x = game_information_start_x + margin_horizontal_current_time_text;
  float current_time_text_top_left_position_y = margin_vertical_current_time_text;
  
  int margin_horizontal_background_current_time = 10;
  int margin_vertical_between_background_current_time_text = 50;
  float background_current_time_top_left_position_x = game_information_start_x + margin_horizontal_background_current_time;
  float background_current_time_top_left_position_y = current_time_text_top_left_position_y + margin_vertical_between_background_current_time_text;
  float background_current_time_width = 285;
  float background_current_time_height = 70;

  char current_time_int_to_text[10];
  sprintf(current_time_int_to_text, "%d", current_time);
  Vector2 current_time_int_to_text_size = MeasureTextEx(font, current_time_int_to_text, current_time_font_size, 2);

  // Adjust horizontal padding for current time to stay centered as it decreases
  int padding_horizontal_current_time = 0;
  if(current_time > 99) {
    padding_horizontal_current_time = 30;
  }
  else if(current_time <= 99 && current_time > 9) {
    padding_horizontal_current_time = 45;
  }
  else {
    padding_horizontal_current_time = 60;
  }
  
  int padding_vertical_current_time = 10;
  float current_time_top_left_position_x = background_current_time_top_left_position_x + padding_horizontal_current_time;
  float current_time_top_left_position_y = background_current_time_top_left_position_y + padding_vertical_current_time;

  int padding_horizontal_current_time_text_seconds = 20;
  float current_time_text_seconds_top_left_position_x = current_time_top_left_position_x + current_time_int_to_text_size.x + padding_horizontal_current_time_text_seconds;
  float current_time_text_seconds_top_left_position_y = current_time_top_left_position_y;


  DrawTextEx(
    font, 
    "Current Time", 
    {current_time_text_top_left_position_x, current_time_text_top_left_position_y}, 
    current_time_font_size, 2, WHITE);

  DrawRectangleRounded({
    background_current_time_top_left_position_x, 
    background_current_time_top_left_position_y, 
    background_current_time_width, 
    background_current_time_height}, 
    0.3, 6, PINK);

  DrawTextEx(
    font, 
    current_time_int_to_text, 
    {current_time_top_left_position_x, current_time_top_left_position_y}, 
    current_time_font_size, 2, WHITE);

  DrawTextEx(
    font, 
    "seconds", 
    {current_time_text_seconds_top_left_position_x, current_time_text_seconds_top_left_position_y}, 
    current_time_font_size, 2, WHITE);
}

void Game::draw_message(int game_information_width, int game_information_start_x) {
  //int message_font_size = 30;

  int margin_horizontal_background_message = 10;
  int margin_vertical_background_message = 600;
  float background_message_top_left_position_x = game_information_start_x + margin_horizontal_background_message;
  float background_message_top_left_position_y = margin_vertical_background_message;
  float background_message_width = 285;
  float background_message_height = 250;

  DrawRectangleRounded(
    {background_message_top_left_position_x, 
    background_message_top_left_position_y, 
    background_message_width, 
    background_message_height},
    0.3, 6, PINK);
}

void Game::display_game_information() {
  int game_information_start_x = 1515;
  int game_information_width = SCREEN_WIDTH - game_information_start_x;

  // Draw title
  draw_title(game_information_width, game_information_start_x);

  // Draw best time
  draw_best_time(game_information_width, game_information_start_x);

  // Draw current time
  draw_current_time(game_information_width, game_information_start_x);

  // Draw draw message
  draw_message(game_information_width, game_information_start_x);

  // Draw Sesame's coordinates
  draw_sesame_coordinates(game_information_width, game_information_start_x);
}

void Game::show_apartment() {
  // Write logic determining which frame of apartment to show based on 
  // Sesame interacting with opening/closing doors

  apartment.show_laundry_kitchen_rooms();
  apartment.show_living_room();
  apartment.show_bathroom_closets();
  apartment.show_bedroom();
}

void Game::countdown_timer() {
  if(timer_countdown.is_time_for_event(1.0) && current_time > 0) {
    current_time -= 1;
    timer_countdown.reset_timer();
  }
}

bool Game::check_game_over() {
  if(current_time == 0) {
    is_game_over = true;
  }
  return is_game_over;
}

bool Game::check_is_successful() const {
  return is_successful;
}

void Game::reset_game() {
  current_time = start_time;
  sesame.reset_sesame_position();
}
