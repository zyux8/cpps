#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {
}

void ScalarConverter::printChar(double nbr) {
	std::cout << "Char: ";
	if (std::isnan(nbr) || std::isinf(nbr) || nbr < std::numeric_limits<char>::min() || nbr > std::numeric_limits<char>::max())
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(nbr)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(nbr) << "'" << std::endl;
}

void ScalarConverter::printInt(double nbr) {
	std::cout << "Int: ";
	if (std::isnan(nbr) || std::isinf(nbr) || nbr < std::numeric_limits<int>::min() || nbr > std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(nbr) << std::endl;
}

void ScalarConverter::printFloat(double nbr) {
    float f = static_cast<float>(nbr);
    std::cout << "Float: " << f;
    if (!std::isnan(f) && !std::isinf(f) && f == std::floor(f))
        std::cout << ".0";
    std::cout << "f" << std::endl;
}

void ScalarConverter::printDouble(double nbr) {
    std::cout << "Double: " << nbr;
    if (!std::isnan(nbr) && !std::isinf(nbr) && nbr == std::floor(nbr))
        std::cout << ".0";
    std::cout << std::endl;
}

void ScalarConverter::printError() {
	std::cout << "Char: impossible" << std::endl;
	std::cout << "Int: impossible" << std::endl;
	std::cout << "Float: impossible" << std::endl;
	std::cout << "Double: impossible" << std::endl;
}

void ScalarConverter::findError(const std::string& literal) {
	if (literal.empty()) {
		printError();
		throw std::runtime_error("");
	}
	if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) {
        char c = literal[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        throw std::runtime_error("");
    }

    char* pEnd = NULL;
    double d = std::strtod(literal.c_str(), &pEnd);

    std::string endStr(pEnd);
    if (endStr != "" && endStr != "f") {
        printError();
        throw std::runtime_error("");
    }

    if (d == 0.0 && literal[0] != '0' && literal[0] != '+' && literal[0] != '-') {
        printError();
        throw std::runtime_error("");
    }
}

void ScalarConverter::convert(const std::string& literal) {
	try {
        findError(literal);

        char* pEnd = NULL;
        double d = std::strtod(literal.c_str(), &pEnd);

        printChar(d);
        printInt(d);
        printFloat(d);
        printDouble(d);
    } catch (std::exception& e) {
        return;
    }
}
