#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "ClapTrap default constructor called" << std:: endl;
}

ClapTrap::ClapTrap(std::string name){
	this->Name = name;
	this->HitPoints = 10;
	this->EnergyPoints = 10;
	this->AttackDamage = 0;
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target){
	if (this->HitPoints <= 0)
		std::cout << "ClapTrap " << this->Name << " is dead..." << std::endl;
	if (this->EnergyPoints <= 0){
		std::cout << "ClapTrap " << this->Name << " is out of energy..." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->Name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
	this->EnergyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount){
	if (this->HitPoints <= 0) {
		std::cout << "ClapTrap " << this->Name << " is already dead";
		return ;
	}
	if (this->HitPoints - amount <= 0) {
		std::cout << "ClapTrap " << this->Name << " died..." << std::endl;
		return ;
	}
	else{
		this->HitPoints -= amount;
		std::cout << "ClapTrap " << this->Name << " took " << amount << " damage" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->EnergyPoints <= 0)
		std::cout << "ClapTrap " << this->Name << " is out of energy..." << std::endl;
	std::cout << "ClapTrap " << this->Name << " repaired itself by " << amount << " HitPoints!" << std::endl;
	this->HitPoints += amount;
	this->EnergyPoints--;
}
