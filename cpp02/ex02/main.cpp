#include "Fixed.hpp"

int main( void ) {
	std::cout << "=== Testing Constructors ===" << std::endl;
	Fixed a; // Default constructor
	std::cout << "a: " << a << std::endl;

	Fixed b(10); // Int constructor
	std::cout << "b: " << b << std::endl;

	Fixed c(42.42f); // Float constructor
	std::cout << "c: " << c << std::endl;

	Fixed d(b); // Copy constructor
	std::cout << "d (copy of b): " << d << std::endl;

	std::cout << "\n=== Testing Assignment Operator ===" << std::endl;
	a = c;
	std::cout << "a after assignment from c: " << a << std::endl;

	std::cout << "\n=== Testing Comparison Operators ===" << std::endl;
	Fixed x(5.5f);
	Fixed y(3.3f);
	std::cout << "x: " << x << ", y: " << y << std::endl;
	std::cout << "x > y: " << (x > y) << std::endl;
	std::cout << "x < y: " << (x < y) << std::endl;
	std::cout << "x >= y: " << (x >= y) << std::endl;
	std::cout << "x <= y: " << (x <= y) << std::endl;
	std::cout << "x == y: " << (x == y) << std::endl;
	std::cout << "x != y: " << (x != y) << std::endl;

	std::cout << "\n=== Testing Arithmetic Operators ===" << std::endl;
	Fixed p(10.5f);
	Fixed q(2.5f);
	std::cout << "p: " << p << ", q: " << q << std::endl;
	std::cout << "p + q: " << (p + q) << std::endl;
	std::cout << "p - q: " << (p - q) << std::endl;
	std::cout << "p * q: " << (p * q) << std::endl;
	std::cout << "p / q: " << (p / q) << std::endl;

	std::cout << "\n=== Testing Increment/Decrement Operators ===" << std::endl;
	Fixed z(5.0f);
	std::cout << "z: " << z << std::endl;
	std::cout << "++z: " << ++z << std::endl;
	std::cout << "z after ++z: " << z << std::endl;
	std::cout << "z++: " << z++ << std::endl;
	std::cout << "z after z++: " << z << std::endl;
	std::cout << "--z: " << --z << std::endl;
	std::cout << "z after --z: " << z << std::endl;
	std::cout << "z--: " << z-- << std::endl;
	std::cout << "z after z--: " << z << std::endl;

	std::cout << "\n=== Testing Min/Max Functions ===" << std::endl;
	Fixed m1(15.5f);
	Fixed m2(20.2f);
	std::cout << "m1: " << m1 << ", m2: " << m2 << std::endl;
	std::cout << "min(m1, m2): " << Fixed::min(m1, m2) << std::endl;
	std::cout << "max(m1, m2): " << Fixed::max(m1, m2) << std::endl;

	const Fixed cm1(15.5f);
	const Fixed cm2(20.2f);
	std::cout << "const min(cm1, cm2): " << Fixed::min(cm1, cm2) << std::endl;
	std::cout << "const max(cm1, cm2): " << Fixed::max(cm1, cm2) << std::endl;

	std::cout << "\n=== Testing Conversion Functions ===" << std::endl;
	Fixed conv(42.42f);
	std::cout << "conv: " << conv << std::endl;
	std::cout << "toInt(): " << conv.toInt() << std::endl;
	std::cout << "toFloat(): " << conv.toFloat() << std::endl;

	std::cout << "\n=== Testing Raw Bits Functions ===" << std::endl;
	Fixed raw(10.5f);
	std::cout << "raw: " << raw << std::endl;
	std::cout << "getRawBits(): " << raw.getRawBits() << std::endl;
	raw.setRawBits(256); // This should be 1.0 in fixed point (256 / 256 = 1)
	std::cout << "after setRawBits(256): " << raw << std::endl;

	std::cout << "\n=== Testing Complex Expression ===" << std::endl;
	Fixed complex = (Fixed(5.05f) * Fixed(2)) + Fixed(1.5f);
	std::cout << "Complex expression result: " << complex << std::endl;

	return 0;
}
