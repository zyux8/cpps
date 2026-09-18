#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default") {	
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target) {
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

std::string ShrubberyCreationForm::getTarget() const {
	return this->_target;
}

void ShrubberyCreationForm::CreateAsciiTree() const {
	std::ofstream file((this->getTarget() + "_shrubbery").c_str());

	if (!file) {
		std::cerr << "File could not be opened!";
		return;
	}

	file << "       *       \n";
	file << "      ***      \n";
	file << "     *****     \n";
	file << "    *******    \n";
	file << "   *********   \n";
	file << "  ***********  \n";
	file << " ************* \n";
	file << "      |||      \n";
	file << "      |||      \n";

	file.close();
}

void ShrubberyCreationForm::execute(Bureaucrat const &executer) const {
	if (!this->getSigned())
		throw AForm::UnsignedFormException();
	else if (executer.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException();
	else
		this->CreateAsciiTree();
}
