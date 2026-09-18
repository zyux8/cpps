#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	private:
		int value;
		static const int fraction = 8;
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& fixed);
		~Fixed();
		Fixed &operator=(const Fixed fixed);
		float toFloat(void) const;
		int toInt(void) const;
		void setRawBits(int const raw);
		int  getRawBits() const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
