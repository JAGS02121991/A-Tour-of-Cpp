#include "ShapeBuilder.h"

Shape* ShapeBuilder::create_shape(ShapeType shape) {
    switch(shape) {
        case ShapeType::circle:
            return new Circle(Point{0, 0}, 0);

        case ShapeType::smiley:
            return new Smiley(Point{0, 0}, 0);

        default:
            return nullptr;
    }
}

