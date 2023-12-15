#pragma once

class Game {
  private:
    int screen_width;
    int screen_height;

  public:
    Game();
    ~Game();
    int get_screen_width();
    int get_screen_height();
};