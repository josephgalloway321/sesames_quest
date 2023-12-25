#include "../header/hidden_objects.hpp"

Hidden_Objects::Hidden_Objects() {
  collision_boundary = {0, 0, 0, 0};
}

Hidden_Objects::~Hidden_Objects() {
  UnloadTexture(hidden_object);
}

void Hidden_Objects::initialize_object(std::string path_to_texture) {
  hidden_object = LoadTexture(path_to_texture.c_str());
}

void Hidden_Objects::set_position(int position_top_left_x, int position_top_left_y) {
  this -> position_top_left_x = position_top_left_x;
  this -> position_top_left_y = position_top_left_y;
}

void Hidden_Objects::set_collision_boundary() {
  collision_boundary = {
    position_top_left_x + 20, // Add for adjustment
    position_top_left_y + 20, 
    60, 32};
}

void Hidden_Objects::draw_hidden_object() const {
  DrawTexture(hidden_object, position_top_left_x, position_top_left_y, WHITE);
  //DrawCircle(position_top_left_x, position_top_left_y, 6, BLUE);
}

void Hidden_Objects::draw_collision_boundary() {
  DrawRectangleRec(collision_boundary, CUSTOM_BLUE);
}

float Hidden_Objects::get_position_top_left_x() const {
  return position_top_left_x;
}

float Hidden_Objects::get_position_top_left_y() const {
  return position_top_left_y;
}

Rectangle Hidden_Objects::get_collision_boundary() const {
  return collision_boundary;
}

void Hidden_Objects::move_left() {
  position_top_left_x -= 30;
}

void Hidden_Objects::move_right() {
  position_top_left_x += 30;
}

void Hidden_Objects::move_up() {
  position_top_left_y -= 30;
}

void Hidden_Objects::move_down() {
  position_top_left_y += 30;
}
