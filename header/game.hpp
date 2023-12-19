#pragma once
#include <vector>
#include <cstdlib>
#include <ctime>
#include "../header/sesame.hpp"
#include "../header/timers.hpp"

class Game {
  private:
    Sesame sesame;
    Timer timer_until_meow_or_groom;
    Timer timer_meow_duration;
    Timer timer_groom_duration;
    int SCREEN_WIDTH, SCREEN_HEIGHT;
    bool is_time_to_meow_or_groom;
    bool meow;
    bool groom;
    int seconds_until_meow_or_groom;
    int seconds_meow_duration;
    int seconds_groom_duration;
    void toggle_full_screen_window(int window_width, int window_height);
    void handle_meow_or_groom();

  public:
    Game(int SCREEN_WIDTH, int SCREEN_HEIGHT);
    ~Game();
    Font font;
    void check_if_sesame_inside_screen();
    void handle_keyboard_input();
    void display_sesame_coordinates();
};