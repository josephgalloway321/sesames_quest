#pragma once
#include <iostream>
#include <raylib.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "../header/sesame.hpp"
#include "../header/timers.hpp"
#include "../header/apartment.hpp"
#include "../header/audio.hpp"
#include "../header/mobile_objects.hpp"
#include "../header/hidden_objects.hpp"
#include "../header/goals.hpp"

class Game {
  private:
    Apartment laundry_room_kitchen;
    Apartment living_room;
    Apartment bathroom;
    Apartment bedroom;
    Rectangle apartment_left_wall;
    Sesame sesame;
    Timer timer_until_meow_or_groom;
    Timer timer_countdown;
    Timer sesame_eating;
    Timer sesame_woken;
    Timer timer_end_cut_scene;
    Font font;
    Audio audio;
    Vector2 mouse_position;
    Mobile_Objects cat_bed;
    Mobile_Objects laundry_basket;
    Mobile_Objects litter_box;
    Mobile_Objects meow_rug;
    Mobile_Objects bathroom_rug;
    //Hidden_Objects blue_ball;
    //Hidden_Objects pink_ball;
    //Hidden_Objects green_ball;
    Hidden_Objects book;
    Hidden_Objects cow;
    Hidden_Objects duck_one;
    Hidden_Objects duck_two;
    //Hidden_Objects gray_mouse;
    //Hidden_Objects brown_mouse;
    //Hidden_Objects white_mouse;
    //Hidden_Objects papers;
    Hidden_Objects treat_box;
    Goals find_treats;
    Goals eat_treats;
    Goals hide_treat_box;
    Texture2D duck_date;
    Texture2D human;

    int SCREEN_WIDTH, SCREEN_HEIGHT;
    int game_information_start_x;
    int game_information_width;
    bool is_time_to_meow_or_groom;
    bool meow;
    bool groom;
    int seconds_until_meow_or_groom;
    char sesame_last_move;
    int best_time;  // seconds
    int start_time; // seconds
    int time_remaining;  // seconds
    bool is_successful;
    int num_hidden_objects;
    int returned_random_value;
    std::vector<int> vector_random_values;

    int treat_box_location;
    bool is_treat_box_revealed;
    bool is_sesame_near_treat_box;
    int seconds_until_finished_eating;
    bool is_done_eating_treats;
    bool is_hide_treats;

    bool end_cut_scene;
    bool sesame_woken_up;

    int get_random_value(std::vector<int> vector_random_values, int num_hidden_objects);
    std::vector<float> get_coordinates(int random_value);
    void toggle_full_screen_window(int window_width, int window_height);
    void handle_meow_or_groom();
    void draw_sesame_coordinates(int game_information_width, int game_information_start_x);
    void draw_title(int game_information_width, int game_information_start_x);
    void draw_best_time(int game_information_width, int game_information_start_x);
    void draw_time_remaining(int game_information_width, int game_information_start_x);
    void draw_message(int game_information_width, int game_information_start_x);
    void update_best_time();
    void initialize_apartment();
    void initialize_hidden_objects();
    void initialize_mobile_objects();
    void set_apartment_room_positions();
    void set_apartment_interaction_boundaries();
    void set_apartment_collision_boundaries();
    void set_hidden_objects_starting_positions();
    void set_treat_box_interation_boundary();
    void set_mobile_objects_starting_positions();
    void set_mobile_objects_interaction_boundaries();
    void set_mobile_objects_collision_boundaries();
    void set_goal_texts();
    void set_goal_positions();
    void interact_with_mobile_objects();
    void reverse_sesame_last_move();
    void interact_with_apartment();
    void find_treat_box_location();
    void set_is_game_over();

  public:
    Game(int SCREEN_WIDTH, int SCREEN_HEIGHT);
    ~Game();
    void cut_scene_start();
    void draw_cut_scene();
    void cut_scene_done();
    void check_all_boundaries();
    void check_all_interactions();
    void handle_keyboard_input();
    void handle_mouse_input();
    void draw_game_information();
    void draw_apartment();
    void draw_mobile_objects() const;
    void draw_hidden_objects() const;
    void draw_goals() const;
    Font get_font() const;
    void countdown_timer();
    bool check_game_over();
    bool check_is_successful() const;
    void reset_game();
    void reset_mobile_objects();
    void check_find_treats();
    void check_eat_treats();
    void check_hide_treats();
    void draw_wall_boundaries();
    bool get_end_cut_scene() const;
    void start_cut_scene_timers();
};