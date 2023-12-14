#pragma once
#include <raylib.h>

class Sesame {
  private:
    int sesame_walking_max_frames;
    float sesame_walking_frame_width;
    float sesame_walking_frame_height;
    int sesame_walking_current_frame;
    int sesame_walking_position_x;
    int sesame_walking_position_y;

  public:
    Texture2D sesame_walking;
    Texture2D sesame_grooming;
    Sesame();
    ~Sesame();
    float get_sesame_walking_frame_width();
    float get_sesame_walking_frame_height();
    int get_sesame_walking_current_frame();
    void iterate_sesame_walking_current_frame();
    float get_sesame_walking_position_x();
    float get_sesame_walking_position_y();
    void set_sesame_walking_position_x();
    void set_sesame_walking_position_y();
};