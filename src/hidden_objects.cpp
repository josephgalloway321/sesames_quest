#include "../header/hidden_objects.hpp"

Hidden_Objects::Hidden_Objects() {

}

Hidden_Objects::~Hidden_Objects() {
  UnloadTexture(hidden_object);
}

void Hidden_Objects::initialize_object(std::string path_to_texture, float position_top_left_x, float position_top_left_y) {
  this -> position_top_left_x = position_top_left_x;
  this -> position_top_left_y = position_top_left_y;
  hidden_object = LoadTexture(path_to_texture.c_str());
}

void Hidden_Objects::draw_mobile_object() const {
  DrawTexture(hidden_object, position_top_left_x, position_top_left_y, WHITE);
}

float Hidden_Objects::get_position_top_left_x() const {
  return position_top_left_x;
}

float Hidden_Objects::get_position_top_left_y() const {
  return position_top_left_y;
}
