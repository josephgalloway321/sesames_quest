#pragma once
#include <raylib.h>

class Apartment {
  private:
    Texture2D apartment;

    float apartment_laundry_kitchen_top_left_x;
    float apartment_laundry_kitchen_top_left_y;

    int apartment_max_frames;
    float apartment_frame_width;
    float apartment_frame_height;
    //int apartment_start_frame_index;
    //int apartment_end_frame_index;
    int apartment_current_frame_index;

  public:
    Apartment();
    ~Apartment();
    void show_apartment();
};