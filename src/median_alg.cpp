#include <algorithm>

#include "median_alg.hpp"

static float sub_median(std::vector<int>& to_sort, unsigned int end)
{
	auto end_iter = to_sort.begin(); 
	std::advance(end_iter, end);

	unsigned int num_of_sorted = std::distance(to_sort.begin(), end_iter);

    std::sort(to_sort.begin(), end_iter);

    if(num_of_sorted % 2 == 0)
    {
        return static_cast<float>(to_sort[num_of_sorted / 2 - 1] + to_sort[num_of_sorted / 2]) / 2.0f;
    }
    else
    {
        return to_sort[num_of_sorted / 2];
    }
}

std::vector<float> median(const std::vector<int>& values, const std::vector<int>& breaks)
{
	std::vector<int> to_sort = values;
	std::vector<float> result = {};

	for(auto b : breaks)
	{
        result.push_back(sub_median(to_sort, b));
	}
	return result;
}
