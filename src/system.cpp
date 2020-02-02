#include <unistd.h>
#include <cstddef>
#include <set>
#include <string>
#include <vector>

#include "linux_parser.h"
#include "process.h"
#include "processor.h"
#include "system.h"

using LinuxParser::MemoryType;
using std::set;
using std::size_t;
using std::string;
using std::vector;

// TODO: Return the system's CPU
Processor& System::Cpu() { return cpu_; }

// TODO: Return a container composed of the system's processes
vector<Process>& System::Processes() {
  vector<int> processes_pids = LinuxParser::Pids();
  // TODO: Can I not clear and recreate all the Process everytime this function
  // is called?
  processes_.clear();
  for (size_t i = 0; i < processes_pids.size(); ++i) {
    Process* new_process =
        new Process(processes_pids.at(i), cpu_.getTotalJiffies());
    processes_.push_back(*new_process);
    delete(new_process);
  }
  std::sort(processes_.begin(), processes_.end());
  return processes_;
}

// #DONE TODO: Return the system's kernel identifier (string)
std::string System::Kernel() { return LinuxParser::Kernel(); }

// #DONE TODO: Return the system's memory utilization
float System::MemoryUtilization() { return LinuxParser::MemoryUtilization(); }

// #DONE TODO: Return the operating system name
std::string System::OperatingSystem() { return LinuxParser::OperatingSystem(); }

// TODO: Return the number of processes actively running on the system
int System::RunningProcesses() { return LinuxParser::RunningProcesses(); }

// TODO: Return the total number of processes on the system
int System::TotalProcesses() { return LinuxParser::TotalProcesses(); }

// TODO: Return the number of seconds since the system started running
long int System::UpTime() { return LinuxParser::UpTime(); }