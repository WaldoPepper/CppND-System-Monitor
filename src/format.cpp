#include <string>

#include "format.h"

using std::string;
using std::to_string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function

string Format::AppendZero(long number) {
  if (number < 10)
    return "0" + to_string(number);
  else
    return to_string(number);
}

string Format::ElapsedTime(long seconds) {
  const int seconds_in_minutes = 60;
  const int seconds_in_hours = 3600;

  long hours = seconds / seconds_in_hours;
  int minutes = (seconds % seconds_in_hours) / seconds_in_minutes;
  int remaining_seconds = seconds % seconds_in_minutes;

  string output = AppendZero(hours) + ":" + AppendZero(minutes) + ":" +
                  AppendZero(remaining_seconds);

  return output;
}