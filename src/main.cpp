#include <iostream>

#include "linux_parser.h"
#include "ncurses_display.h"
#include "system.h"

int main() {
  System system;
  int processes_to_display = 30;
  NCursesDisplay::Display(system, processes_to_display);
}