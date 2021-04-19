#include <vector>
#include "Shape.h"
#include "ShapeBuilder.h"

int main()
{

    std::vector<std::unique_ptr<Shape>> shapes;
    ShapeBuilder shape_builder;

    auto left_eye = std::unique_ptr<Shape>{new Circle(Point{10, 10}, 10)};
    auto right_eye = std::unique_ptr<Shape>{new Circle(Point{20, 10}, 10)};

    auto smiley = shape_builder.create_shape(ShapeType::smiley);

    {
        // https://stackoverflow.com/questions/36120424/alternatives-of-static-pointer-cast-for-unique-ptr
        Smiley *smiley_ptr = dynamic_cast<Smiley *>(smiley.get());
        smiley_ptr->add_eye(std::move(left_eye));
        smiley_ptr->add_eye(std::move(right_eye));
        smiley_ptr->set_mouth(std::unique_ptr<Shape>{new Circle(Point{20, 10}, 10)}); // Since it is a r-value, it will move by default
    }

    shapes.push_back(shape_builder.create_shape(ShapeType::circle));
    shapes.push_back(shape_builder.create_shape(ShapeType::smiley));
}