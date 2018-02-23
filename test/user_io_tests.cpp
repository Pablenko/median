#include <gtest/gtest.h>

#include "user_io.hpp"

TEST(user_io_tests, validate_input)
{
	EXPECT_TRUE(validate("1 m q"));
	EXPECT_FALSE(validate("1 m"));
	EXPECT_FALSE(validate("1 m 2 m"));
}

TEST(user_io_tests, result_to_str_with_precision)
{
	float result[] = {1.0, 2.43, 3.2, 4.554};

	EXPECT_EQ("1.00 2.43 3.20 4.55", result_to_str(result, 4));
}
