#pragma once
#include <string>
#include <raylib.h>

class Mobile_Objects {
  private:
    Texture2D mobile_object;
    std::string path_to_texture;
    float position_top_left_x;
    float position_top_left_y;

  public:
    Mobile_Objects();
    ~Mobile_Objects();
    void initialize_object(std::string path_to_texture, float position_top_left_x, float position_top_left_y);
    void draw_mobile_object() const;
    float get_position_top_left_x() const;
    float get_position_top_left_y() const;
    void move_left();
    void move_right();
    void move_up();
    void move_down();
};