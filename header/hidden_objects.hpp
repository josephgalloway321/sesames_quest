#pragma once
#include <raylib.h>
#include <string>

class Hidden_Objects {
  private:
    Texture2D hidden_object;
    std::string path_to_texture;
    float position_top_left_x;
    float position_top_left_y;

  public:
    Hidden_Objects();
    ~Hidden_Objects();
    void initialize_object(std::string path_to_texture);
    void draw_hidden_object() const;
    float get_position_top_left_x() const;
    float get_position_top_left_y() const;
    void set_position(int position_top_left_x, int position_top_left_y);
    void move_left();
    void move_right();
    void move_up();
    void move_down();
};