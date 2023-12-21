#pragma once
#include <raylib.h>

class Audio {
  private:
  Image volume_image;
  Image mute_image;
  Texture2D volume_texture;
  Texture2D mute_texture;
  Rectangle audio_button_bounds;
  bool is_mute;
  float audio_texture_position_top_left_x;
  float audio_texture_position_top_left_y;

  public:
    Audio();
    ~Audio();
    Rectangle get_audio_button_bounds();
    void toggle_is_mute();
    bool get_is_mute() const;
    void draw_audio_light();
    void draw_audio_dark();
    void draw_mute_light();
    void draw_mute_dark();
};