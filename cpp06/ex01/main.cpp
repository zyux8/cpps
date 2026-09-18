#include <iostream>
#include "Data.hpp"
#include "Serialization.hpp"

int main(void) {
	Data data(42);
	uintptr_t raw = Serializer::serialize(&data);
	Data* copy = Serializer::deserialize(raw);

	std::cout << "original address: " << &data << std::endl;
	std::cout << "serialized raw: " << raw << std::endl;
	std::cout << "restored address: " << copy << std::endl;
	std::cout << "value: " << copy->_num << std::endl;

	if (copy == &data)
		std::cout << "Round trip successful" << std::endl;
	else
		std::cout << "Round trip failed" << std::endl;
	return 0;
}
