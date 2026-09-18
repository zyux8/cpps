#include <iostream>

template <typename T>
Array<T>::Array() {
	_data = new T[0];
	_size = 0;
	std::cout << "Default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) {
	_data = new T[n];
	_size = n;
	std::cout << "Modified constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array& other) {
	_data = new T[other._size];
	for (unsigned int x = 0; x < other._size; x++)
		_data[x] = other._data[x];
	_size = other._size;
	std::cout << "Copy constructor called" << std::endl;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (this != &other) {
		// _data = other._data;
		_data = new T[other._size];
		for (unsigned int x = 0; x < other._size; x++)
			_data[x] = other._data[x];
		_size = other._size;
		// *this = other;
	}
	std::cout << "Copy assignment operator called" << std::endl;
}

template <typename T>
Array<T>::~Array() {
	delete[] _data;
	std::cout << "Destructor called" << std::endl;
}

template <typename T>
T& Array<T>::operator[](unsigned int i) {
	if (i >= _size) {
		throw std::exception();
	}
	return _data[i];
}

template <typename T>
unsigned int Array<T>::size() const {
	return _size;
}
