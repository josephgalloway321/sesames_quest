#include <raylib.h>
#include "../header/timer.hpp"

Timer::Timer() {
  begin_timer = GetTime();  // Get time at the beginning of the program
}

double Timer::elapsed() {
  double elapsed = GetTime() - begin_timer;
  return elapsed;
}

// After elapsed time has passed given interval, reset the timer
void Timer::reset_timer() {
  begin_timer = GetTime();
}