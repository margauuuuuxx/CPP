#include "../includes/Form.class.hpp"

Form::Form(const std::string &name, const int &gradeSign, const int &gradeExec) : name(name), isSigned(false), gradeSign(gradeSign), gradeExec(gradeExec) 
{
    if (gradeSign < 1 || gradeExec < 1)
        throw Bureaucrat::GradeTooHighException();
    if (gradeSign > 150 || gradeExec > 150)
        throw Bureaucrat::GradeTooLowException();
}

Form::Form(const Form &other) : name(other.name), isSigned(other.isSigned), gradeSign(other.gradeSign), gradeExec(other.gradeExec) {}

Form& Form::operator = (const Form &other)
{
    if (this != &other)
        this->isSigned = other.isSigned;
    return (*this);
}

Form::~Form() {}

std::string Form::getName() const { return (this->name); }
bool    Form::getIsSigned() const { return (this->isSigned); }
int Form::getGradeSign() const { return (this->gradeSign); }
int Form::getGradeExec() const { return (this->gradeExec); }

void    Form::beSigned(Bureaucrat &b)
{
    if (b.getGrade() <= this->getGradeSign())
        this->isSigned = true;
    else 
        throw Bureaucrat::GradeTooLowException();
}

std::ostream& operator << (std::ostream& os, const Form &f)
{
    os << "Form: " << f.getName() << std::endl;
    os << "\t" << "Grade needed to sign: " << f.getGradeSign() << std::endl;
    os << "\t" << "Grade needed to execute: " << f.getGradeExec() << std::endl;
    os << "\t" << "Is signed? " << f.getIsSigned() << std::endl;
    return (os);
}