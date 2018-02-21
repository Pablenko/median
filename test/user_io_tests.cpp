#include <gtest/gtest.h>

#include "user_io.hpp"

TEST(user_io_tests, validate_input)
{
	EXPECT_TRUE(validate("1 m q"));
	EXPECT_FALSE(validate("1 m"));
	EXPECT_FALSE(validate("1 m 2 m"));
}

TEST(user_io_tests, parse_user_input)
{
	std::string input = "1 m 2 m 3 4 m q";

	std::vector<int> expected_values = {1, 2, 3, 4};
	std::vector<int> expected_break = {1, 2, 4};

	EXPECT_EQ(std::make_pair(expected_values, expected_break), parse_input(input));
}

TEST(user_io_tests, result_to_str_with_precision)
{
	EXPECT_EQ("1.00 2.43 3.20 4.55", result_to_str({1.0, 2.43, 3.2, 4.554}));
}
