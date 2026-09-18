#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::Fixed(const Fixed& hans) {
	std::cout << "Copy constructer called" << std::endl;
	value = hans.value;
}


int  Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return value;
}

Fixed& Fixed::operator=(const Fixed name) {
	if (this != &name)
		this->value = name.value;
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

void Fixed::setRawBits(int const raw) {
	this->value = raw;
}
