#pragma once
#include <raylib.h>
#include <vector>
#include <string>
#include "../header/custom_colors.hpp"

class Sesame {
  private:
    // Walking left, walking down, walking right, walking up
    // Grooming, sitting, meowing, eating, dancing
    // Frightened, napping, awake
    Texture2D sesame;

    int max_frames;
    float frame_width;
    float frame_height;
    int start_frame;
    int current_frame;
    int end_frame;
    float position_top_left_x, position_top_left_y;

    int walking_stride;

    std::vector<std::vector<float>> frame_coordinates;
    Rectangle boundary;

  public:
    Sesame();
    ~Sesame();
    void initialize_action(char action);
    void set_posiiton();

    // TODO: Go through methods below
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

    int get_sesame_grooming_current_frame() const;
    int get_sesame_meowing_current_frame() const;

    void reset_sesame_position(); 
};