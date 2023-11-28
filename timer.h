#ifndef TIMER_H
#define TIMER_H

#include <string>

// Start or stop timer
void Timer(bool start);

// Reset timer
void ResetTimer();

// Returns the elapsed time as a string from the global timer
std::string GetTime();

#endif