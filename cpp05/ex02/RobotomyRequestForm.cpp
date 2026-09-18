#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") {
}

RobotomyRequestForm::RobotomyRequestForm(std::string& target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target) {
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

std::string RobotomyRequestForm::getTarget() const {
	return this->_target;
}

void RobotomyRequestForm::robotomize() const {
	for (int x = 0; x < 3; x++)
		std::cout << "Drilling noises!!" << std::endl;

	int random = std::rand() % 2;
	if (random == 0)
		std::cout << this->getTarget() << " has been successfully robotomized!" << std::endl;
	else
		std::cout << this->getTarget() << " has survived robotomization! (Failure)" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executer) const {
	if (!this->getSigned())
		throw AForm::UnsignedFormException();
	else if (executer.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException();
	else
		this->robotomize();
}
