#include "../header/apartment.hpp"

Apartment::Apartment() {
  apartment_laundry_kitchen_top_left_x = 0;
  apartment_laundry_kitchen_top_left_y = 0;
  
  apartment = LoadTexture("C:/Users/josep/Documents/GitHub/sesames_quest/resources/sprites/apartment.png");
  apartment_max_frames = 8;
  apartment_frame_width = (float)(apartment.width / apartment_max_frames);
  apartment_frame_height = apartment.height;
  apartment_current_frame_index = 0;
}

Apartment::~Apartment() {
  UnloadTexture(apartment);
}

void Apartment::show_apartment() {
  DrawTextureRec(
    apartment,
    Rectangle{
      apartment_frame_width * apartment_current_frame_index,
      0,
      apartment_frame_width,
      apartment_frame_height},
    Vector2{
      apartment_laundry_kitchen_top_left_x,
      apartment_laundry_kitchen_top_left_y},
      WHITE);
}