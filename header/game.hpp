#pragma once
#include "../header/sesame.hpp"
#include "../header/timers.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>

class Game {
  private:
    Sesame sesame;
    Timer timer_until_meow_groom;
    Timer timer_meow_duration;
    Timer timer_groom_duration;
    int SCREEN_WIDTH, SCREEN_HEIGHT;
    bool is_time_to_meow_groom;
    bool meow;
    bool groom;
    int seconds_until_meow_groom;
    int seconds_meow_duration;
    int seconds_groom_duration;
    void toggle_full_screen_window(int window_width, int window_height);
    
  public:
    Game(int SCREEN_WIDTH, int SCREEN_HEIGHT);
    ~Game();
    void check_if_sesame_inside_screen();
    void handle_keyboard_input();
};