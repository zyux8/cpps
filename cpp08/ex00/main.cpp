#include "easyfind.hpp"
#include <vector>

int main()
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	std::vector<int>::iterator idx;

	std::cout << "Added values 1-5" << std::endl;

	std::cout << "Searching for '4'" << std::endl;
	idx = ::easyfind(vec, 4);
	std::cout << std::endl;

	std::cout << "Searching for '10'" << std::endl;
	idx = ::easyfind(vec, 10);
	std::cout << std::endl;

	std::cout << "Adding 10 and searching again for '10'" << std::endl;
	vec.push_back(10);
	idx = ::easyfind(vec, 10);
}