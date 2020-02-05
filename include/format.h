#ifndef FORMAT_H
#define FORMAT_H

#include <string>

namespace Format {
std::string ElapsedTime(const long seconds);  // TODO: See src/format.cpp
std::string AppendZero(const long number);
};  // namespace Format

#endif