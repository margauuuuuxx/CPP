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

        bool    operator>(const Fixed& f) const;
        bool    operator<(const Fixed& f) const;
        bool    operator>=(const Fixed& f) const;
        bool    operator<=(const Fixed& f) const;
        bool    operator==(const Fixed& f) const;
        bool    operator!=(const Fixed& f) const;
        Fixed   operator+(const Fixed& f) const;
        Fixed   operator-(const Fixed& f) const;
        Fixed   operator*(const Fixed& f) const;
        Fixed   operator/(const Fixed& f) const;
        Fixed&  operator++();
        Fixed   operator++(int);
        Fixed&  operator--();
        Fixed   operator--(int);

        static Fixed&       min(Fixed& f1, Fixed& f2);
        static const Fixed& minCst(const Fixed& f1, const Fixed& f2);
        static Fixed&       max(Fixed& f1, Fixed& f2);
        static const Fixed& maxCst(const Fixed& f1, const Fixed& f2);
};

std::ostream&   operator<<(std::ostream& out, const Fixed& f);

#endif 
