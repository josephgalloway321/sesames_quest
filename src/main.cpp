#include <iostream>
#include <raylib.h>
#include "../header/game.hpp"

const int SCREEN_WIDTH = 1800, SCREEN_HEIGHT = 1012;

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Sesame's Quest");
  SetTargetFPS(4);

  // Create game objects
  Game game(SCREEN_WIDTH, SCREEN_HEIGHT);
  enum GameScreen {title, cut_scene, gameplay, ending_success, ending_failure};
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
        game.handle_keyboard_input();

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