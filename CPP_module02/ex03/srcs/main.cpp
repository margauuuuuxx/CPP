#include "../includes/Point.class.hpp"
#include <SFML/Graphics.hpp>
#include <optional>

int displayTriangle(Point const a, Point const b, Point const c, Point const point)
{
    sf::RenderWindow window(sf::VideoMode(sf::Vector2f(800, 600)));

    sf::CircleShape pointShape(5);
    pointShape.setFillColor(sf::Color::Red);
    float   pointx = point.getx();
    float   pointy = point.gety();
    pointShape.setPosition(sf::Vector2f(pointx - 5, pointy - 5));


    float   Ax = a.getx();
    float   Ay = a.gety();
    float   Bx = b.getx();
    float   By = b.gety();
    float   Cx = c.getx();
    float   Cy = c.gety();
    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(Ax, Bx));
    triangle.setPoint(1, sf::Vector2f(Bx, By));
    triangle.setPoint(2, sf::Vector2f(Cx, Cy));
    triangle.setFillColor(sf::Color(100, 100, 255, 100));

    while (window.isOpen())
    {
        std::optional<sf::Event> event = window.pollEvent(); // checks for mouse clicks, key presses, ..
        if (event)
        {
            if (event->is == sf::Event::Closed)
        }
    }
}

int main()
{
    Point const a(2, 3);
    Point const b(3.14f, 3.14f);
    Point const c(5.00356f, 0);
    Point const point(2.5f, 1.2f);

    std::cout << "ax = " << a.getx() << "\tay = " << a.gety() << std::endl;
    std::cout << "bx = " << b.getx() << "\tby = " << b.gety() << std::endl;
    std::cout << "cx = " << c.getx() << "\tcy = " << c.gety() << std::endl;
    std::cout << "pointx = " << point.getx() << "\tpointy = " << point.gety() << std::endl;
    std::cout << std::endl;
    std::cout << bsp(a, b, c, point) << std::endl;
    return (0);
}

