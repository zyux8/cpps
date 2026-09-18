#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
	std::cout << "=== ClapTrap feature tests ===" << std::endl;
	ClapTrap robot("CT-01");

	robot.attack("Target A");
	robot.takeDamage(3);
	robot.beRepaired(5);

	robot.takeDamage(8);

	std::cout << std::endl;

	ClapTrap helper("CT-02");
	for (int i = 0; i < 11; ++i) {
		helper.attack("Dummy");
	}
	helper.beRepaired(2);



	std::cout << std::endl << std::endl;
	std::cout << "=== ScavTrap feature tests ===" << std::endl;

	ScavTrap scav("ST-01");
	scav.attack("Enemy1");
	scav.takeDamage(20);
	scav.beRepaired(15);
	scav.guardGate();

	std::cout << std::endl;

	ScavTrap gatekeeper("Gatekeeper");
	for (int i = 0; i < 5; ++i) {
		gatekeeper.attack("Intruder");
	}
	gatekeeper.guardGate();



	std::cout << std::endl << std::endl;
	std::cout << "=== FragTrap feature tests ===" << std::endl;

	FragTrap frag("FT-01");
	frag.attack("Enemy2");
	frag.takeDamage(12);
	frag.beRepaired(8);
	frag.highFivesGuys();

	std::cout << std::endl;

	FragTrap party("PartyBot");
	party.highFivesGuys();
	party.attack("Target B");


	std::cout << std::endl << std::endl;
	std::cout << "=== DiamondTrap feature tests ===" << std::endl;

	DiamondTrap diamond("DT-01");
	diamond.attack("Enemy3");
	diamond.takeDamage(15);
	diamond.beRepaired(10);
	diamond.whoAmI();
	diamond.highFivesGuys();

	std::cout << std::endl;

	DiamondTrap hybrid("HybridBot");
	hybrid.whoAmI();
	hybrid.attack("Target C");
	hybrid.guardGate();
	hybrid.highFivesGuys();

	std::cout << std::endl << std::endl;
	std::cout << "=== Testing default DiamondTrap ===" << std::endl;
	DiamondTrap defaultDiamond;
	defaultDiamond.whoAmI();
	defaultDiamond.attack("Dummy");


	std::cout << std::endl << std::endl;
	//Destructors
	return 0;
}