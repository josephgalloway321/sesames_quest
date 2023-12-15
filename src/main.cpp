#include <iostream>
#include <raylib.h>
#include "../header/timers.hpp"
#include "../header/sesame.hpp"
#include "../header/game.hpp"

const int SCREEN_WIDTH = 1800, SCREEN_HEIGHT = 1012;

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
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Sesame's Quest");
  SetTargetFPS(4);
  enum GameScreen {title, cut_scene, gameplay, ending_success, ending_failure};

  // Create game objects
  Game game;
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
          toggle_full_screen_window(SCREEN_WIDTH, SCREEN_HEIGHT);
        }

        // Iterate the frame counters for each Sesame action
        sesame.iterate_sesame_frames();
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

        sesame.walk_down();
        
        // Draw Sesame grooming
        DrawTextureRec(
          sesame.sesame_grooming,
          Rectangle{
            sesame.get_sesame_grooming_frame_width() * sesame.get_sesame_grooming_current_frame(),
            0,
            sesame.get_sesame_grooming_frame_width(),
            sesame.get_sesame_grooming_frame_height()},
          Vector2{
            sesame.get_sesame_grooming_position_x(),
            sesame.get_sesame_grooming_position_y()},
          WHITE);
    
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