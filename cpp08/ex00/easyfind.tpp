#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &container, int n) {
	typename T::iterator search = std::find(container.begin(), container.end(), n);
	if (search != container.end())
		std::cout << "Value found" << std::endl;
	else
		std::cout << "Value not found" << std::endl;
	return search;
}