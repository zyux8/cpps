#include "Form.hpp"

Form::Form() : _name("NULL"), _signed(false), _gradeSign(150), _gradeExec(150) {
}

Form::Form(const std::string name, const int gradeSign, const int gradeExec) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec) {
	if (gradeSign < 1 || gradeExec < 1) {
        throw Form::GradeTooHighException();
    } else if (gradeSign > 150 || gradeExec > 150) {
        throw Form::GradeTooLowException();
    }
}

Form::Form(const Form& other) : _name(other._name), _signed(other._signed), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec) {
}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		_signed = other._signed;
	}
	return *this;
}

Form::~Form() {
}

std::string Form::getName() const {
	return this->_name;
}

bool Form::getSigned() const {
	return this->_signed;
}

int Form::getGradeSign() const {
	return this->_gradeSign;
}

int Form::getGradeExec() const {
	return this->_gradeExec;
}

void Form::beSigned(const Bureaucrat& bureau) {
	if (bureau.getGrade() > _gradeSign)
		throw Form::GradeTooLowException();
	if (_signed == true)
		throw Form::FormAlreadySigned();
	_signed = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

const char* Form::FormAlreadySigned::what() const throw() {
	return "Form already signed";
}

std::ostream &operator <<(std::ostream &os, const Form &i) {
    os << i.getName() << ", form grade to sign " << i.getGradeSign() << ", grade to execute " << i.getGradeExec() << " and form is signed: " << i.getSigned() << ".";
    return os;
}

