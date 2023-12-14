#include <iostream>
#include <raylib.h>

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
  SetTargetFPS(60);
  enum GameScreen {title, cut_scene, gameplay, ending_success, ending_failure};
  GameScreen current_screen = gameplay;

  Texture2D sesame = LoadTexture("C:/Users/josep/Documents/GitHub/sesames_quest/resources/sprites/sesame/sesame_walking.png");
  Texture2D background = LoadTexture("C:/Users/josep/Documents/GitHub/sesames_quest/resources/sprites/test_background.png");

  float frame_width = (float)(sesame.width / 16);
  int max_frames = (int)(sesame.width / (int)frame_width);

  float timer = 0.0f;
  int frame = 0;

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
        timer += GetFrameTime();  // Time it takes to render a single frame
    
        if(timer >= 0.25) {
          timer = 0.0f;
          frame += 1;
        }
    
        frame = frame % max_frames;
    
        BeginDrawing();
        ClearBackground(PINK);
    
        // Draw the background
        DrawTexture(background, 0, 0, WHITE);
    
        DrawTextureRec(
                sesame,
                Rectangle{frame_width * frame, 0, frame_width, (float)sesame.height},
                Vector2{20, 20},
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