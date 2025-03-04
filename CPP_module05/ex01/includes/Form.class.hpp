#ifndef FORM_CLASS_HPP
# define FORM_CLASS_HPP

#include "Bureaucrat.class.hpp"
#include <iostream>
#include <cstdbool>

class Bureaucrat;

class Form
{
    private:
        const       std::string name;
        bool        isSigned;
        const int   gradeSign;
        const int   gradeExec;

    public:
        Form(const std::string &name, const int &gradeSign, const int &gradeExec);
        Form(const Form &other);
        Form& operator=(const Form &other);
        ~Form();

        std::string getName() const;
        bool getIsSigned() const;
        int getGradeSign() const;
        int getGradeExec() const;
        void beSigned(Bureaucrat &b);    
};

std::ostream& operator<<(std::ostream& os, const Form& i);

#endif 