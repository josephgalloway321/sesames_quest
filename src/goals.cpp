#include "../header/goals.hpp"

Goals::Goals() {
  goal = LoadTexture("C:/Users/josep/Documents/GitHub/sesames_quest/resources/sprites/goals.png");
  max_frames = 3;
  frame_width = (float)(goal.width / max_frames);
  frame_height = goal.height;
  
  is_goal_accomplished = false;
  current_frame = 0;
}

Goals::~Goals() {
  UnloadTexture(goal);
}

void Goals::set_position(int position_top_left_x, int position_top_left_y) {
  this -> position_top_left_x = position_top_left_x;
  this -> position_top_left_y = position_top_left_y;
}

void Goals::set_goal_text(std::string goal_text) {
  this -> goal_text = goal_text;
}

void Goals::draw_goal() const {
  DrawTextureRec(
    goal,
    Rectangle{
      frame_width * current_frame,
      0,
      frame_width,
      frame_height},
    Vector2{
      position_top_left_x,
      position_top_left_y},
      WHITE);
  DrawText(goal_text.c_str(), position_top_left_x + 50, position_top_left_y, 30, WHITE);
}

void Goals::draw_goal_accomplished() const {
  
}

void Goals::draw_goal_failed() const {
  
}

bool Goals::get_is_goal_accomplished() {
  return is_goal_accomplished;
}

void Goals::set_goal_accomplshed() {
  is_goal_accomplished = true;
}

void Goals::set_goal_failed() {
  is_goal_accomplished = false;
}
