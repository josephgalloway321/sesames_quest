#include <iostream>
#include <raylib.h>
#include "../header/game.hpp"

const int SCREEN_WIDTH = 1820, SCREEN_HEIGHT = 1024;

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Sesame's Quest");
  SetTargetFPS(4);

  // Create game objects
  Game game(SCREEN_WIDTH, SCREEN_HEIGHT);
  enum GameScreen {title, cut_scene, gameplay, ending_success, ending_failure};
  GameScreen current_screen = title;

  while(!WindowShouldClose()) {
    /*
    * DRAW
    */
    switch(current_screen) {
      case title: {
        SetTargetFPS(60);
        BeginDrawing();
        ClearBackground(PINK);
        // Game title
        DrawText("Sesame's Quest", 450, 350, 64, WHITE);

        // Controls
        DrawText("- Use arrow keys for walking", 250, 550, 32, WHITE);
        DrawText("- Press F for full screen toggle", 250, 550 + 50, 32, WHITE);
        DrawText("- Press A to interact with something", 250, 550 + 50*2, 32, WHITE);
        DrawText("- Hold down E to eat the treats", 250, 550 + 50*3, 32, WHITE);
        DrawText("- Hold down S to sleep", 250, 550 + 50*4, 32, WHITE);
        DrawText("- Hold down D to show TV screen", 250, 550 + 50*5, 32, WHITE);

        // Goals
        DrawText("Accomplish all goals to win:", 1050, 550, 32, WHITE);
        DrawText("1) Find the treat box", 1050, 550 + 50, 32, WHITE);
        DrawText("2) Eat all the treats (3 seconds)", 1050, 550 + 50*2, 32, WHITE);
        DrawText("3) Hide the empty treat box", 1050, 550 + 50*3, 32, WHITE);

        // "Press enter to continue"
        DrawText("Press Space to Continue", 450, 900, 40, WHITE);
        EndDrawing();
      } break;
      
      case cut_scene: {
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
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
        if(IsKeyPressed(KEY_SPACE)) {
          current_screen = cut_scene;
          game.start_cut_scene_timers();
        }

        // ONLY FOR TESTING, Track position of mouse to get coordinates on screen
        int test_x = (int)GetMousePosition().x;
        int test_y = (int)GetMousePosition().y;
        DrawText(TextFormat("x: %d,\n\ny: %d", test_x, test_y), 25, 10, 25, WHITE);
      } break;

      case cut_scene: {
        SetTargetFPS(4);
        game.draw_mobile_objects();
        game.cut_scene_start();
        game.draw_apartment();
        game.draw_cut_scene();
        game.draw_mobile_objects();

        if(game.get_end_cut_scene()) {
          current_screen = gameplay;
          game.cut_scene_done();
        }

        // ONLY FOR TESTING, Track position of mouse to get coordinates on screen
        int test_x = (int)GetMousePosition().x;
        int test_y = (int)GetMousePosition().y;
        DrawText(TextFormat("x: %d,\n\ny: %d", test_x, test_y), 25, 10, 25, WHITE);
      } break;

      case gameplay: {
        // The order matters; first is lowest layer & last is highest layer
        game.draw_apartment();
        game.draw_hidden_objects();
        game.draw_mobile_objects();
        game.draw_game_information();
        game.draw_goals();
        //game.draw_wall_boundaries();  For debugging

        game.handle_keyboard_input();  // Sesame drawn here
        game.handle_mouse_input();

        game.check_all_boundaries();
        game.check_all_interactions();

        game.countdown_timer();

        game.check_find_treats();
        game.check_eat_treats();
        game.check_hide_treats();

        if(game.check_game_over() && game.check_is_successful()) {
          current_screen = ending_success;
        }
        else if(game.check_game_over()) {
          current_screen = ending_failure;
        }

        // ONLY FOR TESTING, Track position of mouse to get coordinates on screen
        int test_x = (int)GetMousePosition().x;
        int test_y = (int)GetMousePosition().y;
        DrawText(TextFormat("x: %d,\n\ny: %d", test_x, test_y), 25, 10, 25, WHITE);
      } break;

      case ending_success: {
        game.reset_game();

        // ONLY FOR TESTING, Track position of mouse to get coordinates on screen
        int test_x = (int)GetMousePosition().x;
        int test_y = (int)GetMousePosition().y;
        DrawText(TextFormat("x: %d,\n\ny: %d", test_x, test_y), 25, 10, 25, WHITE);
      } break;

      case ending_failure: {
        game.reset_game();

        // ONLY FOR TESTING, Track position of mouse to get coordinates on screen
        int test_x = (int)GetMousePosition().x;
        int test_y = (int)GetMousePosition().y;
        DrawText(TextFormat("x: %d,\n\ny: %d", test_x, test_y), 25, 10, 25, WHITE);
      } break;

      default:
        break;
    }
  }
}