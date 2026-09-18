#pragma once

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		std::string _target;
		void robotomize() const;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		virtual ~RobotomyRequestForm();
		std::string getTarget() const;
		void execute(Bureaucrat const &executer) const;
};
