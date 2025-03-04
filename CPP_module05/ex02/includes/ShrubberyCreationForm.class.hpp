#ifndef SCHRUBBERYCREATIONFORM_CLASS_HPP
# define SCHRUBBERYCREATIONFORM_CLASS_HPP

#include "AForm.abstract.hpp"

class SchrubberyCreationForm : public AForm
{
    private:
        const std::string target;

    public: 
        SchrubberyCreationForm(const std::string &target);
        SchrubberyCreationForm(const SchrubberyCreationForm &other);
        SchrubberyCreationForm& operator=(const SchrubberyCreationForm &other);
        ~SchrubberyCreationForm();

        void generateColor() const;
        void generateTree(int height, std::ofstream& opFile) const;
        void execute(Bureaucrat const &b) const;
};

#endif 