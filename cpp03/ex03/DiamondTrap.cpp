#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("noname_clap_name"), FragTrap(), ScavTrap() {
	this->name = "noname";
	std::cout << "DiamondTrap default constructor calles" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name) {
	this->name = name;
	std::cout << "DiamondTrap name constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "I am both " << this->name << " and " << ClapTrap::name << std::endl;
}
