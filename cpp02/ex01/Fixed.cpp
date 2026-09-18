#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructer called" << std::endl;
	this->value = value * (1 << fraction);
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructer called" << std::endl;
	this->value = roundf(value * (1 << fraction));
}

Fixed::Fixed(const Fixed& fixed) {
	std::cout << "Copy constructer called" << std::endl;
	value = fixed.value;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed name) {
	if (this != &name)
		this->value = name.value;
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(this->value) / (1 << fraction);
}

int Fixed::toInt(void) const {
	return (this->value) / (1 << fraction);
}

int  Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return value;
}

void Fixed::setRawBits(int const raw) {
	this->value = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}
