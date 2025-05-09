#ifndef AFORM_CLASS_HPP
# define AFORM_CLASS_HPP

#include "Bureaucrat.class.hpp"
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class AForm
{
    protected:
        const       std::string name;
        bool        isSigned;
        const int   gradeSign;
        const int   gradeExec;

    public:
        AForm(const std::string &name, const int &gradeSign, const int &gradeExec);
        AForm(const AForm &other);
        AForm& operator=(const AForm &other);
        ~AForm();

        std::string getName() const;
        bool getIsSigned() const;
        int getGradeSign() const;
        int getGradeExec() const;
        void beSigned(Bureaucrat &b);
        virtual void execute(Bureaucrat const & executor) const = 0; // this pure virtual function is what makes the class abstract 
        void checkExecution(const Bureaucrat &b) const;   

        class FormNotSignedException : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& i);

#endif 