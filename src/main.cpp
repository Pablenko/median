#include <iostream>
#include <string>

int main()
{
    std::string input;
    std::cout << "Welcome to median alg program! Please provide input: \n";
    std::getline(std::cin, input);
    std::cout << "Result: " << input;
}