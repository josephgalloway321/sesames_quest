#pragma once
#include <raylib.h>

class Apartment {
  private:
    Texture2D apartment;

    int max_frames;
    float frame_width;
    float frame_height;
    int start_frame;
    int current_frame;
    int end_frame;
    float position_top_left_x, position_top_left_y;

  public:
    Apartment();
    ~Apartment();
    void initialize_apartment_room(int start_frame, int end_frame);
    void set_apartment_room_position(float x, float y);
    void draw_room();
    void update_current_frame(int current_frame);
};