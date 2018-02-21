#include <iostream>
#include <string>

#include "median_alg.hpp"
#include "user_io.hpp"

int main()
{
    std::string input;
    std::cout << "Welcome to median program! Please provide input: \n";

    std::getline(std::cin, input);

    if(not validate(input))
    {
    	std::cout << "Wrong input provided. Please remember about m and q markers!\n";
    	return 1;
    }

    auto parsed = parse_input(input);
    auto result = median(parsed.first, parsed.second);
    auto output = result_to_str(result);

    std::cout << "\nResult: \n" << output << "\n";
}