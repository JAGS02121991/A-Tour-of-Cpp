#ifndef SHAPEBUILDER_H
#define SHAPEBUILDER_H

#include "Circle.h"
#include "Smiley.h"
#include "Shape.h"

enum class ShapeType { circle, smiley };

class ShapeBuilder {
    public:
        Shape* create_shape(ShapeType shape);
};

#endif /* SHAPEBUILDER_H */