#include "iter.hpp"
#include <iostream>

void up(int c) {
	c += 10;
	std::cout << c << std::endl;
}

int main() {
	int x[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	iter(x, 10, up);
	return 0;
}
