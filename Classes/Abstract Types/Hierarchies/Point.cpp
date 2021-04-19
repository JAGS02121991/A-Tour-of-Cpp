#include "Point.h"
#include <stdexcept>

Point::Point(std::initializer_list<int> list)
{
    if (list.size() != 2)
        throw std::length_error("Initializer list is not of size 2");

    auto it = list.begin();

    x = *it;
    ++it;
    y = *it;
}

int Point::getX()
{
    return x;
}
int Point::getY()
{
    return y;
}
