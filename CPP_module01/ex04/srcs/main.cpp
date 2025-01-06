/*
    params: <filename> <s1> <s2>
    copies the content of filename into filename.replace an replace evry s1 by s2
*/

#include <fstream>
#include <iostream>
#include <string>
#include <fstream>

std::string    fileName(std::string str)
{
    std::string result;
    size_t  lastDot = str.rfind('.');
    if (lastDot != std::string::npos)
        result = str.substr(0, lastDot + 1) + "replace";
    else 
        result = str + ".replace";
    return (result);
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Please submit a valid input:\n\t<filename> <s1> <s2>" << std::endl;
        return (1);
    }

    std::ifstream sourceFile(argv[1]); // open the file for reading
    if (!sourceFile)
    {
        std::cerr << "Error opening source file" << std::endl;
        return (1);
    }

    // std::cout << "test filename: " << fileName(argv[1]) << std::endl;

    // std::string fileName = fileName(argv[1]);
    // //std::string fileName = argv[1] + "replace";
    // std::ofstream destFile()
    // test << "this is a test input" << std::endl;
}