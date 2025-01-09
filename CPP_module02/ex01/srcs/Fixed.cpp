#include "../includes/Fixed.class.hpp"

Fixed::Fixed() { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed(const int value)
{ 
    std::cout << "Default constructor called" << std::endl; 
    this->rawBits = value << fractionalBits;
}
Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed::Fixed(const float fValue)
{
    std::cout << "Copy constructor called" << std::endl;
    this->rawBits = roundf(fValue * (1 << fractionalBits));
}

Fixed&  Fixed::operator=(const Fixed& other)
{
    if (this != &other)
    {
        std::cout << "Copy assignment operator called" << std::endl;
        this->rawBits = other.getRawBits();
    }
    return (*this);
}

float   Fixed::toFloat( void ) const { return (static_cast<float>(this->rawBits) / (1 << this->fractionalBits)); } // *
int Fixed::toInt( void ) const { return (this->rawBits >> fractionalBits); }


int Fixed::getRawBits( void ) const
{ 
    std::cout << "getRawBits member function called" << std::endl;
    return(this->rawBits); 
}

void    Fixed::setRawBits( int const raw ) { this->rawBits = raw; }

std::ostream&   operator<<(std::ostream& out, Fixed const& f)
{
    out << f.toFloat();
    return (out);
}

/*
    bitwise left shift operator : 
        when (1 << x) that means 2ˆx so (1 << 8) converts into 256 bits 
*/