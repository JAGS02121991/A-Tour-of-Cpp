#include "Point.h"
#include "Circle.h"
#include <iostream>

Circle::Circle(Point c, int r) : center{c}, radius{r}
{
}

Circle::~Circle()
{
    std::cout << "Destroying Circle\n";
}

Point Circle::get_center() const
{
    return center;
}
void Circle::move(Point to)
{
    center = to;
}
void Circle::draw() const {}
void Circle::rotate(int angle)
{
    std::cout << "Rotate circle\n";
}
