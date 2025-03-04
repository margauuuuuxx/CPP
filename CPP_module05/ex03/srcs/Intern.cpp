#include "../includes/Intern.class.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) { (void)other; }

Intern& Intern::operator = (const Intern &other) 
{ 
    (void)other;
    return (*this);
}

Intern::~Intern() {}

AForm*  Intern::makeForm(std::string formName, std::string formTarget)
{
    toLowerCase(formName);
    FormInfo formTypes[] = { 
        {"robotomy request", &createRobotomyRequestForm}, 
        {"robotomy Request form", &createRobotomyRequestForm},
        {"presidential pardon", &createPresidentialPardonForm}, 
        {"presidential pardon form", &createPresidentialPardonForm},
        {"shrubbery creation", &createShrubberyCreationForm},
        {"shrubbery creation form", &createShrubberyCreationForm},
    };
    for (int i = 0; i < 6; i++)
    {
        if (formTypes[i].name == formName)
        {
            std::cout << "Intern creates " << formName << " for target "<< formTarget <<"📑" << std::endl;
            return (formTypes[i].create(formTarget));
        }
    }
    throw IncorrectName();
}

AForm*  createRobotomyRequestForm(std::string target) { return new RobotomyRequestForm(target); }
AForm*  createPresidentialPardonForm(std::string target) { return new PresidentialPardonForm(target); }
AForm*  createShrubberyCreationForm(std::string target) { return new ShrubberyCreationForm(target); }

void    Intern::toLowerCase(std::string &str)
{
    for (size_t i = 0; i < str.size(); i++)
        str[i] = std::tolower(str[i]);
}

const char* Intern::IncorrectName::what() const throw()
{
    return ("\033[31mIntern cannot make form because the name is invalid, please submit a valid name:\n\tRobotomy Request / Presidential Pardon / Schrubbery Creation\033[0m");
}