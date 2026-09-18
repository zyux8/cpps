#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("NULL"), _signed(false), _gradeSign(150), _gradeExec(150) {
}

AForm::AForm(const std::string name, const int gradeSign, const int gradeExec) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec) {
	if (gradeSign < 1 || gradeExec < 1) {
        throw AForm::GradeTooHighException();
    } else if (gradeSign > 150 || gradeExec > 150) {
        throw AForm::GradeTooLowException();
    }
}

AForm::AForm(const AForm& other) : _name(other._name), _signed(other._signed), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec) {
}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		_signed = other._signed;
	}
	return *this;
}

AForm::~AForm() {
}

std::string AForm::getName() const {
	return this->_name;
}

bool AForm::getSigned() const {
	return this->_signed;
}

int AForm::getGradeSign() const {
	return this->_gradeSign;
}

int AForm::getGradeExec() const {
	return this->_gradeExec;
}

void AForm::beSigned(const Bureaucrat& bureau) {
	if (bureau.getGrade() > _gradeSign)
		throw AForm::GradeTooLowException();
	if (_signed == true)
		throw AForm::AFormAlreadySigned();
	_signed = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

const char* AForm::AFormAlreadySigned::what() const throw() {
	return "Form already signed";
}

const char* AForm::UnsignedFormException::what() const throw() {
	return "Form is not signed";
}

std::ostream &operator <<(std::ostream &os, const AForm &i) {
    os << i.getName() << ", form grade to sign " << i.getGradeSign() << ", grade to execute " << i.getGradeExec() << " and form is signed: " << i.getSigned() << ".";
    return os;
}

