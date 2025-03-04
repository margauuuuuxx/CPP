#include "../includes/RobotomyRequestForm.class.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy Request Form", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm("Robotomy Request Form", 72, 45) { *this = other; }

RobotomyRequestForm& RobotomyRequestForm::operator = (const RobotomyRequestForm &other)
{
    if (this != &other)
        this->isSigned = other.isSigned;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void    RobotomyRequestForm::execute(Bureaucrat const &b) const
{
    std::cout << "Driiiiingggg Driiiiiingggg ...." << std::endl;
    srand(time(0));
    if (rand() % 2 == 0)
        std::cout << "Bureaucrat target: " << b.getName() << " has been successfully robotomized !✅" << std::endl;
    else 
        std::cout << "Robotomy of target " << b.getName() << " has failed... ❌" << std::endl;
}