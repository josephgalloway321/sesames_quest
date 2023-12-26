#pragma once
#include <raylib.h>
#include <string>

class Goals {
  private:
    Texture2D goal;

    std::string goal_text;
    int max_frames; 
    float frame_width;
    float frame_height;
    int current_frame;  // Current frame will change depending on goal status
    bool is_goal_accomplished;
    float position_top_left_x;
    float position_top_left_y;

  public:
    Goals();
    ~Goals();
    void set_position(int position_top_left_x, int position_top_left_y);
    void set_goal_text(std::string goal_text);
    void draw_goal() const;
    void draw_goal_accomplished() const;
    void draw_goal_failed() const;
    bool get_is_goal_accomplished();
    void set_goal_accomplshed();
    void set_goal_failed();
};