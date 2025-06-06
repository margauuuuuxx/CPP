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

void    Bureaucrat::signForm(AForm &f)
{
    if (f.getIsSigned() == 1)
    {
        std::cout << "Form is already signed !" << std::endl; 
        return;
    }
   try {
        f.beSigned(*this);
        std::cout << "\033[32m" <<this->name << " signed " << f.getName() << "\033[0m" << std::endl;
   }
   catch (const std::exception &e) {
        std::cerr << "\033[31m" << this->name << " (sign: " << this->getGrade() << ")" <<" couldn't sign " << f.getName() << " because " << this->name << " has an insufficent grade to sign " << f.getName() << " (sign: " << f.getGradeSign() << ") " << "\033[0m" << std::endl;
   }
}

void    Bureaucrat::executeForm(AForm const &form)
{
    form.checkExecution(*this);
    try {
        form.execute(*this);
        std::cout << "\033[32m" <<this->name << " executed " << form.getName() << "\033[0m" << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "\033[31m" << this->name << " couldn't execute " << form.getName() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("\033[31mGrade is too high !");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("\033[31mGrade is too low !");
}

std::ostream&   operator << (std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return (os);
}