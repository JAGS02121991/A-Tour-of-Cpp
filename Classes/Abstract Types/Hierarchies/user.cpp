#include <vector>
#include "Point.h"
#include "Shape.h"
#include "Smiley.h"

void rotate_all(std::vector<Shape *> &shapes, int angle)
{
    for (Shape *shape : shapes)
        shape->rotate(angle);
}

int main()
{
    std::vector<Shape *> shapes;

    shapes.push_back(new Smiley(Point{0, 2}, 10));
    shapes.push_back(new Circle(Point{1, 3}, 5));

    rotate_all(shapes, 30);
}