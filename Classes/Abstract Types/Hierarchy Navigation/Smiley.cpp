#include "Smiley.h"
#include <iostream>

Smiley::Smiley(Point center, int radius) : Circle{center, radius}, mouth{nullptr}
{
}

Smiley::~Smiley()
{
    delete mouth;
    for (Shape *eye : eyes)
        delete eye;
}

void Smiley::draw() const
{
    Circle::draw();
    mouth->draw();
    for (Shape *eye : eyes)
        eye->draw();
}
void Smiley::rotate(int angle)
{
    std::cout << "Rotate Smiley\n";
    if (mouth)
        mouth->rotate(angle);

    for (Shape *eye : eyes)
        eye->rotate(angle);
}

void Smiley::add_eye(Shape *eye)
{
    eyes.push_back(eye);
}
void Smiley::set_mouth(Shape *mouth)
{
    this->mouth = mouth;
}

void Smiley::wink(int i)
{
    std::cout << "Smiley wink eye: " << i << "\n";
}