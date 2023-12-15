#pragma once
#include "../header/sesame.hpp"

class Game {
  private:
    int screen_width;
    int screen_height;

  public:
    Game();
    ~Game();
    //Sesame sesame;
    int get_screen_width() const;
    int get_screen_height() const;
    void handle_keyboard_input();
};