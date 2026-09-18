#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
		int value;
		static const int fraction = 8;
	public:
		Fixed();
		Fixed(const Fixed& hans);
		~Fixed();
		Fixed &operator=(const Fixed name);
		void setRawBits( int const raw);
		int  getRawBits() const;
};

#endif