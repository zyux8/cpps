#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    Intern someRandomIntern;
    AForm* rrf = NULL;

    try {
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    if (rrf) {
        delete rrf;
    }

    Bureaucrat boss("Boss", 1);
    Bureaucrat clerk("Clerk", 150);
    Bureaucrat gardener("Gardener", 137);
    Bureaucrat robotExec("RobotExec", 45);
    Bureaucrat president("President", 5);

    std::string shrubTarget = "garden";
    std::string robotTarget = "Bender";
    std::string pardonTarget = "Zoidberg";

    ShrubberyCreationForm shrub(shrubTarget);
    RobotomyRequestForm robot(robotTarget);
    PresidentialPardonForm pardon(pardonTarget);

    std::cout << "=== Unsigned forms cannot execute ===" << std::endl;
    clerk.executeForm(shrub);
    clerk.executeForm(robot);
    clerk.executeForm(pardon);

    std::cout << "\n=== Sign valid forms ===" << std::endl;
    shrub.beSigned(boss);
    robot.beSigned(boss);
    pardon.beSigned(boss);

    std::cout << shrub << std::endl;
    std::cout << robot << std::endl;
    std::cout << pardon << std::endl;

    std::cout << "\n=== Valid execution ===" << std::endl;
    gardener.executeForm(shrub);
    robotExec.executeForm(robot);
    president.executeForm(pardon);

    std::cout << "\n=== Invalid execution attempts ===" << std::endl;
    clerk.executeForm(shrub);
    clerk.executeForm(robot);
    clerk.executeForm(pardon);

    return 0;
}
