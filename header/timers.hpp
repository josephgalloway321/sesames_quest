#pragma once

class Timer {
  private:
    double begin_timer;
    double time_until_event;
    double time_to_hold_event;
    double elapsed();
  public:
    Timer();
    bool is_time_for_event(double time_until_event);
    //bool is_time_for_event_and_hold(double time_until_event, double time_to_hold_event);
    void reset_timer();
};