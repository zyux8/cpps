#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default") {
}

PresidentialPardonForm::PresidentialPardonForm(std::string& target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other._target) {
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

std::string PresidentialPardonForm::getTarget() const {
	return this->_target;
}

void PresidentialPardonForm::pardon() const {
	std::cout << this->_target << " has been pardoned by Zaphod Beedlebrox" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executer) const {
	if (!this->getSigned())
		throw AForm::UnsignedFormException();
	else if (executer.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException();
	else
		this->pardon();
}
