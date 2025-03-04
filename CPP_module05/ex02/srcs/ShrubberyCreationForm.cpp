#include "../includes/ShrubberyCreationForm.class.hpp"
#include <fstream>
#include <cstdlib>
#include <ctime>

SchrubberyCreationForm::SchrubberyCreationForm(const std::string &target) : AForm("Schrubbery Creation Form", 145, 137), target(target) {}

SchrubberyCreationForm::SchrubberyCreationForm(const SchrubberyCreationForm &other) : AForm("Schrubbery Creation Form", 145, 137) { *this = other; }

SchrubberyCreationForm& SchrubberyCreationForm::operator = (const SchrubberyCreationForm &other)
{
    if (this != &other)
        this->isSigned = other.isSigned;
    return (*this);
}

SchrubberyCreationForm::~SchrubberyCreationForm() {}

void    SchrubberyCreationForm::generateColor() const
{
    const std::string   colors[] = {
        "\033[31m",
        "\033[32m",
        "\033[33m",
        "\033[34m",
        "\033[35m",
        "\033[36m",
        "\033[37m",
    };
    int randomIndex = rand() % 7;
    std::cout << colors[randomIndex];
}

void    SchrubberyCreationForm::generateTree(int height, std::ofstream& opFile) const
{
    for (int i = 0; i < height; i++)
    {
        int starsN = 2 * i + 1;
        int spacesN = height - i - 1;
        for (int j = 0; j < spacesN; j++)
            opFile << " ";
        for (int k = 0; k < starsN; k++)
        {
            generateColor();
            opFile << "*";
        }
        opFile << std::endl;
    }
    for (int i = 0; i < height - 1; i++)
        opFile << " ";
    opFile << "|" << std::endl;
}

void    SchrubberyCreationForm::execute(Bureaucrat const &b) const
{
    srand(static_cast<unsigned int>(time(0)));
    std::string fileName = b.getName();
    fileName.append("_shrubbery");
    const char* cFileName = fileName.c_str();
    std::ofstream opFile(cFileName);
    if (!opFile)
    {
        std::cerr << "Error opening output file" << std::endl;
        return;
    }
    int height = rand() % 20 + 1;
    generateTree(height, opFile);
    opFile.close();
}