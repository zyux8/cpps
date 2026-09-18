#pragma once

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include <iostream>

class Intern {
    private:
        typedef AForm *(Intern::*FormPointer)(const std::string& target) const;
        AForm* createPresident(const std::string& target) const;
        AForm* createRobotomy(const std::string& target) const;
        AForm* createShrubbery(const std::string& target) const;
    public:
        Intern();
        ~Intern();
        AForm* makeForm(const std::string& name, const std::string& target);
        class FormNotExist : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};
