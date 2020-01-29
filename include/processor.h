#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <vector>

using std::vector;

// TODO (KK): use instantenous CPU utulization
// Utilization = no of time instant that CPU is working / total time

class CpuTime {
 public:
  CpuTime(vector<int> cpu_data) : user_(cpu_data.at(0)) {}

 private:
  int user_;
  int nice_;
  int system_;
};

class Processor {
 public:
  float Utilization();  // TODO: See src/processor.cpp

  // TODO: Declare any necessary private members
 private:
  int user_current_;
  int nice_current_;
  int system_current_;
  int raw_idle_;
  int raw_iowait_;
  int raw_irq_;
  int raw_soft_irq_;
  int raw_steal_;
  int raw_guest_;
  int raw_nice_;
  int total_time_current_;
  int total_time_prev;
  int
};

#endif