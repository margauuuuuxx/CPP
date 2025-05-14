#ifndef RPN_CLASS_HPP
#define RPN_CLASS_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <stdexcept>

class RPN
{
    private:
        std::stack<int> _stack;

    public:
        RPN(std::string input);
        RPN(const RPN &other);
        RPN&    operator=(const RPN &other);
        ~RPN();

        int caluculate();
};

#endif