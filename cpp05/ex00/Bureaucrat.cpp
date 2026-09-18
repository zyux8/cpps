#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
	
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name){
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        _grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {

}

std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::setGrade(int grade) {
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    } else if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    this->_grade = grade;
}

void Bureaucrat::incGrade() {
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade--;
}

void Bureaucrat::decGrade() {
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

std::ostream &operator <<(std::ostream &os, const Bureaucrat &i) {
   	os << i.getName() << ", bureaucrat grade " << i.getGrade() << ".";
    return os;
}

