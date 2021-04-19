#ifndef SHAPE_H
#define SHAPE_H

#include "Point.h"

class Shape
{
public:
    virtual Point get_center() const = 0;
    virtual void move(Point to) = 0;
    virtual void draw() const = 0;
    virtual void rotate(int angle) = 0;
    virtual ~Shape(){};
};

#endif /* SHAPE_H */