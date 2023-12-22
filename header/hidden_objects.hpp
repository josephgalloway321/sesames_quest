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
    void initialize_object(std::string path_to_texture, float position_top_left_x, float position_top_left_y);
    void draw_mobile_object() const;
    float get_position_top_left_x() const;
    float get_position_top_left_y() const;
};