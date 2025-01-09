#include "../includes/Point.class.hpp"

Point::Point() : x(Fixed(0)), y(Fixed(0)) {}
Point::Point(const float x, const float y) : x(Fixed(x)), y(Fixed(y)) {}
Point::Point(const Point& other) : x(other.x), y(other.y) {};
Point::~Point() {};

Point&  Point::operator = (const Point& other) 
{ 
    (void)other;
    throw std::logic_error("Assignment to a const member object is not allowed");
    return (*this); 
} 

float   Point::getx() const { return(this->x.toFloat()); }
float   Point::gety() const { return(this->y.toFloat()); }