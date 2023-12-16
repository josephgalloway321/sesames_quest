#include <raylib.h>
#include "../header/timers.hpp"

Timer::Timer() {
  begin_timer = GetTime();  // Gets time at the beginning of the program
}

double Timer::elapsed()  {
  double elapsed = GetTime() - begin_timer;
  return elapsed;
}

bool Timer::is_time_for_event(double time_until_event) {
  if(elapsed() > time_until_event) {
    reset_timer();
    return true;
  }
  return false;
}

/*
bool Timer::is_time_for_event(double time_until_event) {
  if(elapsed() > time_until_event) {
    reset_timer();
    return true;
  }
  return false;
}
*/

// After elapsed time has surpassed interval set in game, reset the timer
void Timer::reset_timer()  {
  begin_timer = GetTime();
}