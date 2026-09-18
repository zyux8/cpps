#include "ClapTrap.hpp"

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

	return 0;
}
