#include "ScavTrap.hpp"

int main() {
	ClapTrap robot("CT-01");

	robot.attack("Target A");
	robot.takeDamage(3);
	robot.beRepaired(5);

	robot.takeDamage(8);

	ClapTrap helper("CT-02");
	for (int i = 0; i < 11; ++i) {
		helper.attack("Dummy");
	}
	helper.beRepaired(2);

	std::cout << std::endl;
	std::cout << "=== ScavTrap feature tests ===" << std::endl;
	
	ScavTrap scav("ST-01");
	scav.attack("Enemy1");
	scav.takeDamage(20);
	scav.beRepaired(15);
	scav.guardGate();
	
	ScavTrap gatekeeper("Gatekeeper");
	for (int i = 0; i < 5; ++i) {
		gatekeeper.attack("Intruder");
	}
	gatekeeper.guardGate();

	return 0;
}

