#include "../includes/PresidentialPardonForm.class.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("Presidential Pardon Form", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm("Presidenial Pardon Form", 25, 5) { *this = other; }

PresidentialPardonForm& PresidentialPardonForm::operator = (const PresidentialPardonForm &other)
{
    if (this != &other)
        this->isSigned = other.isSigned;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void    PresidentialPardonForm::execute(Bureaucrat const &b) const
{
    std::cout << "Bureaucrat target " << b.getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl; 
}