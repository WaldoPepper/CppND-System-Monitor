#include <vector>

#include "linux_parser.h"
#include "processor.h"

using LinuxParser::CPUStates;
using LinuxParser::CPUTime;
using std::vector;

Processor::Processor() {
  prev_cpu_data_ = LinuxParser::CpuUtilization();
  CalculateCpuTime(prev_cpu_data_, prev_cpu_time_);
}

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
  current_cpu_data_ = LinuxParser::CpuUtilization();
  CalculateCpuTime(current_cpu_data_, current_cpu_time_);
  CalculateDeltaTime();

  float small_number_buffer = 0.0000000001;
  float utilization_ =
      delta_time_.at(CPUTime::kNonIdleTime_) /
      (delta_time_.at(CPUTime::kTotalTime_) + small_number_buffer);

  prev_cpu_data_ = current_cpu_data_;
  prev_cpu_time_ = current_cpu_time_;

  return utilization_;
}

void Processor::CalculateCpuTime(vector<int>& cpu_data, vector<int>& cpu_time) {
  int idle_time =
      cpu_data.at(CPUStates::kIdle_) + cpu_data.at(CPUStates::kIOwait_);
  int nonidle_time =
      cpu_data.at(CPUStates::kUser_) + cpu_data.at(CPUStates::kNice_) +
      cpu_data.at(CPUStates::kSystem_) + cpu_data.at(CPUStates::kIRQ_) +
      cpu_data.at(CPUStates::kSoftIRQ_) + cpu_data.at(CPUStates::kSteal_);
  int total_time = idle_time + nonidle_time;

  cpu_time.clear();
  cpu_time.push_back(idle_time);
  cpu_time.push_back(nonidle_time);
  cpu_time.push_back(total_time);
}

void Processor::CalculateDeltaTime() {
  delta_time_.clear();
  for (int i = 0; i < 3; ++i) {
    delta_time_.push_back(current_cpu_time_.at(i) - prev_cpu_time_.at(i));
  }
}