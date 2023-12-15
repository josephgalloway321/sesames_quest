#include <iostream>
#include <raylib.h>
#include "../header/timers.hpp"  // Erase after moving control to game
#include "../header/sesame.hpp"  // Erase after moving control to game
#include "../header/game.hpp"

void toggle_full_screen_window(int window_width, int window_height) {
  if(!IsWindowFullscreen()) {
    int monitor = GetCurrentMonitor();
    SetWindowSize(GetMonitorWidth(monitor), GetMonitorHeight(monitor));
    ToggleFullscreen();
  }
  else {
    ToggleFullscreen();
    SetWindowSize(window_width, window_height);
  }
}

int main() {
  Game game;
  InitWindow(game.get_screen_width(), game.get_screen_height(), "Sesame's Quest");
  SetTargetFPS(4);
  enum GameScreen {title, cut_scene, gameplay, ending_success, ending_failure};

  // Create game objects
  
  Sesame sesame;
  GameScreen current_screen = gameplay;

  while(!WindowShouldClose()) {
    /*
    * UPDATE
    */
    switch(current_screen) {
      case title: {

      } break;
      case cut_scene: {
        
      } break;
      case gameplay: {
        if(IsKeyPressed(KEY_SPACE)) {
          toggle_full_screen_window(game.get_screen_width(), game.get_screen_height());
        }

      } break;
      case ending_success: {
        
      } break;
      case ending_failure: {
        
      } break;
      default:
        break;
    }

    /*
    * DRAW
    */
    switch(current_screen) {
      case title: {

      } break;
      case cut_scene: {
        
      } break;
      case gameplay: {
        BeginDrawing();
        ClearBackground(WHITE);

        sesame.sitting();
    
        EndDrawing();
        
      } break;
      case ending_success: {
        
      } break;
      case ending_failure: {
        
      } break;
      default:
        break;
    }
  }
}