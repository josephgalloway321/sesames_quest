#include "../header/apartment.hpp"

Apartment::Apartment() {
  apartment = LoadTexture("C:/Users/josep/Documents/GitHub/sesames_quest/resources/sprites/apartment.png");
  apartment_max_frames = 13;
  apartment_frame_width = (float)(apartment.width / apartment_max_frames);
  apartment_frame_height = apartment.height;

  apartment_laundry_kitchen_current_frame_index = 0;
  apartment_living_room_current_frame_index = 7;
  apartment_bathroom_closets_current_frame_index = 8;
  apartment_bedroom_current_frame_index = 11;

  apartment_laundry_kitchen_top_left_x = 0;
  apartment_laundry_kitchen_top_left_y = 0;
  apartment_living_room_top_left_x = 0;
  apartment_living_room_top_left_y = apartment_frame_height;
  apartment_bathroom_closets_top_left_x = apartment_frame_width;
  apartment_bathroom_closets_top_left_y = 0;
  apartment_bedroom_top_left_x = apartment_frame_width;
  apartment_bedroom_top_left_y = apartment_frame_height;
}

Apartment::~Apartment() {
  UnloadTexture(apartment);
}

void Apartment::show_laundry_kitchen_rooms() {
  DrawTextureRec(
    apartment,
    Rectangle{
      apartment_frame_width * apartment_laundry_kitchen_current_frame_index,
      0,
      apartment_frame_width,
      apartment_frame_height},
    Vector2{
      apartment_laundry_kitchen_top_left_x,
      apartment_laundry_kitchen_top_left_y},
      WHITE);
}

void Apartment::show_living_room() {
  DrawTextureRec(
    apartment,
    Rectangle{
      apartment_frame_width * apartment_living_room_current_frame_index,
      0,
      apartment_frame_width,
      apartment_frame_height},
    Vector2{
      apartment_living_room_top_left_x,
      apartment_living_room_top_left_y},
      WHITE);
}

void Apartment::show_bathroom_closets() {
  DrawTextureRec(
    apartment,
    Rectangle{
      apartment_frame_width * apartment_bathroom_closets_current_frame_index,
      0,
      apartment_frame_width,
      apartment_frame_height},
    Vector2{
      apartment_bathroom_closets_top_left_x,
      apartment_bathroom_closets_top_left_y},
      WHITE);
}

void Apartment::show_bedroom() {
  DrawTextureRec(
    apartment,
    Rectangle{
      apartment_frame_width * apartment_bedroom_current_frame_index,
      0,
      apartment_frame_width,
      apartment_frame_height},
    Vector2{
      apartment_bedroom_top_left_x,
      apartment_bedroom_top_left_y},
      WHITE);
}
