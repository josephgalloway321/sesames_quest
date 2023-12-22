#pragma once
#include <raylib.h>

class Apartment {
  private:
    Texture2D apartment;

    float apartment_laundry_kitchen_top_left_x;
    float apartment_laundry_kitchen_top_left_y;
    float apartment_living_room_top_left_x;
    float apartment_living_room_top_left_y;
    float apartment_bathroom_closets_top_left_x;
    float apartment_bathroom_closets_top_left_y;
    float apartment_bedroom_top_left_x;
    float apartment_bedroom_top_left_y;

    int apartment_max_frames;
    float apartment_frame_width;
    float apartment_frame_height;
    //int apartment_laundry_kitchen_start_frame_index;
    //int apartment_laundry_kitchen_end_frame_index;
    int apartment_laundry_kitchen_current_frame_index;
    int apartment_living_room_current_frame_index;
    int apartment_bathroom_closets_current_frame_index;
    int apartment_bedroom_current_frame_index;

  public:
    Apartment();
    ~Apartment();
    void draw_laundry_kitchen_rooms();
    void draw_living_room();
    void draw_bathroom_closets();
    void draw_bedroom();
};