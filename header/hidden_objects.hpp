#pragma once
#include <raylib.h>
#include <string>
#include "../header/custom_colors.hpp"

class Hidden_Objects {
  private:
    Texture2D hidden_object;
    Rectangle collision_boundary;
    std::string path_to_texture;
    float position_top_left_x;
    float position_top_left_y;

  public:
    Hidden_Objects();
    ~Hidden_Objects();
    void initialize_object(std::string path_to_texture);
    void set_position(int position_top_left_x, int position_top_left_y);
    void set_collision_boundary();
    void draw_hidden_object() const;
    void draw_collision_boundary();
    float get_position_top_left_x() const;
    float get_position_top_left_y() const;
    Rectangle get_collision_boundary() const;
    void move_left();
    void move_right();
    void move_up();
    void move_down();
};