#include "../includes/Bureaucrat.class.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) { *this = other; }

Bureaucrat& Bureaucrat::operator = (const Bureaucrat &other)
{
    if (this != &other)
        this->grade = other.grade;
    return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string   Bureaucrat::getName() const { return (this->name); }

int   Bureaucrat::getGrade() const { return (this->grade); }

void    Bureaucrat::decrementGrade()
{
    if (this->grade == 150)
        throw GradeTooLowException();
    else 
        this->grade++;
}

void    Bureaucrat::incrementGrade()
{
    if (this->grade == 1)
        throw GradeTooHighException();
    else 
        this->grade--;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too high !");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low !");
}

std::ostream&   operator << (std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return (os);
}