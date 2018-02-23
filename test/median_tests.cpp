#include <gtest/gtest.h>

#include "median_alg.hpp"

TEST(median_tests, alg_test)
{
	std::string input = "3 5 m 8 m 6 m q";

	float result[100] = {};
	unsigned int result_size = median(input, result);

	EXPECT_EQ(3, result_size);
	EXPECT_FLOAT_EQ(4.0, result[0]);
	EXPECT_FLOAT_EQ(5.0, result[1]);
	EXPECT_FLOAT_EQ(5.5, result[2]);
}

TEST(median_tests, one_break)
{
	std::string input = "5 1 6 3 2 8 -10 -11 m q";

	float result[100] = {};
	unsigned int result_size = median(input, result);

	EXPECT_EQ(1, result_size);
	EXPECT_FLOAT_EQ(2.0, result[0]);
}

TEST(median_tests, many_breaks)
{
	std::string input = "-10 m 0 m 8 m 1 m 2 m q";

	float result[100] = {};
	unsigned int result_size = median(input, result);

	EXPECT_EQ(5, result_size);
	EXPECT_FLOAT_EQ(-10.0, result[0]);
	EXPECT_FLOAT_EQ(-5.0, result[1]);
	EXPECT_FLOAT_EQ(0.0, result[2]);
	EXPECT_FLOAT_EQ(0.5, result[3]);
	EXPECT_FLOAT_EQ(1.0, result[4]);
}

TEST(median_tests, empty_input)
{
	std::string input = "m q";

	float result[100] = {};
	unsigned int result_size = median(input, result);

	EXPECT_EQ(0, result_size);
}
