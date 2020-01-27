#include <iostream>

#include "linux_parser.h"
#include "ncurses_display.h"
#include "system.h"

int main() {
  System system;
  // float x = LinuxParser::MemoryUtilization();
  // std::cout << x << "\n";
  NCursesDisplay::Display(system);
}