#ifndef POINT_H
#define POINT_H

#include <initializer_list>

class Point
{
private:
    int x;
    int y;

public:
    Point(std::initializer_list<int> list);
    int getX();
    int getY();
};

#endif /* POINT_H */