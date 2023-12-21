#include "../header/mobile_objects.hpp"

Mobile_Objects::Mobile_Objects() {

}

Mobile_Objects::~Mobile_Objects() {
  UnloadTexture(mobile_object);
}

// Couldn't figure out how to initialize object using constructor; issue when 
// instantiating a Mobile_Objects object in game class header file with parameters
void Mobile_Objects::initialize_object(std::string path_to_texture, float position_top_left_x, float position_top_left_y) {
  this -> position_top_left_x = position_top_left_x;
  this -> position_top_left_y = position_top_left_y;
  mobile_object = LoadTexture(path_to_texture.c_str());
}

void Mobile_Objects::show_mobile_object() const {
  DrawTexture(mobile_object, position_top_left_x, position_top_left_y, WHITE);
}

float Mobile_Objects::get_position_top_left_x() const {
  return position_top_left_x;
}

float Mobile_Objects::get_position_top_left_y() const {
  return position_top_left_y;
}

void Mobile_Objects::move_left() {
  position_top_left_x -= 30;
}

void Mobile_Objects::move_right() {
  position_top_left_x += 30;
}