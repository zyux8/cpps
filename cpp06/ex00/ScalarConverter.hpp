#pragma once

# include <iostream>
# include <string>
# include <cstdlib>
# include <limits>
# include <cmath>
# include <cctype>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();
		static void printChar(double nbr);
		static void printInt(double nbr);
		static void printFloat(double nbr);
		static void printDouble(double nbr);
		static void printError();
		static void findError(const std::string& literal);
	public:
		static void convert(const std::string& literal);
};
