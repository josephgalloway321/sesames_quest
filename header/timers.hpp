#pragma once

class Timer {
  private:
    double begin_timer;

  public:
    Timer();
    double elapsed();
    void reset_timer();
};