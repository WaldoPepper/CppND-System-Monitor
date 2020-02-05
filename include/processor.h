#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <vector>

using std::vector;

class Processor {
 public:
  Processor();
  float Utilization();
  long getTotalJiffies();

 private:
  void CalculateDeltaTime(vector<int>&, vector<int>&);
  virtual void GetLinuxParsesForJiffies(vector<int>&);
  float CalculateUtilization();
  
  // cpu_jiffies vectors are organised with [0] = ActiveJiffies [1] =
  // NonIdleJiffies [2] = TotalJiffies
  vector<int> current_cpu_jiffies_;
  vector<int> prev_cpu_jiffies_;
  vector<float> delta_jiffies_;
};

#endif