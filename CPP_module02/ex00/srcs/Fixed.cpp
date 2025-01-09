#include "../includes/Fixed.class.hpp"

Fixed::Fixed() : rawBits(0) { std::cout << "Default constructor called" << std::endl; }
Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->rawBits = other.getRawBits();
}

Fixed&  Fixed::operator=(const Fixed& other)
{
    if (this != &other) // protecting against self-assignment
    {
        std::cout << "Copy assignment operator called" << std::endl;
        this->rawBits = other.getRawBits();
    }
    return (*this);
}

int Fixed::getRawBits( void ) const
{ 
    std::cout << "getRawBits member function called" << std::endl;
    return(this->rawBits); 
}

void    Fixed::setRawBits( int const raw ) { this->rawBits = raw; }