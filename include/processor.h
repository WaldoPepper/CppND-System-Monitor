#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <vector>

using std::vector;

// TODO (KK): use instantenous CPU utulization
// Utilization = no of time instant that CPU is working / total time

class Processor {
 public:
  Processor();
  virtual ~Processor() {};
  virtual float Utilization();  // TODO: See src/processor.cpp
  long getTotalJiffies();

  // TODO: Declare any necessary private members
 protected:
  void CalculateDeltaTime(vector<int>&, vector<int>&);
  virtual void GetLinuxParsesForJiffies(vector<int>&);
  float CalculateUtilization();
  vector<int> current_cpu_jiffies_;
  vector<int> prev_cpu_jiffies_;
  vector<float> delta_time_;
};

#endif