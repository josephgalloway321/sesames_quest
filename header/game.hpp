#pragma once
#include "../header/sesame.hpp"
#include "../header/timers.hpp"

class Game {
  private:
    Sesame sesame;
    Timer timer_until_meow;
    Timer timer_meow_duration;
    int SCREEN_WIDTH, SCREEN_HEIGHT;
    bool is_time_to_meow;
    int seconds_until_meow;
    int seconds_meow_duration;
    bool is_sesame_inside_screen;
    void toggle_full_screen_window(int window_width, int window_height);
    
  public:
    Game(int SCREEN_WIDTH, int SCREEN_HEIGHT);
    ~Game();
    void check_if_sesame_inside_screen();
    void handle_keyboard_input();
    void debug_show_sesame_frame_coordinates();
};