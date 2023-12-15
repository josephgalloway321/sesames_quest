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

    int sesame_grooming_max_frames;
    float sesame_grooming_frame_width;
    float sesame_grooming_frame_height; 
    int sesame_grooming_current_frame;
    int sesame_grooming_position_x; 
    int sesame_grooming_position_y;     

  public:
    Texture2D sesame_walking;
    Texture2D sesame_grooming;
    Sesame();
    ~Sesame();

    float get_sesame_walking_frame_width() const;
    float get_sesame_walking_frame_height() const;
    int get_sesame_walking_current_frame() const;
    void iterate_sesame_walking_current_frame();
    float get_sesame_walking_position_x() const;
    float get_sesame_walking_position_y() const;
    void set_sesame_walking_position_x();
    void set_sesame_walking_position_y();

    float get_sesame_grooming_frame_width() const;
    float get_sesame_grooming_frame_height() const;
    int get_sesame_grooming_current_frame() const;
    void iterate_sesame_grooming_current_frame();
    float get_sesame_grooming_position_x() const;
    float get_sesame_grooming_position_y() const;
    void set_sesame_grooming_position_x();
    void set_sesame_grooming_position_y();
};