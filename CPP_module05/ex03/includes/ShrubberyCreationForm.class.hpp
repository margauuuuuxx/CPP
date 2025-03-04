#ifndef SCHRUBBERYCREATIONFORM_CLASS_HPP
# define SCHRUBBERYCREATIONFORM_CLASS_HPP

#include "AForm.abstract.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        const std::string target;

    public: 
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);
        ~ShrubberyCreationForm();

        void generateColor() const;
        void generateTree(int height, std::ofstream& opFile) const;
        void execute(Bureaucrat const &b) const;
};

#endif 