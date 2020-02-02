#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <vector>

#include "linux_parser.h"

using std::vector;

// TODO (KK): use instantenous CPU utulization
// Utilization = no of time instant that CPU is working / total time

class Processor {
 public:
  Processor();
  float Utilization();  // TODO: See src/processor.cpp
  long getTotalJiffies();

  // TODO: Declare any necessary private members
 private:
  void CalculateCpuTime(vector<int>&, vector<int>&);
  void CalculateDeltaTime();
  vector<int> current_cpu_data_;
  vector<int> prev_cpu_data_;
  vector<int> current_cpu_time_;
  vector<int> prev_cpu_time_;
  vector<float> delta_time_;
  long total_jiffies_;
  long active_jiffies_;
  long idle_jiffies_;
};

#endif