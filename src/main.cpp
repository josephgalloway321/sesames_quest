#include <iostream>
#include <raylib.h>
#include "../header/game.hpp"
#include "../header/apartment.hpp"

const int SCREEN_WIDTH = 1820, SCREEN_HEIGHT = 1024;

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Sesame's Quest");
  SetTargetFPS(4);

  // Create game objects
  Game game(SCREEN_WIDTH, SCREEN_HEIGHT);
  enum GameScreen {title, cut_scene, gameplay, duck_closeup, ending_success, ending_failure};
  GameScreen current_screen = gameplay;

  // TEST
  //Texture2D test;
  //test = LoadTexture("C:/Users/josep/Documents/GitHub/sesames_quest/resources/sprites/hidden_objects/cow.png");
  
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
        
      } break;
      case ending_failure: {
        
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
        //DrawTexture(test, 250, 300, WHITE);  // TEST
        game.display_sesame_coordinates();
        game.handle_keyboard_input();
        game.check_if_sesame_inside_screen();

        
        
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