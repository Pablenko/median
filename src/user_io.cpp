#include <iomanip>
#include <sstream>

#include "user_io.hpp"

bool validate(const std::string& input)
{
    const char break_marker = 'm', quit_marker = 'q';

    if((input.find(break_marker) == std::string::npos) or (input.find(quit_marker) == std::string::npos))
    {
        return false;
    }
    return true;
}

std::string result_to_str(const float* medians, const unsigned int size)
{
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(2);

    for(unsigned int i=0; i<size; i++)
    {
        ss << medians[i] << " ";
    }

    std::string result = ss.str();
    result.pop_back();
    return result;
}
