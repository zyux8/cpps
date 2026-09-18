#include "Bureaucrat.hpp"

int main() {
    Bureaucrat* Brr1 = NULL;
    Bureaucrat* Brr2 = NULL;
    Bureaucrat* Brr3 = NULL;
    try {

        Brr1 = new Bureaucrat("bob", 4);
        std::cout << *Brr1 << std::endl;

        Brr2 = new Bureaucrat("beb", 80);
        std::cout << *Brr2 << std::endl;
        Brr2->decGrade();
        std::cout << *Brr2 << std::endl;

		// Brr3 = new Bureaucrat("bab", 200);
		// std::cout << *Brr3 << std::endl;

        Brr1->incGrade();
        std::cout << *Brr1 << std::endl;
		Brr1->incGrade();
        std::cout << *Brr1 << std::endl;
		Brr1->incGrade();
        std::cout << *Brr1 << std::endl;
		// Brr1->incGrade();
        // std::cout << *Brr1 << std::endl;
		// Brr1->incGrade();
        // std::cout << *Brr1 << std::endl;
		// Brr1->incGrade();
        // std::cout << *Brr1 << std::endl;

    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    delete Brr1;
    delete Brr2;
	delete Brr3;

    return 0;
}
