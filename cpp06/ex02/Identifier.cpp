#include "Identifier.hpp"

Base* Identifier::generate(void) {
	int random = rand() % 3;
	if (random == 0) {
		std::cout << "A class was created" << std::endl;
		return new A();
	}
	if (random == 1) {
		std::cout << "B class was created" << std::endl;
		return new B();
	}
	std::cout << "C class was created" << std::endl;
	return new C();
}

void Identifier::identify(Base* p) {
	if (dynamic_cast<A*>(p) != NULL) {
		std::cout << "Idetified class is A" << std::endl;
	} else if (dynamic_cast<B*>(p) != NULL) {
		std::cout << "Idetified class is B" << std::endl;
	} else if (dynamic_cast<C*>(p) != NULL) {
		std::cout << "Idetified class is C" << std::endl;
	} else {
		std::cout << "Idetified class is something else" << std::endl;
	}
}

void Identifier::identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Idetified class is A" << std::endl;
		return;
	} catch (std::exception& e) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "Idetified class is B" << std::endl;
		return;
	} catch (std::exception& e) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "Idetified class is C" << std::endl;
		return;
	} catch (std::exception& e) {}
	std::cout << "Idetified class is something else" << std::endl;
}
