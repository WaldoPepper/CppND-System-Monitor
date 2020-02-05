#include "processor.h"
#include "linux_parser.h"

using LinuxParser::CPUTime;
using std::vector;

// Initialize prev_cpu_jiffies_ for the first time to prevent divide by zeros
Processor::Processor() { GetLinuxParsesForJiffies(prev_cpu_jiffies_); }

// Return the aggregate CPU utilization
float Processor::Utilization() {
  GetLinuxParsesForJiffies(current_cpu_jiffies_);
  CalculateDeltaTime(current_cpu_jiffies_, prev_cpu_jiffies_);
  const float utilization = CalculateUtilization();
  prev_cpu_jiffies_ = current_cpu_jiffies_;
  return utilization;
}

void Processor::CalculateDeltaTime(vector<int>& first_cpu_jiffies,
                                   vector<int>& second_cpu_jiffies) {
  delta_jiffies_.clear();
  for (int i = 0; i < 3; ++i) {
    delta_jiffies_.push_back(first_cpu_jiffies.at(i) - second_cpu_jiffies.at(i));
  }
}

void Processor::GetLinuxParsesForJiffies(vector<int>& cpu_jiffies) {
  cpu_jiffies.clear();
  cpu_jiffies.push_back(LinuxParser::IdleJiffies());
  cpu_jiffies.push_back(LinuxParser::ActiveJiffies());
  cpu_jiffies.push_back(LinuxParser::Jiffies());
}

float Processor::CalculateUtilization() {
  // small_number_buffer to prevent divide by zeros
  const float small_number_buffer = 0.0000000001;
  const float utilization =
      delta_jiffies_.at(CPUTime::kActiveTime_) /
      (delta_jiffies_.at(CPUTime::kTotalTime_) + small_number_buffer);
  return utilization;
}

long Processor::getTotalJiffies() {
  return current_cpu_jiffies_.at(CPUTime::kTotalTime_);
}