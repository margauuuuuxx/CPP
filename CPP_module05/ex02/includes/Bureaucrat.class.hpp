#ifndef BUREAUCRAT_CLASS_HPP
# define BUREAUCRAT_CLASS_HPP

#include <iostream>
#include <stdexcept>
#include "AForm.abstract.hpp"

class AForm;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;

    public:
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat& operator=(const Bureaucrat &other);
        ~Bureaucrat();

        std::string getName() const;
        int getGrade() const;
        void decrementGrade();
        void incrementGrade();
        void signForm(AForm &f);
        void executeForm(AForm const & form);

        class GradeTooHighException : public std::exception
        {
            public: 
                const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif 