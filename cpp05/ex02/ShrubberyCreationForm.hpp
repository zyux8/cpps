#pragma once

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;
		void CreateAsciiTree() const;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		virtual ~ShrubberyCreationForm();
		std::string getTarget() const;
		void execute(Bureaucrat const &executer) const;
};
