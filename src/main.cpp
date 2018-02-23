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

    float* results = nullptr;

    unsigned int results_size = median(input, results);
    auto results_repr = result_to_str(results, results_size);

    std::cout << "\nResult: \n" << results_repr << "\n";

    delete[] results;
}