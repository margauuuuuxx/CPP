#ifndef ROBOTOMYREQUESTFORM_CLASS_HPP
# define ROBOTOMYREQUESTFORM_CLASS_HPP

#include "AForm.abstract.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        const std::string   target;

    public:
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm &other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm &other);
        ~RobotomyRequestForm();

        void execute(Bureaucrat const &b) const;
};

#endif