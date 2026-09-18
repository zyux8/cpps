#include "Fixed.hpp"

Fixed::Fixed() {
	// std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::Fixed(const int value) {
	// std::cout << "Int constructer called" << std::endl;
	this->value = value * (1 << fraction);
}

Fixed::Fixed(const float value) {
	// std::cout << "Float constructer called" << std::endl;
	this->value = roundf(value * (1 << fraction));
}

Fixed::Fixed(const Fixed& fixed) {
	// std::cout << "Copy constructer called" << std::endl;
	value = fixed.value;
}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed name) {
	if (this != &name)
		this->value = name.value;
	// std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

bool Fixed::operator>(const Fixed name) {
	return this->value > name.value;
}

bool Fixed::operator<(const Fixed name) {
	return this->value < name.value;
}

bool Fixed::operator>=(const Fixed name) {
	return this->value >= name.value;
}

bool Fixed::operator<=(const Fixed name) {
	return this->value <= name.value;
}

bool Fixed::operator==(const Fixed name) {
	return this->value == name.value;
}

bool Fixed::operator!=(const Fixed name) {
	return this->value != name.value;
}

Fixed Fixed::operator+(const Fixed name) {
	Fixed temp(0);
	temp.value = this->value + name.value;
	return temp;
}

Fixed Fixed::operator-(const Fixed name) {
	Fixed temp(0);
	temp.value = this->value - name.value;
	return temp;
}

Fixed Fixed::operator*(const Fixed name) {
	Fixed temp(0);
	temp.value = this->value * name.value;
	return temp;
}

Fixed Fixed::operator/(const Fixed name) {
	Fixed temp(0);
	temp.value = this->value / name.value;
	return temp;
}

Fixed& Fixed::operator++() {
	this->value++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(this->value);
	this->value++;
	return temp;
}

Fixed& Fixed::operator--() {
	this->value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(this->value);
	this->value--;
	return temp;
}

Fixed& Fixed::min(Fixed &nbr1, Fixed &nbr2) {
	if (nbr1.value < nbr2.value)
		return nbr1;
	else
		return nbr2;
}

const Fixed& Fixed::min(const Fixed &nbr1, const Fixed &nbr2) {
	if (nbr1.value < nbr2.value)
		return nbr1;
	else
		return nbr2;
}

Fixed& Fixed::max(Fixed &nbr1, Fixed &nbr2) {
	if (nbr1.value > nbr2.value)
		return nbr1;
	else
		return nbr2;
}

const Fixed& Fixed::max(const Fixed &nbr1, const Fixed &nbr2) {
	if (nbr1.value > nbr2.value)
		return nbr1;
	else
		return nbr2;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(this->value) / (1 << fraction);
}

int Fixed::toInt(void) const {
	return (this->value) / (1 << fraction);
}

int  Fixed::getRawBits() const {
	// std::cout << "getRawBits member function called" << std::endl;
	return value;
}

void Fixed::setRawBits(int const raw) {
	this->value = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}
