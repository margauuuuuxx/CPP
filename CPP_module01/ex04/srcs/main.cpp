/*
    params: <filename> <s1> <s2>
    copies the content of filename into filename.replace an replace evry s1 by s2
*/

#include <fstream>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

void    error(std::string str)
{
    std::cout << str << std::endl;
}

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

std::string    replace(std::string inputContent, std::string s1, std::string s2)
{
    std::string         result;
    size_t              pos;
    size_t              found;

    pos = 0;
    found = 0;
    while ((found = inputContent.find(s1, pos)) != std::string::npos)
    {
        result.append(inputContent, pos, found - pos);
        result.append(s2);
        pos = found + s1.length();
    }
    result.append(inputContent, pos, std::string::npos);
    return (result);
}

int main(int argc, char **argv)
{
    if (argc != 4)
        return(error("Please submit a valid input:\n\t<filename> <s1> <s2>"), 1);
    std::ifstream sourceFile(argv[1]); // open the file for reading
    if (!sourceFile)
        return(error("Error opening input file"), 1);
    std::string fileContent((std::istreambuf_iterator<char>(sourceFile)),
                                std::istreambuf_iterator<char>()); // parcourir sourcefile et le mettre dans filecontent
    sourceFile.close();
    std::string modifiedContent = replace(fileContent, std::string(argv[2]), std::string(argv[3]));
    std::ofstream outputFile(fileName(argv[1])); // opening the file for writing
    if (!outputFile)
        return(error("Error opening ouput file"), 1);
    outputFile << modifiedContent;
    outputFile.close();
}