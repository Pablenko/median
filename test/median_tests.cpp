#include <gtest/gtest.h>

#include "median_alg.hpp"

TEST(median_tests, alg_works_properly)
{
    std::string input = "3 5 m 8 m 6 m q";

    EXPECT_EQ(std::string("4.0 5.0 6.0"), median(input));
}
