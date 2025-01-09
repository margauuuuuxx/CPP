#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int                 rawBits;
        static const int    fractionalBits = 8;
    public:
        Fixed();
        ~Fixed();
        Fixed(const int value);
        Fixed(const float fValue);
        Fixed& operator = (const Fixed& other);

        int     getRawBits ( void ) const;
        void    setRawBits( int const raw );
        float   toFloat( void ) const;
        int     toInt( void ) const;
};

std::ostream&   operator<<(std::ostream& out, const Fixed& f); // *

#endif 

/*
    std::ostream&   = the output stream where we want to print
    defining operator<< as the fct name so the compiler gets that i define how the
                            << operator works for Fixed objects 
*/