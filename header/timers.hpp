#pragma once

class Timer {
  private:
    double begin_timer;
    double time_until_event;
    double elapsed();
  public:
    Timer();
    bool is_time_for_event(double time_until_event);
    void reset_timer();
};