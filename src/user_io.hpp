#ifndef USER_IO_HPP
#define USER_IO_HPP

#include <string>
#include <vector>

std::pair<std::vector<int>, std::vector<int>> parse_input(const std::string& input);

std::string result_to_str(const std::vector<float>& medians);

#endif
