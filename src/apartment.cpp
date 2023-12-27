#include "../header/apartment.hpp"

Apartment::Apartment() {
  apartment = LoadTexture("C:/Users/josep/Documents/GitHub/sesames_quest/resources/sprites/apartment.png");
  
  max_frames = 13;
  frame_width = (float)(apartment.width / max_frames);
  frame_height = apartment.height;

  position_top_left_x = 0;
  position_top_left_y = 0;

  start_frame = 0;
  current_frame = 0;
  end_frame = 0;

  is_door_open = false;
}

Apartment::~Apartment() {
  UnloadTexture(apartment);
}

void Apartment::initialize_apartment_room(int start_frame, int end_frame) {
  this -> start_frame = start_frame;
  current_frame = start_frame;
  this -> end_frame = end_frame;  // Exclusive
}

void Apartment::set_apartment_room_position(float x, float y) {
  position_top_left_x = x;
  position_top_left_y = y;
}

void Apartment::draw_room() {
  DrawTextureRec(
    apartment,
    Rectangle{
      frame_width * current_frame,
      0,
      frame_width,
      frame_height},
    Vector2{
      position_top_left_x,
      position_top_left_y},
      WHITE);
}

void Apartment::update_current_frame(int current_frame) {
  this -> current_frame = current_frame;
}

void Apartment::set_interaction_boundary(Rectangle interaction_boundary) {
  this -> interaction_boundary = interaction_boundary;
}

void Apartment::set_is_sesame_in_interaction_boundary(bool condition) {
  is_sesame_in_interaction_boundary = condition;
}

Rectangle Apartment::get_interaction_boundary() const {
  return interaction_boundary;
}

bool Apartment::get_is_sesame_in_interaction_boundary() const {
  return is_sesame_in_interaction_boundary;
}

void Apartment::toggle_is_door_open() {
  is_door_open = !is_door_open;
}

bool Apartment::get_is_door_open() const {
  return is_door_open;
}

void Apartment::draw_interaction_boundary() {
  DrawRectangleRec(interaction_boundary, CUSTOM_RED);
}

