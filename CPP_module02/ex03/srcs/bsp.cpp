#include "../includes/Point.class.hpp"

bool    bsp(Point const a, Point const b, Point const c, Point const point)
{
    float   x;
    float   y;
    float   z;
    float   pointx = point.getx();
    float   pointy = point.gety();
    float   x1 = a.getx();
    float   y1 = a.gety();
    float   x2 = b.getx();
    float   y2 = b.gety();
    float   x3 = c.getx();
    float   y3 = c.gety();

    x = ((y2 -y3) * (pointx - x3) + (x3 - x2) * (pointy - y3)) / ((y2 - y3) * (x1 -x3) + (x3 -x2) * (y1 - y3));
    y = ((y3 - y1) * (pointx - x3) + (x1 - x3) * (pointy - y3)) / ((y2 - y3) * (x1 - x3) + (x3 - x2) * (y1 - y3));
    z = 1 - x - y;

    if (x >= -EPSILON && x <= 1 + EPSILON
            && y >= -EPSILON && y <= 1 + EPSILON
            && z >= -EPSILON && z <= 1 + EPSILON)
        return (true);
    return (false);
}