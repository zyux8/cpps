#pragma once

# include <fstream>
// # include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string _name;
		bool _signed;
		const int _gradeSign;
		const int _gradeExec;
	public:
		AForm();
		AForm(const std::string name, const int gradeSign, const int gradeExec);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();
		std::string getName() const;
		bool getSigned() const;
		int getGradeSign() const;
		int getGradeExec() const;
		void beSigned(const Bureaucrat& bureau);
		virtual void execute(Bureaucrat const &executer) const = 0;
		class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
		class AFormAlreadySigned : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class UnsignedFormException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream &operator <<(std::ostream &os, const AForm &i);