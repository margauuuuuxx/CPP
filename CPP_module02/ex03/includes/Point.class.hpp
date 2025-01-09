#ifndef POINT_CLASS_HPP
# define POINT_CLASS_HPP

#include "Fixed.class.hpp"

#define EPSILON 0.00000011929093

class Point
{
    private:
        const Fixed x;
        const Fixed y;
        //  ...
    public:
        Point();
        Point(const float x, const float y);
        Point(const Point& other);
        Point& operator = (const Point& other);
        ~Point();

        float   getx() const;
        float   gety() const;

};

bool    bsp(Point const a, Point const b, Point const c, Point const point);

#endif 