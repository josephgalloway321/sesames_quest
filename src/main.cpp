#include <iostream>
#include <raylib.h>
#include "../header/game.hpp"
#include "../header/mobile_objects.hpp"

const int SCREEN_WIDTH = 1820, SCREEN_HEIGHT = 1024;

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Sesame's Quest");
  SetTargetFPS(4);

  // Create game objects
  Game game(SCREEN_WIDTH, SCREEN_HEIGHT);
  enum GameScreen {title, cut_scene, gameplay, duck_closeup, ending_success, ending_failure};
  GameScreen current_screen = title;

  while(!WindowShouldClose()) {
    /*
    * DRAW
    */
    switch(current_screen) {
      case title: {
        BeginDrawing();
        ClearBackground(PINK);
        EndDrawing();
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
        game.draw_apartment();
        game.draw_hidden_objects();
        game.draw_mobile_objects();
        game.draw_game_information();

        game.handle_keyboard_input();
        game.handle_mouse_input();

        game.check_all_boundaries();
        game.check_all_interactions();

        game.countdown_timer();

        if(game.check_game_over() && game.check_is_successful()) {
          current_screen = ending_success;
        }
        else if(game.check_game_over()) {
          current_screen = ending_failure;
        }

        // ONLY FOR TESTING
        // Track position of mouse to get coordinates on screen
        int test_x = (int)GetMousePosition().x;
        int test_y = (int)GetMousePosition().y;
        DrawText(TextFormat("x: %d,\n\ny: %d", test_x, test_y), 25, 10, 25, WHITE);
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