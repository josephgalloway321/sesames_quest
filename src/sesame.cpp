#include "../header/sesame.hpp"

Sesame::Sesame() {
  sesame_walking = LoadTexture("C:/Users/josep/Documents/GitHub/sesames_quest/resources/sprites/sesame/sesame_walking.png");
  sesame_walking_max_frames = 16;  //  Number of frames in the original png file
  sesame_walking_frame_width = (float)(sesame_walking.width / sesame_walking_max_frames);   // Calculate the width of each frame in image
  sesame_walking_frame_height = sesame_walking.height;
  sesame_walking_current_frame = 0;  // Frame counter to keep track of current frame
  sesame_walking_position_x = 250;  // Position x at the start of the game
  sesame_walking_position_y = 250;  // Position y at the start of the game
  
  sesame_grooming = LoadTexture("C:/Users/josep/Documents/GitHub/sesames_quest/resources/sprites/sesame/sesame_grooming.png");
  sesame_grooming_max_frames = 12;  //  Number of frames in the original png file
  sesame_grooming_frame_width = (float)(sesame_walking.width / sesame_walking_max_frames);   // Calculate the width of each frame in image
  sesame_grooming_frame_height = sesame_walking.height;
  sesame_grooming_current_frame = 0;  // Frame counter to keep track of current frame
  sesame_grooming_position_x = 350;  // Position x at the start of the game
  sesame_grooming_position_y = 350;  // Position y at the start of the game
}

Sesame::~Sesame() {
  UnloadTexture(sesame_walking);
  UnloadTexture(sesame_grooming);
}

// Walking
float Sesame::get_sesame_walking_frame_width() const {
  return sesame_walking_frame_width;
}

float Sesame::get_sesame_walking_frame_height() const {
  return sesame_walking_frame_height;
}

int Sesame::get_sesame_walking_current_frame() const {
  return sesame_walking_current_frame;
}

void Sesame::iterate_sesame_walking_current_frame() {
  sesame_walking_current_frame += 1;
  // Frame will count up to maximum frames value then reset at zero
  sesame_walking_current_frame = sesame_walking_current_frame % sesame_walking_max_frames;
}

float Sesame::get_sesame_walking_position_x() const {
  return sesame_walking_position_x;
}

float Sesame::get_sesame_walking_position_y() const {
  return sesame_walking_position_y;
}

void Sesame::set_sesame_walking_position_x() {
  sesame_walking_position_x = 0;
}

void Sesame::set_sesame_walking_position_y() {
  sesame_walking_position_y = 0;
}

// Grooming
float Sesame::get_sesame_grooming_frame_width() const {
  return sesame_grooming_frame_width;
}

float Sesame::get_sesame_grooming_frame_height() const {
  return sesame_grooming_frame_height;
}

int Sesame::get_sesame_grooming_current_frame() const {
  return sesame_grooming_current_frame;
}

void Sesame::iterate_sesame_grooming_current_frame() {
  sesame_grooming_current_frame += 1;
  // Frame will count up to maximum frames value then reset at zero
  sesame_grooming_current_frame = sesame_grooming_current_frame % sesame_grooming_max_frames;
}

float Sesame::get_sesame_grooming_position_x() const {
  return sesame_grooming_position_x;
}

float Sesame::get_sesame_grooming_position_y() const {
  return sesame_grooming_position_y;
}

void Sesame::set_sesame_grooming_position_x() {
  sesame_grooming_position_x = 0;
}

void Sesame::set_sesame_grooming_position_y() {
  sesame_grooming_position_y = 0;
}