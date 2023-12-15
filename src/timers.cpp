#include <raylib.h>
#include "../header/timers.hpp"

Timer::Timer() {
  begin_timer = GetTime();  // Gets time at the beginning of the program
}

double Timer::elapsed()  {
  double elapsed = GetTime() - begin_timer;
  return elapsed;
}

// After elapsed time has surpassed interval set in game, reset the timer
void Timer::reset_timer()  {
  begin_timer = GetTime();
}