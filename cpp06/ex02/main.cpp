#include "Identifier.hpp"
#include <ctime>

int main(void) {
	srand(static_cast<unsigned>(time(NULL)));
	for (int i = 0; i < 5; ++i) {
		Base* ptr = Identifier::generate();

		std::cout << "Run " << i + 1 << ":" << std::endl;
		std::cout << "Pointer identification:" << std::endl;
		Identifier::identify(ptr);
		std::cout << "Reference identification:" << std::endl;
		Identifier::identify(*ptr);
		std::cout << std::endl;

		delete ptr;
	}
	return 0;
}
