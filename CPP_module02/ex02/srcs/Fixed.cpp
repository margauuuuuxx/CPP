#include "../includes/Fixed.class.hpp"

// CONSTRUCTORS & DESTRUCTOR

Fixed::Fixed(): rawBits(0) {}
Fixed::Fixed(const int value) { this->rawBits = value << fractionalBits; }
Fixed::Fixed(const float fValue) { this->rawBits = roundf(fValue * (1 << fractionalBits)); }
Fixed::~Fixed() {}

Fixed::Fixed(const Fixed& other) { this->rawBits = other.getRawBits(); }

Fixed&  Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        this->rawBits = other.getRawBits();
    return (*this);
}

// GETTER & SETTER
int Fixed::getRawBits( void ) const { return(this->rawBits); }
void    Fixed::setRawBits( int const raw ) { this->rawBits = raw; }

// CONVERSIONS
float   Fixed::toFloat( void ) const { return (static_cast<float>(this->rawBits) / (1 << this->fractionalBits)); } // *
int Fixed::toInt( void ) const { return (this->rawBits >> fractionalBits); }

// OPERATORS 
bool    Fixed::operator > (const Fixed& f) const { return (this->rawBits > f.getRawBits()); }
bool    Fixed::operator < (const Fixed& f) const { return (this->rawBits < f.getRawBits()); }
bool    Fixed::operator >= (const Fixed& f) const { return (this->rawBits >= f.getRawBits()); }
bool    Fixed::operator <= (const Fixed& f) const { return (this->rawBits <= f.getRawBits()); }
bool    Fixed::operator == (const Fixed& f) const { return (this->rawBits == f.getRawBits()); }
bool    Fixed::operator != (const Fixed& f) const { return (this->rawBits != f.getRawBits()); }
Fixed   Fixed::operator + (const Fixed& f) const { return (Fixed(this->toFloat() + f.toFloat())); }
Fixed   Fixed::operator - (const Fixed& f) const { return (Fixed(this->toFloat() - f.toFloat())); }
Fixed   Fixed::operator * (const Fixed& f) const { return (Fixed(this->toFloat() * f.toFloat())); }
Fixed   Fixed::operator / (const Fixed& f) const 
{ 
    if (f.toFloat() == 0)
        throw std::logic_error("\033[31mDivision by 0 is undefined\033[0m");
    return (Fixed(this->toFloat() / f.toFloat())); 
}

Fixed&  Fixed::operator++()
{
    this->rawBits++;
    return (*this);
}

Fixed   Fixed::operator++(int)
{
    Fixed   old;

    old = *this;
    ++(*this);
    return (old);
}

Fixed&   Fixed::operator--()
{
    this->rawBits--;
    return (*this);
}

Fixed  Fixed::operator--(int)
{
    Fixed   old;

    old = *this;
    --(*this);
    return (old);
}

std::ostream&   operator<<(std::ostream& out, const Fixed& f)
{
    out << f.toFloat();
    return (out);
}

// MINS & MAXS 
Fixed&   Fixed::min(Fixed& f1, Fixed& f2)
{
    if (f1.toFloat() >= f2.toFloat())
        return (f2);
    return (f1);
}

const Fixed& Fixed::minCst(const Fixed& f1, const Fixed& f2)
{
    if (f1.toFloat() >= f2.toFloat())
        return (f2);
    return (f1);
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2)
{
    if (f1.toFloat() >= f2.toFloat())
        return (f1);
    return (f2);
}

const Fixed& Fixed::maxCst(const Fixed& f1, const Fixed& f2)
{
    if (f1.toFloat() >= f2.toFloat())
        return (f1);
    return (f2);
}
