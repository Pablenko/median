#include <iomanip>
#include <iterator>
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

std::pair<std::vector<int>, std::vector<int>> parse_input(const std::string& input)
{
    const char break_marker = 'm';
    const std::size_t last_break_pos = input.rfind(break_marker);

    std::vector<int> values;
    std::vector<int> break_positions;
    std::size_t current_pos = 0, break_pos = 0;

    do
    {
        break_pos = input.find(break_marker, current_pos);
        std::istringstream ss(input.substr(current_pos, break_pos));
        std::copy(std::istream_iterator<int>(ss), std::istream_iterator<int>(), std::back_inserter(values));
        break_positions.push_back(values.size());
        current_pos = break_pos + 1;
    }
    while(break_pos != last_break_pos);

    return std::make_pair(values, break_positions);
}

std::string result_to_str(const std::vector<float>& medians)
{
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(2);
    std::copy(medians.begin(), medians.end(), std::ostream_iterator<float>(ss, " "));
    std::string result = ss.str();
    result.pop_back();
    return result;
}
