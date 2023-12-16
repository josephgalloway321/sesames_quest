#pragma once
#include "../header/sesame.hpp"
#include "../header/timers.hpp"

class Game {
  private:
    Sesame sesame;
    Timer timer_example;
    Timer timer_draw_rect;
    int SCREEN_WIDTH, SCREEN_HEIGHT;
    bool is_time_example;
    
  public:
    Game(int SCREEN_WIDTH, int SCREEN_HEIGHT);
    ~Game();
    void handle_keyboard_input();
    void toggle_full_screen_window(int window_width, int window_height);
};