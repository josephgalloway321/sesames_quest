#include "../header/audio.hpp"

Audio::Audio() {
  volume_image = LoadImage("C:/Users/josep/Documents/GitHub/sesames_quest/resources/audio/volume.png");
  mute_image = LoadImage("C:/Users/josep/Documents/GitHub/sesames_quest/resources/audio/mute.png");
  volume_texture = LoadTextureFromImage(volume_image);
  mute_texture = LoadTextureFromImage(mute_image);
  UnloadImage(volume_image);
  UnloadImage(mute_image);

  audio_texture_position_top_left_x = 1650;
  audio_texture_position_top_left_y = 885;
  audio_button_bounds = {audio_texture_position_top_left_x, audio_texture_position_top_left_y, 50, 50};

  InitAudioDevice();
  is_mute = false;
}

Audio::~Audio() {
  UnloadTexture(volume_texture);
  UnloadTexture(mute_texture);
  CloseAudioDevice();
}

Rectangle Audio::get_audio_button_bounds() {
  return audio_button_bounds;
}

void Audio::toggle_is_mute() {
  is_mute = !is_mute;
}

bool Audio::get_is_mute() const {
  if(is_mute) {
    return true;
  }
  return false;
}

void Audio::draw_audio_light() {
  DrawRectangle(audio_texture_position_top_left_x, audio_texture_position_top_left_y, 50, 50, BLACK);
  DrawTexture(volume_texture, audio_texture_position_top_left_x, audio_texture_position_top_left_y, WHITE);
  //SetMusicVolume(music, 1);
  //SetSoundVolume(rotate_sound, 1);
  //SetSoundVolume(clear_sound, 1);
}

void Audio::draw_audio_dark() {
  DrawRectangle(audio_texture_position_top_left_x, audio_texture_position_top_left_y, 50, 50, BLACK);
  DrawTexture(volume_texture, audio_texture_position_top_left_x, audio_texture_position_top_left_y, LIGHTGRAY);
  //SetMusicVolume(music, 1);
  //SetSoundVolume(rotate_sound, 1);
  //SetSoundVolume(clear_sound, 1);
}

void Audio::draw_mute_light() {
  DrawRectangle(audio_texture_position_top_left_x, audio_texture_position_top_left_y, 50, 50, BLACK);
  DrawTexture(mute_texture, audio_texture_position_top_left_x, audio_texture_position_top_left_y, WHITE);
  //SetMusicVolume(music, 0);
  //SetSoundVolume(rotate_sound, 0);
  //SetSoundVolume(clear_sound, 0);
}

void Audio::draw_mute_dark() {
  DrawRectangle(audio_texture_position_top_left_x, audio_texture_position_top_left_y, 50, 50, BLACK);
  DrawTexture(mute_texture, audio_texture_position_top_left_x, audio_texture_position_top_left_y, LIGHTGRAY);
  //SetMusicVolume(music, 0);
  //SetSoundVolume(rotate_sound, 0);
  //SetSoundVolume(clear_sound, 0);
}
