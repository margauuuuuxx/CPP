#ifndef INTERN_CLASS_HPP
# define INTERN_CLASS_HPP

#include "AForm.abstract.hpp"
#include "RobotomyRequestForm.class.hpp"
#include "PresidentialPardonForm.class.hpp"
#include "ShrubberyCreationForm.class.hpp"

struct FormInfo
{
    std::string name;
    AForm* (*create)(std::string);
};

class Intern
{
    private:
        void toLowerCase(std::string& str);

    public:
        Intern();
        Intern(const Intern &other);
        Intern& operator=(const Intern &other);
        ~Intern();

        AForm*  makeForm(std::string formName, std::string formTarget);

        class IncorrectName : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

AForm* createRobotomyRequestForm(std::string target);
AForm* createPresidentialPardonForm(std::string target);
AForm* createShrubberyCreationForm(std::string target);

#endif 