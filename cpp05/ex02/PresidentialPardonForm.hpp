#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string _target;
		void pardon() const;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		virtual ~PresidentialPardonForm();
		std::string getTarget() const;
		void execute(Bureaucrat const &executer) const;
};
