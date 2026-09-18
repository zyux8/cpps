#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap() {
	std::cout << "ScavTrap default constructer called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
	std::cout << "Scavtrap constructer called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->Name << " is now in guard mode" << std::endl;
}