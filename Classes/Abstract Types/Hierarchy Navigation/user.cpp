#include <vector>
#include "Shape.h"
#include "ShapeBuilder.h"

void rotate_all(std::vector<Shape *> &shapes, int angle)
{
    for (Shape *shape : shapes) {
        shape->rotate(angle);
    }
}

void wink_all_smileys(std::vector<Shape *> const &shapes) {
    /* 
        The vector<Shape *> container returns Shape * so that we can treat all 
        Shapes alike. However, what can we do if we want to use a member function 
        that is only provided by a particular derived class, such as Smiley ’s wink()? 
        We can ask “is this Shape a kind of Smiley ?” using the dynamic_cast operator.
    */
    for (Shape *shape : shapes) {
        if (Smiley *smiley = dynamic_cast<Smiley *>(shape))
            smiley->wink(0);

        /*
            If at run time the object pointed to by the argument of dynamic_cast 
            (here, ps ) is not of the expected type (here, Smiley ) or a class 
            derived from the expected type, dynamic_cast returns nullptr.
        */


        Smiley& r {dynamic_cast<Smiley&>(*shape)}; // somewhere, catch std::bad_cast
        /*
            When a different type is unacceptable, we can simply dynamic_cast
            to a reference type. If the object is not of the expected type,
            dynamic_cast throws a bad_cast exception.
        */
    }
}

int main()
{
    std::vector<Shape *> shapes;
    ShapeBuilder shape_builder;

    shapes.push_back(shape_builder.create_shape(ShapeType::circle));
    shapes.push_back(shape_builder.create_shape(ShapeType::smiley));

    wink_all_smileys(shapes);
}