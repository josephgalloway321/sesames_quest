#pragma once

class Game {
  private:
    const int SCREEN_WIDTH = 1800;
    const int SCREEN_HEIGHT = 1012;

  public:
    Game();
    ~Game();
    int get_screen_width() const;
    int get_screen_height() const;
};