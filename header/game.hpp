#pragma once
#include <vector>
#include <cstdlib>
#include <ctime>
#include "../header/sesame.hpp"
#include "../header/timers.hpp"
#include "../header/apartment.hpp"
#include "../header/audio.hpp"
#include "../header/mobile_objects.hpp"

class Game {
  private:
    Apartment apartment;
    Sesame sesame;
    Timer timer_until_meow_or_groom;
    Timer timer_countdown;
    Audio audio;
    Vector2 mouse_position;
    Mobile_Objects cat_bed;
    Mobile_Objects fruit_bowl;
    Mobile_Objects laundry_basket;
    Mobile_Objects litter_box;
    Mobile_Objects meow_rug;
    Mobile_Objects sign;
    Mobile_Objects bathroom_rug;

    int SCREEN_WIDTH, SCREEN_HEIGHT;
    bool is_time_to_meow_or_groom;
    bool meow;
    bool groom;
    int seconds_until_meow_or_groom;
    int best_time;  // seconds
    int start_time; // seconds
    int time_remaining;  // seconds
    bool is_game_over;
    bool is_successful;
    
    void toggle_full_screen_window(int window_width, int window_height);
    void handle_meow_or_groom();
    void draw_sesame_coordinates(int game_information_width, int game_information_start_x);
    void draw_title(int game_information_width, int game_information_start_x);
    void draw_best_time(int game_information_width, int game_information_start_x);
    void draw_time_remaining(int game_information_width, int game_information_start_x);
    void draw_message(int game_information_width, int game_information_start_x);
    void update_best_time();

  public:
    Game(int SCREEN_WIDTH, int SCREEN_HEIGHT);
    ~Game();
    Font font;
    void check_if_sesame_inside_screen();  // Change to include object boundaries
    void handle_keyboard_input();
    void handle_mouse_input();
    void display_game_information();
    void display_apartment();
    void display_mobile_objects();
    void countdown_timer();
    bool check_game_over();
    bool check_is_successful() const;
    void reset_game();
};