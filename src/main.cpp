#include <iostream>
#include <raylib.h>
#include "../header/timer.hpp"
#include "../header/sesame.hpp"

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
  SetTargetFPS(4);  // Game is set at 4 frames per second
  enum GameScreen {title, cut_scene, gameplay, ending_success, ending_failure};
  GameScreen current_screen = gameplay;

  // Create game objects
  Sesame sesame;

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
        
        sesame.iterate_sesame_walking_current_frame();

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
    
        // Draw Sesame walking
        DrawTextureRec(
          sesame.sesame_walking,
          Rectangle{
            sesame.get_sesame_walking_frame_width() * sesame.get_sesame_walking_current_frame(),
            0,
            sesame.get_sesame_walking_frame_width(),
            sesame.get_sesame_walking_frame_height()},
          Vector2{  // {x, y} position
            sesame.get_sesame_walking_position_x(),
            sesame.get_sesame_walking_position_y()},  
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