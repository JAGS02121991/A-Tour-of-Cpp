#include "Smiley.h"
#include <iostream>

Smiley::Smiley(Point center, int radius) : Circle{center, radius}, mouth{nullptr}
{
}
Smiley::~Smiley()
{
    std::cout << "Destroying Smiley\n";
}

void Smiley::draw() const
{
    Circle::draw();
    if (mouth)
        mouth->draw();

    // https://stackoverflow.com/questions/20292682/iterating-through-vectorunique-ptrmytype-using-c11-for-loops
    for (auto &eye : eyes)
        eye->draw();
}
void Smiley::rotate(int angle)
{
    std::cout << "Rotate Smiley\n";
    if (mouth)
        mouth->rotate(angle);

    for (auto &eye : eyes)
        eye->rotate(angle);
}

// https://stackoverflow.com/questions/8114276/how-do-i-pass-a-unique-ptr-argument-to-a-constructor-or-a-function/8114913#8114913
void Smiley::add_eye(std::unique_ptr<Shape> eye)
{
    // https://stackoverflow.com/questions/3283778/why-can-i-not-push-back-a-unique-ptr-into-a-vector
    eyes.push_back(std::move(eye));
}
void Smiley::set_mouth(std::unique_ptr<Shape> mouth)
{
    this->mouth = std::move(mouth);
}

void Smiley::wink(int i)
{
    std::cout << "Smiley wink eye: " << i << "\n";
}