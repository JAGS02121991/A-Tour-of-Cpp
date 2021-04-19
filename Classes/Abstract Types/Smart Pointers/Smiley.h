#ifndef SMILEY_H
#define SMILEY_H

#include <vector>
#include <memory>
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
    void add_eye(std::unique_ptr<Shape> eye);
    void set_mouth(std::unique_ptr<Shape> mouth);
    void wink(int eye_index);

private:
    std::unique_ptr<Shape> mouth;
    std::vector<std::unique_ptr<Shape>> eyes;
};

#endif /* SMILEY_H */