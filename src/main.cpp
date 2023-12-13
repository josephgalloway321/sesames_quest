#include <iostream>
#include <raylib.h>

const int SCREEN_WIDTH = 240, SCREEN_HEIGHT = 240;

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
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Test");
  SetTargetFPS(60);

  Texture2D sesame = LoadTexture("C:/Users/josep/Documents/GitHub/sesames_quest/resources/sprites/sesame_walking.png");

  float frame_width = (float)(sesame.width / 16);
  int max_frames = (int)(sesame.width / (int)frame_width);

  float timer = 0.0f;
  int frame = 0;

  while(!WindowShouldClose()) {
    if(IsKeyPressed(KEY_SPACE)) {
      toggle_full_screen_window(SCREEN_WIDTH, SCREEN_HEIGHT);
    }
    
    BeginDrawing();
    ClearBackground(PINK);

    timer += GetFrameTime();  // Time it takes to render a single frame
    
    if(timer >= 0.25) {
      timer = 0.0f;
      frame += 1;
    }

    frame = frame % max_frames;

    // Draw the entire Sesame png file
    //DrawTexture(sesame, 0, 0, WHITE);

    DrawTextureRec(
            sesame,
            Rectangle{frame_width * frame, 0, frame_width, (float)sesame.height},
            Vector2{20, 20},
            WHITE);

    EndDrawing();
  }
}