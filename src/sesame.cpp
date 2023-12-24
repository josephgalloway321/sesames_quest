#include "../header/sesame.hpp"

Sesame::Sesame() {
  // Walking = 0, Grooming = 1, Sitting & Meowing = 2, Eating = 3, Dancing = 4, Scared = 5
  // Sleeping & Woken = 6
  sesame_current_action = 0;  

  sesame_start_position_top_left_x = 250.0;  // Position x at the start of the game
  sesame_start_position_top_left_y = 250.0;  // Position y at the start of the game
  sesame_position_top_left_x = sesame_start_position_top_left_x;  
  sesame_position_top_left_y = sesame_start_position_top_left_y;  
  sesame_position_bottom_right_x = 0.0;  // Initialize
  sesame_position_bottom_right_y = 0.0;  // Initialize

  sesame_walking = LoadTexture("C:/Users/josep/Documents/GitHub/sesames_quest/resources/sprites/sesame/sesame_walking.png");  
  sesame_walking_max_frames = 16;  //  Number of frames in the original png file
  sesame_walking_frame_width = (float)(sesame_walking.width / sesame_walking_max_frames);   // Calculate the width of each frame in image
  sesame_walking_frame_height = sesame_walking.height;
  sesame_walking_left_start_frame_index = 0;  // Each walking frame start index
  sesame_walking_down_start_frame_index = 4;
  sesame_walking_right_start_frame_index = 8;
  sesame_walking_up_start_frame_index = 12;
  sesame_walking_left_current_frame = sesame_walking_left_start_frame_index;  // Keep track of current frame
  sesame_walking_down_current_frame = sesame_walking_down_start_frame_index;
  sesame_walking_right_current_frame = sesame_walking_right_start_frame_index;
  sesame_walking_up_current_frame = sesame_walking_up_start_frame_index;
  sesame_walking_left_end_frame_index = sesame_walking_down_start_frame_index;
  sesame_walking_down_end_frame_index = sesame_walking_right_start_frame_index;
  sesame_walking_right_end_frame_index = sesame_walking_up_start_frame_index;
  sesame_walking_up_end_frame_index = sesame_walking_max_frames;
  sesame_walking_stride = 30;  // Stride length in pixels while walking
  
  sesame_grooming = LoadTexture("C:/Users/josep/Documents/GitHub/sesames_quest/resources/sprites/sesame/sesame_grooming.png");
  sesame_grooming_max_frames = 12;  //  Number of frames in the original png file
  sesame_grooming_frame_width = (float)(sesame_grooming.width / sesame_grooming_max_frames);   // Calculate the width of each frame in image
  sesame_grooming_frame_height = sesame_grooming.height;
  sesame_grooming_current_frame = 0;  // Frame counter to keep track of current frame

  sesame_sitting_meowing = LoadTexture("C:/Users/josep/Documents/GitHub/sesames_quest/resources/sprites/sesame/sesame_sitting_meowing.png");
  sesame_sitting_meowing_max_frames = 12;
  sesame_sitting_meowing_frame_width = (float)(sesame_sitting_meowing.width / sesame_sitting_meowing_max_frames);   // Calculate the width of each frame in image
  sesame_sitting_meowing_frame_height = sesame_sitting_meowing.height;
  sesame_sitting_start_frame_index = 0;
  sesame_meowing_start_frame_index = 6;
  sesame_sitting_current_frame = sesame_sitting_start_frame_index;
  sesame_meowing_current_frame = sesame_meowing_start_frame_index;
  sesame_sitting_end_frame_index = sesame_meowing_start_frame_index;
  sesame_meowing_end_frame_index = sesame_sitting_meowing_max_frames;

  sesame_eating = LoadTexture("C:/Users/josep/Documents/GitHub/sesames_quest/resources/sprites/sesame/sesame_eating.png");
  sesame_eating_max_frames = 2;
  sesame_eating_frame_width = (float)(sesame_eating.width / sesame_eating_max_frames);
  sesame_eating_frame_height = sesame_eating.height; 
  sesame_eating_current_frame = 0;

  sesame_dancing = LoadTexture("C:/Users/josep/Documents/GitHub/sesames_quest/resources/sprites/sesame/sesame_dancing.png");
  sesame_dancing_max_frames = 2;
  sesame_dancing_frame_width = (float)(sesame_dancing.width / sesame_dancing_max_frames);
  sesame_dancing_frame_height = sesame_dancing.height; 
  sesame_dancing_current_frame = 0; 

  sesame_scared = LoadTexture("C:/Users/josep/Documents/GitHub/sesames_quest/resources/sprites/sesame/sesame_scared.png");
  sesame_scared_max_frames = 4;
  sesame_scared_frame_width = (float)(sesame_scared.width / sesame_scared_max_frames);
  sesame_scared_frame_height = sesame_scared.height; 
  sesame_scared_current_frame = 0; 

  sesame_sleeping_woken = LoadTexture("C:/Users/josep/Documents/GitHub/sesames_quest/resources/sprites/sesame/sesame_sleeping_woken.png");
  sesame_sleeping_woken_max_frames = 6;
  sesame_sleeping_woken_frame_width = (float)(sesame_sleeping_woken.width / sesame_sleeping_woken_max_frames);
  sesame_sleeping_woken_frame_height = sesame_sleeping_woken.height;
  sesame_sleeping_start_frame_index = 0;
  sesame_woken_start_frame_index = 4;
  sesame_sleeping_current_frame = sesame_sleeping_start_frame_index;
  sesame_woken_current_frame = sesame_woken_start_frame_index;
  sesame_sleeping_end_frame_index = sesame_woken_start_frame_index;
  sesame_woken_end_frame_index = sesame_sleeping_woken_max_frames;
}

Sesame::~Sesame() {
  UnloadTexture(sesame_walking);
  UnloadTexture(sesame_grooming);
  UnloadTexture(sesame_sitting_meowing);
  UnloadTexture(sesame_eating);
  UnloadTexture(sesame_dancing);
  UnloadTexture(sesame_scared);
  UnloadTexture(sesame_sleeping_woken);
}

std::vector<std::vector<float>> Sesame::get_sesame_frame_coordinates() {
  switch(sesame_current_action) {
    case 0: {
      // Walking
      sesame_position_bottom_right_x = sesame_position_top_left_x + sesame_walking_frame_width;
      sesame_position_bottom_right_y = sesame_position_top_left_y + sesame_walking_frame_height;
    } break;
    case 1: {
      // Grooming
      sesame_position_bottom_right_x = sesame_position_top_left_x + sesame_grooming_frame_width;
      sesame_position_bottom_right_y = sesame_position_top_left_y + sesame_grooming_frame_height;
    } break;
    case 2: {
      // Sitting & Meowing
      sesame_position_bottom_right_x = sesame_position_top_left_x + sesame_sitting_meowing_frame_width;
      sesame_position_bottom_right_y = sesame_position_top_left_y + sesame_sitting_meowing_frame_height;
    } break;
    case 3: {
      // Eating
      sesame_position_bottom_right_x = sesame_position_top_left_x + sesame_eating_frame_width;
      sesame_position_bottom_right_y = sesame_position_top_left_y + sesame_eating_frame_height;
    } break;
    case 4: {
      // Dancing
      sesame_position_bottom_right_x = sesame_position_top_left_x + sesame_dancing_frame_width;
      sesame_position_bottom_right_y = sesame_position_top_left_y + sesame_dancing_frame_height;
    } break;
    case 5: {
      // Scared
      sesame_position_bottom_right_x = sesame_position_top_left_x + sesame_scared_frame_width;
      sesame_position_bottom_right_y = sesame_position_top_left_y + sesame_scared_frame_height;
    } break;
    case 6: {
      // Sleeping & Woken
      sesame_position_bottom_right_x = sesame_position_top_left_x + sesame_sleeping_woken_frame_width;
      sesame_position_bottom_right_y = sesame_position_top_left_y + sesame_sleeping_woken_frame_height;
    } break;
    default:
      break;
  }
  sesame_frame_coordinates = {{sesame_position_top_left_x, sesame_position_top_left_y}, {sesame_position_bottom_right_x, sesame_position_bottom_right_y}};
  return sesame_frame_coordinates;
}

Rectangle Sesame::get_sesame_boundary() {
  switch(sesame_current_action) {
    case 0: {
      // Walking
      // TODO: Split up walking into separate cases to narrow frame width
      //DrawRectangle(sesame_position_top_left_x, sesame_position_top_left_y, sesame_walking_frame_width/4, sesame_walking_frame_height, CUSTOM_BLUE);
      return {sesame_position_top_left_x, sesame_position_top_left_y, sesame_walking_frame_width, sesame_walking_frame_height};
    } break;
    case 1: {
      // Grooming
      return {sesame_position_top_left_x, sesame_position_top_left_y, sesame_grooming_frame_width, sesame_grooming_frame_height};
    } break;
    case 2: {
      // Sitting & Meowing
      //DrawRectangle(sesame_position_top_left_x, sesame_position_top_left_y, sesame_sitting_meowing_frame_width, sesame_sitting_meowing_frame_height, CUSTOM_BLUE);
      return {sesame_position_top_left_x, sesame_position_top_left_y, sesame_sitting_meowing_frame_width, sesame_sitting_meowing_frame_height};
    } break;
    case 3: {
      // Eating
      return {sesame_position_top_left_x, sesame_position_top_left_y, sesame_eating_frame_width, sesame_eating_frame_height};
    } break;
    case 4: {
      // Dancing
      return {sesame_position_top_left_x, sesame_position_top_left_y, sesame_dancing_frame_width, sesame_dancing_frame_height};
    } break;
    case 5: {
      // Scared
      return {sesame_position_top_left_x, sesame_position_top_left_y, sesame_scared_frame_width, sesame_scared_frame_height};
    } break;
    case 6: {
      // Sleeping & Woken
      return {sesame_position_top_left_x, sesame_position_top_left_y, sesame_sleeping_woken_frame_width, sesame_sleeping_woken_frame_height};
    } break;
    default:
      return {sesame_position_top_left_x, sesame_position_top_left_y, sesame_sitting_meowing_frame_width, sesame_sitting_meowing_frame_height};
      break;
  }
}

void Sesame::walk_left() {
  sesame_current_action = 0;
  sesame_walking_left_current_frame += 1;
  sesame_walking_left_current_frame = sesame_walking_left_current_frame % sesame_walking_left_end_frame_index;

  sesame_position_top_left_x -= sesame_walking_stride;

  DrawTextureRec(
    sesame_walking,
    Rectangle{
      sesame_walking_frame_width * sesame_walking_left_current_frame,
      0,
      sesame_walking_frame_width,
      sesame_walking_frame_height},
    Vector2{
      sesame_position_top_left_x,
      sesame_position_top_left_y},
      WHITE);
}

void Sesame::walk_down() {
  sesame_current_action = 0;
  sesame_walking_down_current_frame += 1;
  sesame_walking_down_current_frame = sesame_walking_down_current_frame % sesame_walking_down_end_frame_index;

  if(sesame_walking_down_current_frame == 0) {
    sesame_walking_down_current_frame = sesame_walking_down_start_frame_index;
  }

  sesame_position_top_left_y += sesame_walking_stride;

  DrawTextureRec(
    sesame_walking,
    Rectangle{
      sesame_walking_frame_width * sesame_walking_down_current_frame,
      0,
      sesame_walking_frame_width,
      sesame_walking_frame_height},
    Vector2{
      sesame_position_top_left_x,
      sesame_position_top_left_y},
      WHITE);
}

void Sesame::walk_right() {
  sesame_current_action = 0;
  sesame_walking_right_current_frame += 1;
  sesame_walking_right_current_frame = sesame_walking_right_current_frame % sesame_walking_right_end_frame_index;

  if(sesame_walking_right_current_frame == 0) {
    sesame_walking_right_current_frame = sesame_walking_right_start_frame_index;
  }

  sesame_position_top_left_x += sesame_walking_stride;

  DrawTextureRec(
    sesame_walking,
    Rectangle{
      sesame_walking_frame_width * sesame_walking_right_current_frame,
      0,
      sesame_walking_frame_width,
      sesame_walking_frame_height},
    Vector2{
      sesame_position_top_left_x,
      sesame_position_top_left_y},
      WHITE);
}

void Sesame::walk_up() {
  sesame_current_action = 0;
  sesame_walking_up_current_frame += 1;
  sesame_walking_up_current_frame = sesame_walking_up_current_frame % sesame_walking_up_end_frame_index;

  if(sesame_walking_up_current_frame == 0) {
    sesame_walking_up_current_frame = sesame_walking_up_start_frame_index;
  }

  sesame_position_top_left_y -= sesame_walking_stride;

  DrawTextureRec(
    sesame_walking,
    Rectangle{
      sesame_walking_frame_width * sesame_walking_up_current_frame,
      0,
      sesame_walking_frame_width,
      sesame_walking_frame_height},
    Vector2{
      sesame_position_top_left_x,
      sesame_position_top_left_y},
      WHITE);
}

void Sesame::reverse_walk_left() {
  sesame_current_action = 0;
  sesame_position_top_left_x += sesame_walking_stride;
}

void Sesame::reverse_walk_down() {
  sesame_current_action = 0;
  sesame_position_top_left_y -= sesame_walking_stride;
}

void Sesame::reverse_walk_right() {
  sesame_current_action = 0;
  sesame_position_top_left_x -= sesame_walking_stride;
}

void Sesame::reverse_walk_up() {
  sesame_current_action = 0;
  sesame_position_top_left_y += sesame_walking_stride;
}

void Sesame::grooming() {
  sesame_current_action = 1;
  sesame_grooming_current_frame += 1;
  sesame_grooming_current_frame = sesame_grooming_current_frame % sesame_grooming_max_frames;

  DrawTextureRec(
    sesame_grooming,
    Rectangle{
      sesame_grooming_frame_width * sesame_grooming_current_frame,
      0,
      sesame_grooming_frame_width,
      sesame_grooming_frame_height},
    Vector2{
      sesame_position_top_left_x,
      sesame_position_top_left_y},
      WHITE);
}

void Sesame::sitting() {
  sesame_current_action = 2;
  sesame_sitting_current_frame += 1;
  sesame_sitting_current_frame = sesame_sitting_current_frame % sesame_sitting_end_frame_index;

  DrawTextureRec(
    sesame_sitting_meowing,
    Rectangle{
      sesame_sitting_meowing_frame_width * sesame_sitting_current_frame,
      0,
      sesame_sitting_meowing_frame_width,
      sesame_sitting_meowing_frame_height},
    Vector2{
      sesame_position_top_left_x,
      sesame_position_top_left_y},
      WHITE);
}

void Sesame::meowing() {
  sesame_current_action = 2;
  sesame_meowing_current_frame += 1;
  sesame_meowing_current_frame = sesame_meowing_current_frame % sesame_meowing_end_frame_index;

  if(sesame_meowing_current_frame == 0) {
    sesame_meowing_current_frame = sesame_meowing_start_frame_index;
  }

  DrawTextureRec(
    sesame_sitting_meowing,
    Rectangle{
      sesame_sitting_meowing_frame_width * sesame_meowing_current_frame,
      0,
      sesame_sitting_meowing_frame_width,
      sesame_sitting_meowing_frame_height},
    Vector2{
      sesame_position_top_left_x,
      sesame_position_top_left_y},
      WHITE);
}

void Sesame::eating() {
  sesame_current_action = 3;
  sesame_eating_current_frame += 1;
  sesame_eating_current_frame = sesame_eating_current_frame % sesame_eating_max_frames;

  DrawTextureRec(
    sesame_eating,
    Rectangle{
      sesame_eating_frame_width * sesame_eating_current_frame,
      0,
      sesame_eating_frame_width,
      sesame_eating_frame_height},
    Vector2{
      sesame_position_top_left_x,
      sesame_position_top_left_y},
      WHITE);
}

void Sesame::dancing() {
  sesame_current_action = 4;
  sesame_dancing_current_frame += 1;
  sesame_dancing_current_frame = sesame_dancing_current_frame % sesame_dancing_max_frames;

  DrawTextureRec(
    sesame_dancing,
    Rectangle{
      sesame_dancing_frame_width * sesame_dancing_current_frame,
      0,
      sesame_dancing_frame_width,
      sesame_dancing_frame_height},
    Vector2{
      sesame_position_top_left_x,
      sesame_position_top_left_y},
      WHITE);
}

void Sesame::scared() {
  sesame_current_action = 5;
  sesame_scared_current_frame += 1;
  sesame_scared_current_frame = sesame_scared_current_frame % sesame_scared_max_frames;

  DrawTextureRec(
    sesame_scared,
    Rectangle{
      sesame_scared_frame_width * sesame_scared_current_frame,
      0,
      sesame_scared_frame_width,
      sesame_scared_frame_height},
    Vector2{
      sesame_position_top_left_x,
      sesame_position_top_left_y},
      WHITE);
}

void Sesame::sleeping() {
  sesame_current_action = 6;
  sesame_sleeping_current_frame += 1;
  sesame_sleeping_current_frame = sesame_sleeping_current_frame % sesame_sleeping_end_frame_index;

  DrawTextureRec(
    sesame_sleeping_woken,
    Rectangle{
      sesame_sleeping_woken_frame_width * sesame_sleeping_current_frame,
      0,
      sesame_sleeping_woken_frame_width,
      sesame_sleeping_woken_frame_height},
    Vector2{
      sesame_position_top_left_x,
      sesame_position_top_left_y},
      WHITE);
}

void Sesame::woken() {
  sesame_current_action = 6;
  sesame_woken_current_frame += 1;
  sesame_woken_current_frame = sesame_woken_current_frame % sesame_woken_end_frame_index;

  if(sesame_woken_current_frame == 0) {
    sesame_woken_current_frame = sesame_woken_start_frame_index;
  }

  DrawTextureRec(
    sesame_sleeping_woken,
    Rectangle{
      sesame_sleeping_woken_frame_width * sesame_woken_current_frame,
      0,
      sesame_sleeping_woken_frame_width,
      sesame_sleeping_woken_frame_height},
    Vector2{
      sesame_position_top_left_x,
      sesame_position_top_left_y},
      WHITE);
}

int Sesame::get_sesame_grooming_current_frame() const {
  return sesame_grooming_current_frame;
}

int Sesame::get_sesame_meowing_current_frame() const {
  return sesame_meowing_current_frame;
}

void Sesame::reset_sesame_position() {
  sesame_position_top_left_x = sesame_start_position_top_left_x;
  sesame_position_top_left_y = sesame_start_position_top_left_y;
}
