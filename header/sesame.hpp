#pragma once
#include <raylib.h>
#include <vector>
#include <string>

class Sesame {
  private:
    Texture2D sesame_walking;
    Texture2D sesame_grooming;
    Texture2D sesame_sitting_meowing;

    int sesame_current_action;

    float sesame_position_top_left_x;
    float sesame_position_top_left_y;
    float sesame_position_bottom_right_x;
    float sesame_position_bottom_right_y;
    std::vector<std::vector<float>> sesame_frame_coordinates;

    int SCREEN_WIDTH, SCREEN_HEIGHT;

    int sesame_walking_max_frames;
    float sesame_walking_frame_width;
    float sesame_walking_frame_height;
    int sesame_walking_left_start_frame_index;
    int sesame_walking_down_start_frame_index;
    int sesame_walking_right_start_frame_index;
    int sesame_walking_up_start_frame_index;
    int sesame_walking_left_end_frame_index;
    int sesame_walking_down_end_frame_index;
    int sesame_walking_right_end_frame_index;
    int sesame_walking_up_end_frame_index;
    int sesame_walking_left_current_frame;
    int sesame_walking_down_current_frame;
    int sesame_walking_right_current_frame;
    int sesame_walking_up_current_frame;
    int sesame_walking_stride;

    int sesame_grooming_max_frames;
    float sesame_grooming_frame_width;
    float sesame_grooming_frame_height; 
    int sesame_grooming_current_frame; 

    int sesame_sitting_meowing_max_frames;
    float sesame_sitting_meowing_frame_width;
    float sesame_sitting_meowing_frame_height;
    int sesame_sitting_start_frame_index;
    int sesame_meowing_start_frame_index;
    int sesame_sitting_current_frame;
    int sesame_meowing_current_frame;
    int sesame_sitting_end_frame_index;
    int sesame_meowing_end_frame_index;

    // Eating

    // Dancing

    // Scared

  public:
    Sesame();
    ~Sesame();
    std::vector<std::vector<float>> get_sesame_frame_coordinates();

    void walk_left();
    void walk_down();
    void walk_right();
    void walk_up();
    void reverse_walk_left();
    void reverse_walk_down();
    void reverse_walk_right();
    void reverse_walk_up();

    void groom();
    void sitting();
    void meowing();
};