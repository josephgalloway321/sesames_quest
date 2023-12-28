#pragma once
#include <raylib.h>
#include <vector>
#include <string>
#include "../header/custom_colors.hpp"

class Sesame {
  private:
    Texture2D sesame_walking;
    Texture2D sesame_grooming;
    Texture2D sesame_sitting_meowing;
    Texture2D sesame_eating;
    Texture2D sesame_dancing;
    Texture2D sesame_scared;
    Texture2D sesame_sleeping_woken;
    Texture2D sesame_happy_sad;

    int sesame_current_action;

    float sesame_start_position_top_left_x;
    float sesame_start_position_top_left_y;
    float sesame_position_top_left_x;
    float sesame_position_top_left_y;
    float sesame_position_bottom_right_x;
    float sesame_position_bottom_right_y;
    std::vector<std::vector<float>> sesame_frame_coordinates;
    Rectangle sesame_boundary;

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

    int sesame_eating_max_frames;
    float sesame_eating_frame_width;
    float sesame_eating_frame_height; 
    int sesame_eating_current_frame; 

    int sesame_dancing_max_frames;
    float sesame_dancing_frame_width;
    float sesame_dancing_frame_height; 
    int sesame_dancing_current_frame;

    int sesame_scared_max_frames;
    float sesame_scared_frame_width;
    float sesame_scared_frame_height; 
    int sesame_scared_current_frame;

    int sesame_sleeping_woken_max_frames;
    float sesame_sleeping_woken_frame_width;
    float sesame_sleeping_woken_frame_height;
    int sesame_sleeping_start_frame_index;
    int sesame_woken_start_frame_index;
    int sesame_sleeping_current_frame;
    int sesame_woken_current_frame;
    int sesame_sleeping_end_frame_index;
    int sesame_woken_end_frame_index;

    int sesame_happy_sad_max_frames;
    float sesame_happy_sad_frame_width;
    float sesame_happy_sad_frame_height; 

  public:
    Sesame();
    ~Sesame();
    std::vector<std::vector<float>> get_sesame_frame_coordinates();
    Rectangle get_sesame_boundary();

    void walk_left();
    void walk_down();
    void walk_right();
    void walk_up();
    void reverse_walk_left();
    void reverse_walk_down();
    void reverse_walk_right();
    void reverse_walk_up();

    void grooming();
    void sitting();
    void meowing();
    void eating();
    void dancing();
    void scared();
    void sleeping();
    void woken();

    void happy();
    void sad();

    int get_sesame_grooming_current_frame() const;
    int get_sesame_meowing_current_frame() const;

    void reset_sesame_position(); 
};