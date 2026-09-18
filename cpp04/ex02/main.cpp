#include "polymorphism.hpp"

int main() {
	// const Animal* meta = 0;
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << std::endl;

	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;

	dog->makeSound();
	cat->makeSound();
	// meta->makeSound();

	std::cout << std::endl;

	// delete meta;
	delete dog;
	delete cat;
	return 0;
}
