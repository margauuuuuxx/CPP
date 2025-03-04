#include "../includes/AForm.abstract.hpp"

AForm::AForm(const std::string &name, const int &gradeSign, const int &gradeExec) : name(name), isSigned(false), gradeSign(gradeSign), gradeExec(gradeExec) 
{
    if (gradeSign < 1 || gradeExec < 1)
        throw Bureaucrat::GradeTooHighException();
    if (gradeSign > 150 || gradeExec > 150)
        throw Bureaucrat::GradeTooLowException();
}

AForm::AForm(const AForm &other) : name(other.name), isSigned(other.isSigned), gradeSign(other.gradeSign), gradeExec(other.gradeExec) {}

AForm& AForm::operator = (const AForm &other)
{
    if (this != &other)
        this->isSigned = other.isSigned;
    return (*this);
}

AForm::~AForm() {}

std::string AForm::getName() const { return (this->name); }
bool    AForm::getIsSigned() const { return (this->isSigned); }
int AForm::getGradeSign() const { return (this->gradeSign); }
int AForm::getGradeExec() const { return (this->gradeExec); }

void    AForm::beSigned(Bureaucrat &b)
{
    if (b.getGrade() <= this->getGradeSign())
        this->isSigned = true;
    else 
        throw Bureaucrat::GradeTooLowException();
}

void    AForm::checkExecution(const Bureaucrat &b) const
{
    if (!this->isSigned)
        throw FormNotSignedException();
    if (b.getGrade() > this->gradeExec)
        throw Bureaucrat::GradeTooLowException();
}

std::ostream& operator << (std::ostream& os, const AForm &f)
{
    os << "Form: " << f.getName() << std::endl;
    os << "\t" << "Grade needed to sign: " << f.getGradeSign() << std::endl;
    os << "\t" << "Grade needed to execute: " << f.getGradeExec() << std::endl;
    os << "\t" << "Is signed? " << f.getIsSigned() << std::endl;
    return (os);
}

const char* AForm::FormNotSignedException:: what() const throw()
{
    return ("Form is not signed ..");
}