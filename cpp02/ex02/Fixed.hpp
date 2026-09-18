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
		Fixed &operator=(const Fixed name);
		bool operator>(const Fixed name);
		bool operator<(const Fixed name);
		bool operator>=(const Fixed name);
		bool operator<=(const Fixed name);
		bool operator==(const Fixed name);
		bool operator!=(const Fixed name);
		Fixed operator+(const Fixed name);
		Fixed operator-(const Fixed name);
		Fixed operator*(const Fixed name);
		Fixed operator/(const Fixed name);
		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);
		static Fixed &min(Fixed &nbr1, Fixed &nbr2);
		static const Fixed &min(const Fixed &nbr1, const Fixed &nbr2);
		static Fixed &max(Fixed &nbr1, Fixed &nbr2);
		static const Fixed &max(const Fixed &nbr1, const Fixed &nbr2);
		float toFloat(void) const;
		int toInt(void) const;
		void setRawBits(int const raw);
		int  getRawBits() const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
