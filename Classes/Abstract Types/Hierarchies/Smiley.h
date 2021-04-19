#include <vector>
#include "Circle.h"
#include "Shape.h"

/*
    Implementation Inheritance:
        A base class provides functions and/or data that simplifies
        the implementation of a derived class. e.g. Smiley's draw
        uses Circle's draw.
*/

class Smiley : public Circle
{
public:
    Smiley(Point center, int radius);
    ~Smiley() override;
    void draw() const override;
    void rotate(int angle) override;
    void add_eye(Shape *eye);
    void set_mouth(Shape *mouth);

private:
    Shape *mouth;
    std::vector<Shape *> eyes;
};