#include "ShapeBuilder.h"

std::unique_ptr<Shape> ShapeBuilder::create_shape(ShapeType shape)
{
    //https://stackoverflow.com/questions/4316727/returning-unique-ptr-from-functions
    switch (shape)
    {
    case ShapeType::circle:
        return std::unique_ptr<Shape>(new Circle(Point{0, 0}, 0));

    case ShapeType::smiley:
        return std::unique_ptr<Shape>(new Smiley(Point{0, 0}, 0));

    default:
        return nullptr;
    }
}
