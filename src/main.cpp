#include <iostream>
#include <raylib.h>
#include "../header/game.hpp"

const int SCREEN_WIDTH = 1820, SCREEN_HEIGHT = 1024;

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Sesame's Quest");
  SetTargetFPS(4);

  // Create game objects
  Game game(SCREEN_WIDTH, SCREEN_HEIGHT);
  enum GameScreen {title, cut_scene, gameplay, duck_closeup, ending_success, ending_failure};
  GameScreen current_screen = gameplay;

  while(!WindowShouldClose()) {
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
        ClearBackground(BLACK);
        EndDrawing();
      } break;

      case ending_success: {
        BeginDrawing();
        ClearBackground(PINK);
        EndDrawing();
      } break;

      case ending_failure: {
        BeginDrawing();
        ClearBackground(BLUE);
        EndDrawing();
      } break;

      default:
        break;
    }
    
    /*
    * UPDATE
    */
    switch(current_screen) {
      case title: {

      } break;

      case cut_scene: {
        
      } break;

      case gameplay: {
        // The order matters; first is lowest layer & last is highest layer
        game.show_apartment();
        game.display_game_information();
        game.handle_keyboard_input();
        game.handle_mouse_input();
        game.check_if_sesame_inside_screen();

        game.countdown_timer();
        if(game.check_game_over() && game.check_is_successful()) {
          current_screen = ending_success;
        }
        else if(game.check_game_over()) {
          current_screen = ending_failure;
        }
      } break;

      case ending_success: {
        game.reset_game();
      } break;

      case ending_failure: {
        game.reset_game();
      } break;

      default:
        break;
    }
  }
}