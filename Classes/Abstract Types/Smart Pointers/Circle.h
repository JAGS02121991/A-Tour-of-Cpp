#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include "Point.h"

class Circle : public Shape
{
public:
    Circle(Point center, int radius);
    Point get_center() const override;
    void move(Point to) override;
    virtual void draw() const override;
    virtual void rotate(int angle) override;
    virtual ~Circle() override;

private:
    Point center;
    int radius;
};

#endif /* CIRCLE_H */