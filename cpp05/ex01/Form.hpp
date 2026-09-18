#pragma once

# include "Bureaucrat.hpp"

class Form {
	private:
		const std::string _name;
		bool _signed;
		const int _gradeSign;
		const int _gradeExec;
	public:
		Form();
		Form(const std::string name, const int gradeSign, const int gradeExec);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();
		std::string getName() const;
		bool getSigned() const;
		int getGradeSign() const;
		int getGradeExec() const;
		void beSigned(const Bureaucrat& bureau);
		class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
		class FormAlreadySigned : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream &operator <<(std::ostream &os, const Form &i);