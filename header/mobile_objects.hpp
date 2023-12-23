#pragma once
#include <string>
#include <raylib.h>

class Mobile_Objects {
  private:
    Texture2D mobile_object;
    Color CUSTOM_RED;
    Rectangle interaction_boundary;
    std::string path_to_texture;
    bool is_object_moved;
    float position_top_left_x;
    float position_top_left_y;
    bool is_sesame_in_interaction_boundary;
    void move_left(int distance);
    void move_right(int distance);
    void move_up(int distance);
    void move_down(int distance);

  public:
    Mobile_Objects();
    ~Mobile_Objects();
    bool get_is_object_moved();
    void toggle_is_object_moved();
    void initialize_object(std::string path_to_texture);
    void set_position(int position_top_left_x, int position_top_left_y);
    void set_interaction_boundary(Rectangle interaction_boundary);
    void set_is_sesame_in_interaction_boundary(bool condition);
    void draw_mobile_object() const;
    void draw_interaction_boundary();
    float get_position_top_left_x() const;
    float get_position_top_left_y() const;
    Rectangle get_interaction_boundary() const;
    bool get_is_sesame_in_interaction_boundary() const;
    void toggle_move(char direction, int distance);
};