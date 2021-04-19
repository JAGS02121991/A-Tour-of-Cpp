#include "Vector.h"

Vector::Vector(int s) : elems{new double[s]}, sz{s}
{
}

Vector::~Vector()
{
    delete[] elems;
}

double &Vector::operator[](int i)
{
    return elems[i];
}

int Vector::getSize()
{
    return sz;
}
