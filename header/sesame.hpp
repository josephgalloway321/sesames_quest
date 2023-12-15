#pragma once
#include <raylib.h>

class Sesame {
  private:
    int sesame_position_x;
    int sesame_position_y;

    int sesame_walking_max_frames;
    float sesame_walking_frame_width;
    float sesame_walking_frame_height;
    int sesame_walking_left_start_frame_index;
    int sesame_walking_left_end_frame_index;
    int sesame_walking_left_current_frame;
    int sesame_walking_down_start_frame_index;
    int sesame_walking_down_end_frame_index;
    int sesame_walking_down_current_frame;
    int sesame_walking_right_start_frame_index;
    int sesame_walking_right_end_frame_index;
    int sesame_walking_right_current_frame;
    int sesame_walking_up_start_frame_index;
    int sesame_walking_up_end_frame_index;
    int sesame_walking_up_current_frame;
    int sesame_walking_stride;

    int sesame_grooming_max_frames;
    float sesame_grooming_frame_width;
    float sesame_grooming_frame_height; 
    int sesame_grooming_current_frame;    

  public:
    Texture2D sesame_walking;
    Texture2D sesame_grooming;
    Sesame();
    ~Sesame();

    void iterate_sesame_frames();

    float get_sesame_position_x() const;
    float get_sesame_position_y() const;

    float get_sesame_walking_frame_width() const;
    float get_sesame_walking_frame_height() const;
    void walk_left();
    void walk_right();
    void walk_up();
    void walk_down();

    float get_sesame_grooming_frame_width() const;
    float get_sesame_grooming_frame_height() const;
    int get_sesame_grooming_current_frame() const;
    void groom();

    void waiting();
};