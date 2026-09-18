#include "ScalarConverter.hpp"

int main(int ac, char **av) {
	if (ac == 1) {
		std::string input;
		while (1) {
			std::cout << "Enter number to convert or 'exit' to stop" << std::endl;
			if (!std::getline(std::cin, input))
				return 1;
			if (input == "exit")
				return 0;
			else{
				ScalarConverter::convert(input.c_str());
				std::cout << std::endl << std::endl;
			}
		}
	}
	else if (ac == 2) {
		ScalarConverter::convert(av[1]);
		return 0;
	}
	std::cerr << "Incorrect amount of args" << std::endl;
	return 1;

	return 0;
}