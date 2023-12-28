#include "../header/game.hpp"

Game::Game(int SCREEN_WIDTH, int SCREEN_HEIGHT) : 
SCREEN_WIDTH(SCREEN_WIDTH), SCREEN_HEIGHT(SCREEN_HEIGHT) {
  wall_boundary_vector = {{200, 200}, {250, 250}, {275, 275}};
  game_information_start_x = 1515;
  game_information_width = SCREEN_WIDTH - game_information_start_x;

  font = LoadFont("C:/Users/josep/Documents/GitHub/sesames_quest/resources/font/monogram.ttf");

  is_time_to_meow_or_groom = false; 
  meow = false;
  groom = false;
  seconds_until_meow_or_groom = 12;
  sesame_last_move = 's';  // 's' = sitting, 'l' = walk left, 'd' = walk down, 'r' = walk right, 'u' = walk up
  srand(time(NULL));
  best_time = 0;
  start_time = 999;
  time_remaining = start_time;
  is_game_over = false;
  is_successful = false;

  // Initialize apartment rooms
  initialize_apartment();
  set_apartment_room_positions();
  set_apartment_interaction_boundaries();

  // Initialize mobile objects at the beginning of the game
  initialize_mobile_objects();
  set_mobile_objects_starting_positions();
  set_mobile_objects_interaction_boundaries();
  set_mobile_objects_collision_boundaries();

  // Initialize hidden objects at the beginning of the game
  initialize_hidden_objects();
  set_hidden_objects_starting_positions();

  // Initialize goals at the beginning of the game
  set_goal_texts();
  set_goal_positions();
}

Game::~Game() {
  UnloadFont(font);
}

void Game::set_wall_boundary_vector() {
  // Laundry room
  //wall_boundary_vector.push_back({});

  // Kitchen
  //wall_boundary_vector.push_back({});
}

void Game::draw_wall_boundary_vector() {
  /*
  for(int i = 0; i < wall_boundary_vector.size(); i++) {
    for(int j = 0; j < 2; j++) {
      //float x = wall_boundary_vector[i][j];
      //float y = wall_boundary_vector[i][j];
      //DrawCircle(x, y, 3, GREEN);
    }
  }
  */
}

void Game::initialize_apartment() {
  laundry_room_kitchen.initialize_apartment_room(0, 7);
  living_room.initialize_apartment_room(7, 8);
  bathroom.initialize_apartment_room(8, 11);
  bedroom.initialize_apartment_room(11, 13);
}

void Game::initialize_hidden_objects() {
  //blue_ball.initialize_object("C:/Users/josep/Documents/GitHub/sesames_quest/resources/sprites/hidden_objects/blue_ball.png");
  //green_ball.initialize_object("C:/Users/josep/Documents/GitHub/sesames_quest/resources/sprites/hidden_objects/green_ball.png");
  //pink_ball.initialize_object("C:/Users/josep/Documents/GitHub/sesames_quest/resources/sprites/hidden_objects/pink_ball.png");
  book.initialize_object("C:/Users/josep/Documents/GitHub/sesames_quest/resources/sprites/hidden_objects/book.png");
  cow.initialize_object("C:/Users/josep/Documents/GitHub/sesames_quest/resources/sprites/hidden_objects/cow.png");
  duck_one.initialize_object("C:/Users/josep/Documents/GitHub/sesames_quest/resources/sprites/hidden_objects/duck_one.png");
  duck_two.initialize_object("C:/Users/josep/Documents/GitHub/sesames_quest/resources/sprites/hidden_objects/duck_two.png");
  //gray_mouse.initialize_object("C:/Users/josep/Documents/GitHub/sesames_quest/resources/sprites/hidden_objects/gray_mouse.png");
  //brown_mouse.initialize_object("C:/Users/josep/Documents/GitHub/sesames_quest/resources/sprites/hidden_objects/brown_mouse.png");
  //white_mouse.initialize_object("C:/Users/josep/Documents/GitHub/sesames_quest/resources/sprites/hidden_objects/white_mouse.png");
  //papers.initialize_object("C:/Users/josep/Documents/GitHub/sesames_quest/resources/sprites/hidden_objects/papers.png");
  treat_box.initialize_object("C:/Users/josep/Documents/GitHub/sesames_quest/resources/sprites/hidden_objects/treat_box.png");

  num_hidden_objects = 5;
}

void Game::initialize_mobile_objects() {
  cat_bed.initialize_object("C:/Users/josep/Documents/GitHub/sesames_quest/resources/sprites/mobile_objects/cat_bed.png");
  laundry_basket.initialize_object("C:/Users/josep/Documents/GitHub/sesames_quest/resources/sprites/mobile_objects/laundry_basket.png");
  litter_box.initialize_object("C:/Users/josep/Documents/GitHub/sesames_quest/resources/sprites/mobile_objects/litter_box.png");
  meow_rug.initialize_object("C:/Users/josep/Documents/GitHub/sesames_quest/resources/sprites/mobile_objects/meow_rug.png");
  bathroom_rug.initialize_object("C:/Users/josep/Documents/GitHub/sesames_quest/resources/sprites/mobile_objects/bathroom_rug.png");
}

void Game::set_apartment_room_positions() {
  laundry_room_kitchen.set_apartment_room_position(0, 0);
  living_room.set_apartment_room_position(0, 512);
  bathroom.set_apartment_room_position(910, 0);
  bedroom.set_apartment_room_position(910, 512);
}

void Game::set_apartment_interaction_boundaries() {
  laundry_room_kitchen.set_interaction_boundary({600, 200, 90, 115});
  living_room.set_interaction_boundary({60, 600, 90, 150});
  bathroom.set_interaction_boundary({1158, 185, 50, 115});
  bedroom.set_interaction_boundary({975, 615, 115, 115});
}

void Game::set_hidden_objects_starting_positions() {
  // TODO: Game class will keep track of where each hidden object is located
  // Create a vector of random numbers between 1 and maximum # of places to hide without repeats
  // Each # represents a place to hide in the apartment
  for(int i = 0; i < num_hidden_objects; i++) {
    returned_random_value = get_random_value(vector_random_values, num_hidden_objects);
    vector_random_values.push_back(returned_random_value); 
  }
  
  // Assign each hidden object a random # from vector_random_values
  //int blue_ball_random_value = vector_random_values[0];
  //std::vector<float> blue_ball_coordinates = get_coordinates(blue_ball_random_value);
  //blue_ball.set_position(blue_ball_coordinates[0], blue_ball_coordinates[1]);

  int book_random_value = vector_random_values[0];
  std::vector<float> book_coordinates = get_coordinates(book_random_value);
  book.set_position(book_coordinates[0], book_coordinates[1]);

  //int brown_mouse_random_value = vector_random_values[2];
  //std::vector<float> brown_mouse_coordinates = get_coordinates(brown_mouse_random_value);
  //brown_mouse.set_position(brown_mouse_coordinates[0], brown_mouse_coordinates[1]);

  int cow_random_value = vector_random_values[1];
  std::vector<float> cow_coordinates = get_coordinates(cow_random_value);
  cow.set_position(cow_coordinates[0], cow_coordinates[1]);

  int duck_one_random_value = vector_random_values[2];
  std::vector<float> duck_one_coordinates = get_coordinates(duck_one_random_value);
  duck_one.set_position(duck_one_coordinates[0], duck_one_coordinates[1]);

  int duck_two_random_value = vector_random_values[3];
  std::vector<float> duck_two_coordinates = get_coordinates(duck_two_random_value);
  duck_two.set_position(duck_two_coordinates[0], duck_two_coordinates[1]);

  //int pink_ball_random_value = vector_random_values[6];
  //std::vector<float> pink_ball_coordinates = get_coordinates(pink_ball_random_value);
  //pink_ball.set_position(pink_ball_coordinates[0], pink_ball_coordinates[1]);

  int treat_box_random_value = vector_random_values[4];
  std::vector<float> treat_box_coordinates = get_coordinates(treat_box_random_value);
  treat_box.set_position(treat_box_coordinates[0], treat_box_coordinates[1]);
}

void Game::set_mobile_objects_starting_positions() {
  cat_bed.set_position(360, 670);
  laundry_basket.set_position(160, 340);
  litter_box.set_position(100, 800);
  meow_rug.set_position(909, 155);
  bathroom_rug.set_position(1290, 240);
}

void Game::set_mobile_objects_interaction_boundaries() {
  cat_bed.set_interaction_boundary({340, 650, 190, 160});
  laundry_basket.set_interaction_boundary({135, 335, 160, 140});
  litter_box.set_interaction_boundary({50, 850, 230, 140});
  meow_rug.set_interaction_boundary({920, 220, 140, 100});
  bathroom_rug.set_interaction_boundary({1270, 250, 190, 115});
}

void Game::set_mobile_objects_collision_boundaries() {
  laundry_basket.set_collision_boundary({176, 370, 86, 88});
  litter_box.set_collision_boundary({100, 900, 155, 56});
}

void Game::set_goal_texts() {
  find_treats.set_goal_text("Find treats");
  eat_treats.set_goal_text("Eat treats");
  hide_empty_treat_box.set_goal_text("Hide treat box");
}

void Game::set_goal_positions() {
  int margin_vertical = 700;
  int margin_horizontal = 10;
  int padding_vertical = 75;

  float find_treats_top_left_position_x = game_information_start_x + margin_horizontal;
  float find_treats_top_left_position_y = margin_vertical;
  float eat_treats_top_left_position_x = game_information_start_x + margin_horizontal;
  float eat_treats_top_left_position_y = margin_vertical + padding_vertical;
  float hide_empty_treat_box_top_left_position_x = game_information_start_x + margin_horizontal;
  float hide_empty_treat_box_top_left_position_y = margin_vertical + padding_vertical * 2;;

  find_treats.set_position(find_treats_top_left_position_x, find_treats_top_left_position_y);
  eat_treats.set_position(eat_treats_top_left_position_x, eat_treats_top_left_position_y);
  hide_empty_treat_box.set_position(hide_empty_treat_box_top_left_position_x, hide_empty_treat_box_top_left_position_y);
}

void Game::interact_with_mobile_objects() {
  // Interaction & collision boundaries move w/ mobile object
  if(cat_bed.get_is_sesame_in_interaction_boundary() && !cat_bed.get_is_object_moved()) {
    cat_bed.toggle_move('d', 100);
    cat_bed.toggle_is_object_moved();
  }
  else if(cat_bed.get_is_sesame_in_interaction_boundary() && cat_bed.get_is_object_moved()) {
    cat_bed.toggle_move('u', 100);
    cat_bed.toggle_is_object_moved();
  }

  else if(laundry_basket.get_is_sesame_in_interaction_boundary() && !laundry_basket.get_is_object_moved()) {
    laundry_basket.toggle_move('l', 100);  // Also moves collision_boundary
    laundry_basket.toggle_is_object_moved();
  }
  else if(laundry_basket.get_is_sesame_in_interaction_boundary() && laundry_basket.get_is_object_moved()) {
    laundry_basket.toggle_move('r', 100);  // Also moves collision_boundary
    laundry_basket.toggle_is_object_moved();
  }

  else if(litter_box.get_is_sesame_in_interaction_boundary() && !litter_box.get_is_object_moved()) {
    litter_box.toggle_move('r', 150);  // Also moves collision_boundary
    litter_box.toggle_is_object_moved();
  }
  else if(litter_box.get_is_sesame_in_interaction_boundary() && litter_box.get_is_object_moved()) {
    litter_box.toggle_move('l', 150);  // Also moves collision_boundary
    litter_box.toggle_is_object_moved();
  }

  else if(meow_rug.get_is_sesame_in_interaction_boundary() && !meow_rug.get_is_object_moved()) {
    meow_rug.toggle_move('d', 55);
    meow_rug.toggle_is_object_moved();
  }
  else if(meow_rug.get_is_sesame_in_interaction_boundary() && meow_rug.get_is_object_moved()) {
    meow_rug.toggle_move('u', 55);
    meow_rug.toggle_is_object_moved();
  }

  else if(bathroom_rug.get_is_sesame_in_interaction_boundary() && !bathroom_rug.get_is_object_moved()) {
    bathroom_rug.toggle_move('d', 50);
    bathroom_rug.toggle_move('r', 70);
    bathroom_rug.toggle_is_object_moved();
  }
  else if(bathroom_rug.get_is_sesame_in_interaction_boundary() && bathroom_rug.get_is_object_moved()) {
    bathroom_rug.toggle_move('u', 50);
    bathroom_rug.toggle_move('l', 70);
    bathroom_rug.toggle_is_object_moved();
  }
}

void Game::interact_with_apartment() {
  // Laundry room & kitchen
  if(laundry_room_kitchen.get_is_sesame_in_interaction_boundary() && !laundry_room_kitchen.get_is_door_open()) {
    laundry_room_kitchen.update_current_frame(1);
    laundry_room_kitchen.toggle_is_door_open();
  }
  else if(laundry_room_kitchen.get_is_sesame_in_interaction_boundary() && laundry_room_kitchen.get_is_door_open()) {
    laundry_room_kitchen.update_current_frame(0);
    laundry_room_kitchen.toggle_is_door_open();
  }

  // Living room switch screens
  // TODO: Create method to draw duck texture (almost whole screen)

  // Bathroom
  else if(bathroom.get_is_sesame_in_interaction_boundary() && !bathroom.get_is_door_open()) {
    bathroom.update_current_frame(9);
    bathroom.toggle_is_door_open();
  }
  else if(bathroom.get_is_sesame_in_interaction_boundary() && bathroom.get_is_door_open()) {
    bathroom.update_current_frame(8);
    bathroom.toggle_is_door_open();
  }

  // Bedroom
  else if(bedroom.get_is_sesame_in_interaction_boundary() && !bedroom.get_is_door_open()) {
    bedroom.update_current_frame(12);
    bedroom.toggle_is_door_open();
  }
  else if(bedroom.get_is_sesame_in_interaction_boundary() && bedroom.get_is_door_open()) {
    bedroom.update_current_frame(11);
    bedroom.toggle_is_door_open();
  }
}

int Game::get_random_value(std::vector<int> vector_random_values, int num_hidden_objects) {
  int random_value;
  bool is_repeated;
  do {
    is_repeated = false;
    random_value = (rand() % num_hidden_objects) + 1;
    // Check if random value already in vector
    for(int i : vector_random_values) {
      if(random_value == i) {
        // Stop iterating, generate a new value, start at beginning of vector & iterate again  
        is_repeated = true;
        break;
      }
    }
  } while(is_repeated);
  
  return random_value;
}

std::vector<float> Game::get_coordinates(int random_value) {
  switch(random_value) {
    case 1: {
      return {1330, 275};
    } break;

    case 2: {
      return {400, 700};
    } break;
    
    case 3: {
      return {165, 370};
    } break;

    case 4: {
      return {150, 890};
    } break;

    case 5: {
      return {940, 190};
    } break;

    /*
    case 6: {
      return {650, 235};
    } break;

    case 7: {
      return {1100, 225};
    } break;

    case 8: {
      return {955, 645};
    } break;
    */
    default:
      break;
  }
  return {0, 0};
}

void Game::reverse_sesame_last_move() {
  switch(sesame_last_move) {
    case 's': {
      sesame.reverse_walk_down();
    } break;

    case 'l': {
      sesame.reverse_walk_left();
    } break;

    case 'd': {
      sesame.reverse_walk_down();
    } break;

    case 'r': {
      sesame.reverse_walk_right();
      break;
    }

    case 'u': {
      sesame.reverse_walk_up();
    } break;

    default: {
      break;
    }
  }
}

void Game::check_all_boundaries() {
  // TODO: Check collisions with walls by room

  // Check collisions with mobile objects
  // Use the method calls below for debugging
  //laundry_basket.draw_collision_boundary();
  //litter_box.draw_collision_boundary(); 
  if(CheckCollisionRecs(sesame.get_sesame_boundary(), laundry_basket.get_collision_boundary())) {
    reverse_sesame_last_move();
  }
  else if(CheckCollisionRecs(sesame.get_sesame_boundary(), litter_box.get_collision_boundary())) {
    reverse_sesame_last_move();
  }
}

void Game::check_all_interactions() {
  Rectangle sesame_boundary = sesame.get_sesame_boundary();
  
  // Cat bed
  if(CheckCollisionRecs(sesame_boundary, cat_bed.get_interaction_boundary())) {
    cat_bed.draw_interaction_boundary();
    cat_bed.set_is_sesame_in_interaction_boundary(true);
  }

  // Bathroom rug  
  else if(CheckCollisionRecs(sesame_boundary, bathroom_rug.get_interaction_boundary())) {
    bathroom_rug.draw_interaction_boundary();
    bathroom_rug.set_is_sesame_in_interaction_boundary(true);
  }

  // Laundry basket
  else if(CheckCollisionRecs(sesame_boundary, laundry_basket.get_interaction_boundary())) {
    laundry_basket.draw_interaction_boundary();
    laundry_basket.set_is_sesame_in_interaction_boundary(true);
  }

  // Litter box
  else if(CheckCollisionRecs(sesame_boundary, litter_box.get_interaction_boundary())) {
    litter_box.draw_interaction_boundary();
    litter_box.set_is_sesame_in_interaction_boundary(true);
  }

  // Meow rug
  else if(CheckCollisionRecs(sesame_boundary, meow_rug.get_interaction_boundary())) {
    meow_rug.draw_interaction_boundary();
    meow_rug.set_is_sesame_in_interaction_boundary(true);
  }

  // Laundry room & kicthen
  else if(CheckCollisionRecs(sesame_boundary, laundry_room_kitchen.get_interaction_boundary())) {
    laundry_room_kitchen.draw_interaction_boundary();
    laundry_room_kitchen.set_is_sesame_in_interaction_boundary(true);
  }

  // Living room
  else if(CheckCollisionRecs(sesame_boundary, living_room.get_interaction_boundary())) {
    living_room.draw_interaction_boundary();
    living_room.set_is_sesame_in_interaction_boundary(true);
  }

  // Bathroom
  else if(CheckCollisionRecs(sesame_boundary, bathroom.get_interaction_boundary())) {
    bathroom.draw_interaction_boundary();
    bathroom.set_is_sesame_in_interaction_boundary(true);
  }

  // Bedroom
  else if(CheckCollisionRecs(sesame_boundary, bedroom.get_interaction_boundary())) {
    bedroom.draw_interaction_boundary();
    bedroom.set_is_sesame_in_interaction_boundary(true);
  }

  else {
    cat_bed.set_is_sesame_in_interaction_boundary(false);
    laundry_basket.set_is_sesame_in_interaction_boundary(false);
    litter_box.set_is_sesame_in_interaction_boundary(false);
    meow_rug.set_is_sesame_in_interaction_boundary(false);
    bathroom_rug.set_is_sesame_in_interaction_boundary(false);
    laundry_room_kitchen.set_is_sesame_in_interaction_boundary(false);
    living_room.set_is_sesame_in_interaction_boundary(false);
    bathroom.set_is_sesame_in_interaction_boundary(false);
    bedroom.set_is_sesame_in_interaction_boundary(false);
  }
}

void Game::handle_keyboard_input() {
  // Handle keys held down and check if Sesame is inside screen
  if(IsKeyDown(KEY_LEFT)) {
    timer_until_meow_or_groom.reset_timer();
    sesame.walk_left();
    sesame_last_move = 'l';
  }
  else if(IsKeyDown(KEY_DOWN)) {
    timer_until_meow_or_groom.reset_timer();
    sesame.walk_down();
    sesame_last_move = 'd';
  }
  else if(IsKeyDown(KEY_RIGHT)) {
    timer_until_meow_or_groom.reset_timer();
    sesame.walk_right();
    sesame_last_move = 'r';
  }
  else if(IsKeyDown(KEY_UP)) {
    timer_until_meow_or_groom.reset_timer();
    sesame.walk_up();
    sesame_last_move = 'u';
  }
  else if(IsKeyDown(KEY_S)) {
    timer_until_meow_or_groom.reset_timer();
    sesame.sleeping();
  }
  else {
    // No keys held down
    // After sitting w/o user input, meow or groom
    handle_meow_or_groom();
    sesame_last_move = 's';
  }

  // Handle keys pressed
  int key_pressed = GetKeyPressed();
  switch(key_pressed) {
    case KEY_SPACE: {
      toggle_full_screen_window(SCREEN_WIDTH, SCREEN_HEIGHT);
    }
    case KEY_A: {
      timer_until_meow_or_groom.reset_timer();
      // Call function to check which object interaction with 
      interact_with_mobile_objects();
      interact_with_apartment();
    }
    case KEY_T: {
      timer_until_meow_or_groom.reset_timer();
      //laundry_room_kitchen.update_current_frame(1);
    }
    default: {
      break;
    }
  }
}

void Game::handle_mouse_input() {
  mouse_position = GetMousePosition();

  if(IsMouseButtonDown(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mouse_position, audio.get_audio_button_bounds())) {
    audio.toggle_is_mute();
  }

  // Unmute && within bounds of volume texture
  if(audio.get_is_mute() == false && CheckCollisionPointRec(mouse_position, audio.get_audio_button_bounds())) {
    audio.draw_audio_light();
  }

  // Unmute && not within bounds of volume texture
  else if(audio.get_is_mute() == false) {
    audio.draw_audio_dark();
  }

  // Mute && within bounds of mute texture
  else if(audio.get_is_mute() && CheckCollisionPointRec(mouse_position, audio.get_audio_button_bounds())) {
    audio.draw_mute_light();
  }

  // Mute && not within bounds of mute texture
  else if(audio.get_is_mute()) {
    audio.draw_mute_dark();
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
  int margin_vertical_best_time_text = 180;
  float best_time_text_top_left_position_x = game_information_start_x + margin_horizontal_best_time_text;
  float best_time_text_top_left_position_y = margin_vertical_best_time_text;
  
  int margin_horizontal_background_best_time = 10;
  int margin_vertical_between_background_best_time_text = 50;
  float background_best_time_top_left_position_x = game_information_start_x + margin_horizontal_background_best_time;
  float background_best_time_top_left_position_y = best_time_text_top_left_position_y + margin_vertical_between_background_best_time_text;
  float background_best_time_width = 285;
  float background_best_time_height = 70;

  char best_time_int_to_text[10];
  sprintf(best_time_int_to_text, "%d", best_time);
  Vector2 best_time_int_to_text_size = MeasureTextEx(font, best_time_int_to_text, best_time_font_size, 2);

  // Adjust horizontal padding for best time to stay centered as it decreases
  int padding_horizontal_best_time = 0;
  if(best_time > 99) {
    padding_horizontal_best_time = 30;
  }
  else if(best_time <= 99 && best_time > 9) {
    padding_horizontal_best_time = 45;
  }
  else {
    padding_horizontal_best_time = 60;
  }
  
  int padding_vertical_best_time = 10;
  float best_time_top_left_position_x = background_best_time_top_left_position_x + padding_horizontal_best_time;
  float best_time_top_left_position_y = background_best_time_top_left_position_y + padding_vertical_best_time;

  int padding_horizontal_best_time_text_seconds = 20;
  float best_time_text_seconds_top_left_position_x = best_time_top_left_position_x + best_time_int_to_text_size.x + padding_horizontal_best_time_text_seconds;
  float best_time_text_seconds_top_left_position_y = best_time_top_left_position_y;

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
  
  DrawTextEx(
    font, 
    best_time_int_to_text, 
    {best_time_top_left_position_x, best_time_top_left_position_y}, 
    best_time_font_size, 2, WHITE);

  DrawTextEx(
    font, 
    "seconds", 
    {best_time_text_seconds_top_left_position_x, best_time_text_seconds_top_left_position_y}, 
    best_time_font_size, 2, WHITE);
}

void Game::draw_time_remaining(int game_information_width, int game_information_start_x) {
  int time_remaining_font_size = 40;

  int margin_horizontal_time_remaining_text = 10;
  int margin_vertical_time_remaining_text = 350;
  float time_remaining_text_top_left_position_x = game_information_start_x + margin_horizontal_time_remaining_text;
  float time_remaining_text_top_left_position_y = margin_vertical_time_remaining_text;
  
  int margin_horizontal_background_time_remaining = 10;
  int margin_vertical_between_background_time_remaining_text = 50;
  float background_time_remaining_top_left_position_x = game_information_start_x + margin_horizontal_background_time_remaining;
  float background_time_remaining_top_left_position_y = time_remaining_text_top_left_position_y + margin_vertical_between_background_time_remaining_text;
  float background_time_remaining_width = 285;
  float background_time_remaining_height = 70;

  char time_remaining_int_to_text[10];
  sprintf(time_remaining_int_to_text, "%d", time_remaining);
  Vector2 time_remaining_int_to_text_size = MeasureTextEx(font, time_remaining_int_to_text, time_remaining_font_size, 2);

  // Adjust horizontal padding for time remaining to stay centered as it decreases
  int padding_horizontal_time_remaining = 0;
  if(time_remaining > 99) {
    padding_horizontal_time_remaining = 30;
  }
  else if(time_remaining <= 99 && time_remaining > 9) {
    padding_horizontal_time_remaining = 45;
  }
  else {
    padding_horizontal_time_remaining = 60;
  }
  
  int padding_vertical_time_remaining = 10;
  float time_remaining_top_left_position_x = background_time_remaining_top_left_position_x + padding_horizontal_time_remaining;
  float time_remaining_top_left_position_y = background_time_remaining_top_left_position_y + padding_vertical_time_remaining;

  int padding_horizontal_time_remaining_text_seconds = 20;
  float time_remaining_text_seconds_top_left_position_x = time_remaining_top_left_position_x + time_remaining_int_to_text_size.x + padding_horizontal_time_remaining_text_seconds;
  float time_remaining_text_seconds_top_left_position_y = time_remaining_top_left_position_y;


  DrawTextEx(
    font, 
    "Time Remaining", 
    {time_remaining_text_top_left_position_x, time_remaining_text_top_left_position_y}, 
    time_remaining_font_size, 2, WHITE);

  DrawRectangleRounded({
    background_time_remaining_top_left_position_x, 
    background_time_remaining_top_left_position_y, 
    background_time_remaining_width, 
    background_time_remaining_height}, 
    0.3, 6, PINK);

  DrawTextEx(
    font, 
    time_remaining_int_to_text, 
    {time_remaining_top_left_position_x, time_remaining_top_left_position_y}, 
    time_remaining_font_size, 2, WHITE);

  DrawTextEx(
    font, 
    "seconds", 
    {time_remaining_text_seconds_top_left_position_x, time_remaining_text_seconds_top_left_position_y}, 
    time_remaining_font_size, 2, WHITE);
}

void Game::draw_message(int game_information_width, int game_information_start_x) {
  //int message_font_size = 30;

  int margin_horizontal_background_message = 10;
  int margin_vertical_background_message = 525;
  float background_message_top_left_position_x = game_information_start_x + margin_horizontal_background_message;
  float background_message_top_left_position_y = margin_vertical_background_message;
  float background_message_width = 285;
  float background_message_height = 125;

  DrawRectangleRounded(
    {background_message_top_left_position_x, 
    background_message_top_left_position_y, 
    background_message_width, 
    background_message_height},
    0.3, 6, PINK);
}

void Game::draw_game_information() {
  // Draw title
  draw_title(game_information_width, game_information_start_x);

  // Draw best time
  draw_best_time(game_information_width, game_information_start_x);

  // Draw time remaining
  draw_time_remaining(game_information_width, game_information_start_x);

  // Draw draw message
  draw_message(game_information_width, game_information_start_x);

  // Draw Sesame's coordinates
  // Not necessary for gameplay, commented out
  //draw_sesame_coordinates(game_information_width, game_information_start_x);
}

void Game::draw_apartment() {
  laundry_room_kitchen.draw_room();
  living_room.draw_room();
  bathroom.draw_room();
  bedroom.draw_room();
}

void Game::draw_mobile_objects() const {
  cat_bed.draw_mobile_object();
  laundry_basket.draw_mobile_object();
  litter_box.draw_mobile_object();
  meow_rug.draw_mobile_object();
  bathroom_rug.draw_mobile_object();
}

void Game::draw_hidden_objects() const {
  //blue_ball.draw_hidden_object();
  //pink_ball.draw_hidden_object();
  //green_ball.draw_hidden_object();
  book.draw_hidden_object();
  cow.draw_hidden_object();
  duck_one.draw_hidden_object();
  duck_two.draw_hidden_object();
  //gray_mouse.draw_hidden_object();
  //brown_mouse.draw_hidden_object();
  //white_mouse.draw_hidden_object();
  //papers.draw_hidden_object();
  treat_box.draw_hidden_object();
}

void Game::draw_goals() const {
  find_treats.draw_goal();
  eat_treats.draw_goal();
  hide_empty_treat_box.draw_goal();
}

Font Game::get_font() const {
  return font;
}

void Game::countdown_timer() {
  if(timer_countdown.is_time_for_event(1.0) && time_remaining > 0) {
    time_remaining -= 1;
    timer_countdown.reset_timer();
  }
}

bool Game::check_game_over() {
  if(time_remaining == 0) {
    is_game_over = true;
  }
  return is_game_over;
}

bool Game::check_is_successful() const {
  return is_successful;
}

void Game::update_best_time() {
  if(time_remaining > best_time) {
    best_time = time_remaining;
  }
}

void Game::reset_game() {
  time_remaining = start_time;
  update_best_time();
  time_remaining = 0;
  sesame.reset_sesame_position();
  reset_mobile_objects();
}

void Game::reset_mobile_objects() {
  // Reset all the objects that were moved
  if(cat_bed.get_is_object_moved()) {
    cat_bed.toggle_move('u', 100);
    cat_bed.toggle_is_object_moved();
  }
  else if(laundry_basket.get_is_object_moved()) {
    laundry_basket.toggle_move('r', 100);
    laundry_basket.toggle_is_object_moved();
  }
  else if(litter_box.get_is_object_moved()) {
    litter_box.toggle_move('d', 100);
    litter_box.toggle_is_object_moved();
  }
  else if(meow_rug.get_is_object_moved()) {
    meow_rug.toggle_move('u', 55);
    meow_rug.toggle_is_object_moved();
  }
  else if(bathroom_rug.get_is_object_moved()) {
    bathroom_rug.toggle_move('u', 50);
    bathroom_rug.toggle_move('l', 70);
    bathroom_rug.toggle_is_object_moved();
  }
}
