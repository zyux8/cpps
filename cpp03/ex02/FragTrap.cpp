#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap() {
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name) {
	std::cout << "FragTrap constructer called" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << this->Name << " requests a high five!" << std::endl;
}


