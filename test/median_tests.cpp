#include <gtest/gtest.h>

#include "median_alg.hpp"

TEST(median_tests, median_alg_tests)
{
	std::vector<int> input_values = {3, 5, 8, 6};
	std::vector<int> input_breaks = {2, 3, 4};

	std::vector<float> expected_result = {4.0, 5.0, 5.5};

	EXPECT_EQ(expected_result, median(input_values, input_breaks));
}

TEST(median_tests, empty_input)
{
	EXPECT_EQ(0, median({}, {}).size());
}

TEST(median_tests, one_element)
{
	std::vector<int> input_values = {1};
	std::vector<int> input_breaks = {1};

	std::vector<float> expected_result = {1.0};

	EXPECT_EQ(expected_result, median(input_values, input_breaks));
}

TEST(median_tests, one_break)
{
	std::vector<int> input_values = {5, 1, 6, 3, 2, 8, -10, -11};
	std::vector<int> input_breaks = {8};

	std::vector<float> expected_result = {2.5};

	EXPECT_EQ(expected_result, median(input_values, input_breaks));
}
