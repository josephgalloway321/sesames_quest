#include "../header/sesame.hpp"

Sesame::Sesame() {
  sesame_walking = LoadTexture("C:/Users/josep/Documents/GitHub/sesames_quest/resources/sprites/sesame/sesame_walking.png");
  
  sesame_position_x = 250;  // Position x at the start of the game
  sesame_position_y = 250;  // Position y at the start of the game
  
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
  sesame_walking_stride = 15;  // Stride length in pixels while walking
  
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
}

Sesame::~Sesame() {
  UnloadTexture(sesame_walking);
  UnloadTexture(sesame_grooming);
}

float Sesame::get_sesame_position_x() const {
  return sesame_position_x;
}

float Sesame::get_sesame_position_y() const {
  return sesame_position_y;
}

// Walking
void Sesame::walk_left() {
  sesame_walking_left_current_frame += 1;
  sesame_walking_left_current_frame = sesame_walking_left_current_frame % sesame_walking_left_end_frame_index;

  sesame_position_x -= sesame_walking_stride;

  DrawTextureRec(
    sesame_walking,
    Rectangle{
      sesame_walking_frame_width * sesame_walking_left_current_frame,
      0,
      sesame_walking_frame_width,
      sesame_walking_frame_height},
    Vector2{
      get_sesame_position_x(),
      get_sesame_position_y()},
    WHITE);
}

void Sesame::walk_down() {
  sesame_walking_down_current_frame += 1;
  sesame_walking_down_current_frame = sesame_walking_down_current_frame % sesame_walking_down_end_frame_index;

  if(sesame_walking_down_current_frame == 0) {
    sesame_walking_down_current_frame = sesame_walking_down_start_frame_index;
  }

  sesame_position_y += sesame_walking_stride;

  DrawTextureRec(
    sesame_walking,
    Rectangle{
      sesame_walking_frame_width * sesame_walking_down_current_frame,
      0,
      sesame_walking_frame_width,
      sesame_walking_frame_height},
    Vector2{
      get_sesame_position_x(),
      get_sesame_position_y()},
    WHITE);
}

void Sesame::walk_right() {
  sesame_walking_right_current_frame += 1;
  sesame_walking_right_current_frame = sesame_walking_right_current_frame % sesame_walking_right_end_frame_index;

  if(sesame_walking_right_current_frame == 0) {
    sesame_walking_right_current_frame = sesame_walking_right_start_frame_index;
  }

  sesame_position_x += sesame_walking_stride;

  DrawTextureRec(
    sesame_walking,
    Rectangle{
      sesame_walking_frame_width * sesame_walking_right_current_frame,
      0,
      sesame_walking_frame_width,
      sesame_walking_frame_height},
    Vector2{
      get_sesame_position_x(),
      get_sesame_position_y()},
    WHITE);
}

void Sesame::walk_up() {
  sesame_walking_up_current_frame += 1;
  sesame_walking_up_current_frame = sesame_walking_up_current_frame % sesame_walking_up_end_frame_index;

  if(sesame_walking_up_current_frame == 0) {
    sesame_walking_up_current_frame = sesame_walking_up_start_frame_index;
  }

  sesame_position_y -= sesame_walking_stride;

  DrawTextureRec(
    sesame_walking,
    Rectangle{
      sesame_walking_frame_width * sesame_walking_up_current_frame,
      0,
      sesame_walking_frame_width,
      sesame_walking_frame_height},
    Vector2{
      get_sesame_position_x(),
      get_sesame_position_y()},
    WHITE);
}

// Grooming
void Sesame::groom() {
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
      get_sesame_position_x(),
      get_sesame_position_y()},
    WHITE);
}

// Sitting
void Sesame::sitting() {
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
      get_sesame_position_x(),
      get_sesame_position_y()},
    WHITE);
}

// Meowing
