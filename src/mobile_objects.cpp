#include "../header/mobile_objects.hpp"

Mobile_Objects::Mobile_Objects() {
  is_sesame_in_interaction_boundary = false;
  is_object_moved = false;
  collision_boundary = {0, 0, 0, 0};
}

Mobile_Objects::~Mobile_Objects() {
  UnloadTexture(mobile_object);
}

// Couldn't figure out how to initialize object using constructor; issue when 
// instantiating a Mobile_Objects object in game class header file with parameters
void Mobile_Objects::initialize_object(std::string path_to_texture) {
  mobile_object = LoadTexture(path_to_texture.c_str());
}

void Mobile_Objects::set_is_sesame_in_interaction_boundary(bool condition) {
  is_sesame_in_interaction_boundary = condition;
}

void Mobile_Objects::set_position(int position_top_left_x, int position_top_left_y) {
  this -> position_top_left_x = position_top_left_x;
  this -> position_top_left_y = position_top_left_y;
}

void Mobile_Objects::set_interaction_boundary(Rectangle interaction_boundary) {
  this -> interaction_boundary = interaction_boundary;
}

void Mobile_Objects::set_collision_boundary(Rectangle collision_boundary) {
  this -> collision_boundary = collision_boundary;
}

void Mobile_Objects::draw_mobile_object() const {
  DrawTexture(mobile_object, position_top_left_x, position_top_left_y, WHITE);
}

void Mobile_Objects::draw_interaction_boundary() {
  DrawRectangleRec(interaction_boundary, CUSTOM_RED);
}

void Mobile_Objects::draw_collision_boundary() {
  DrawRectangleRec(collision_boundary, CUSTOM_BLUE);
}

float Mobile_Objects::get_position_top_left_x() const {
  return position_top_left_x;
}

float Mobile_Objects::get_position_top_left_y() const {
  return position_top_left_y;
}

Rectangle Mobile_Objects::get_interaction_boundary() const {
  return interaction_boundary;
}

Rectangle Mobile_Objects::get_collision_boundary() const {
  return collision_boundary;
}

bool Mobile_Objects::get_is_sesame_in_interaction_boundary() const {
  return is_sesame_in_interaction_boundary;
}

void Mobile_Objects::toggle_move(char direction, int distance) {
  if(direction == 'l') {
    move_left(distance);
    collision_boundary.x -= distance;  // Adjust collision boundary
  }
  else if(direction == 'r') {
    move_right(distance);
    collision_boundary.x += distance;  // Adjust collision boundary
  }
  else if(direction == 'u') {
    move_up(distance);
    collision_boundary.y -= distance;  // Adjust collision boundary
  }
  else if(direction == 'd') {
    move_down(distance);
    collision_boundary.y += distance;  // Adjust collision boundary
  }
}

void Mobile_Objects::move_left(int distance) {
  position_top_left_x -= distance;
}

void Mobile_Objects::move_right(int distance) {
  position_top_left_x += distance;
}

void Mobile_Objects::move_up(int distance) {
  position_top_left_y -= distance;
}

void Mobile_Objects::move_down(int distance) {
  position_top_left_y += distance;
}

bool Mobile_Objects::get_is_object_moved() {
  return is_object_moved;
}

void Mobile_Objects::toggle_is_object_moved() {
  is_object_moved = !is_object_moved;
}