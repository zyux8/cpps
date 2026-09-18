#include "polymorphism.hpp"

int main() {
	int x = 20;
	const Animal* animals[x];

	for (int y = 0; y < x; y++) {
		if (y < (x / 2))
			animals[y] = new Dog();
		else
			animals[y] = new Cat();
	}

	std::cout << std::endl;

	for (int y = 0; y < x; y++) {
		std::cout << "Call: " << y + 1 << std::endl;
		animals[y]->makeSound();
	}

	std::cout << std::endl;

	for (int y = 0; y < x; y++) {
		delete animals[y];
	}

	std::cout << std::endl << "Everything deleted" << std::endl;

	return 0;
}
