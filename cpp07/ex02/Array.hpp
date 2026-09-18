#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array {
	private:
	    T*              _data;
	    unsigned int    _size;
	public:
	    Array();
	    Array(unsigned int n);
	    Array(const Array& other);
	    Array& operator=(const Array& other);
	    ~Array();
	    T&              operator[](unsigned int i);
	    unsigned int    size() const;
};

# include "Array.tpp"
# include <cmath>

#endif