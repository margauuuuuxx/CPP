#include "../includes/RPN.class.hpp"

RPN::RPN() {}

RPN::RPN(std::string input)
{
    std::istringstream  iss(input);
    std::string         token;

    while (iss >> token)
    {
        if (token == "+" || token == "-" 
            || token == "*" || token == "/")
        {
            if (_stack.size() < 2)
                throw::std::runtime_error("\e[31mError: Not enough operands ..\e[0m");
        
            int b = _stack.top();
            _stack.pop();

            int a = _stack.top();
            _stack.pop();

            if (token == "+")
                _stack.push(a + b);
            else if (token == "-")
                _stack.push(a - b);
            else if (token == "*")
                _stack.push(a * b);
            else if (token == "/")
            {
                if (b == 0)
                    throw::std::runtime_error("\e[31mError: Division by 0 is undefined ..\e[0m");
                _stack.push(a / b);
            }
        }
        else
        {
            std::istringstream  ss(token);
            int                 value;

            if (!(ss >> value) || value > 9 || value < 0)
                throw::std::runtime_error("\e[31mError: Invalid token: " + token + " ..\e[0m");
            
            _stack.push(value);
        }
    }

    if (_stack.size() != 1)
        throw::std::runtime_error("\e[31mError: Malformed expression ..\e[0m");
}

RPN::RPN(const RPN &other) { *this = other; }

RPN&    RPN::operator = (const RPN &other)
{
    if (this != &other)
        this->_stack = other._stack;
    return (*this);
}

RPN::~RPN() {}

int RPN::caluculate() { return (_stack.top()); }