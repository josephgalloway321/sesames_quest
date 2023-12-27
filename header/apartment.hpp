#pragma once
#include <raylib.h>
#include "../header/custom_colors.hpp"

class Apartment {
  private:
    Texture2D apartment;
    Rectangle interaction_boundary;

    int max_frames;
    float frame_width;
    float frame_height;
    int start_frame;
    int current_frame;
    int end_frame;
    float position_top_left_x, position_top_left_y;
    bool is_sesame_in_interaction_boundary;
    bool is_door_open;

  public:
    Apartment();
    ~Apartment();
    void initialize_apartment_room(int start_frame, int end_frame);
    void set_apartment_room_position(float x, float y);
    void draw_room();
    void update_current_frame(int current_frame);
    void set_interaction_boundary(Rectangle interaction_boundary);
    void draw_interaction_boundary();
    void set_is_sesame_in_interaction_boundary(bool condition);
    Rectangle get_interaction_boundary() const;
    bool get_is_sesame_in_interaction_boundary() const;
    void toggle_is_door_open();
    bool get_is_door_open() const;
};