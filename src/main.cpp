#include <iostream>
#include <raylib.h>

const int WIDTH = 240, HEIGHT = 240;

int main() {
  InitWindow(WIDTH, HEIGHT, "Test");
  SetTargetFPS(60);

  Texture2D sesame = LoadTexture("C:/Users/josep/Documents/GitHub/sesames_quest/resources/sprites/sesame_sitting.png");

  float frame_width = (float)(sesame.width / 6);
  int max_frames = (int)(sesame.width / (int)frame_width);

  float timer = 0.0f;
  int frame = 0;

  while(!WindowShouldClose()) {
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