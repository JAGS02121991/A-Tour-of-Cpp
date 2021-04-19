#include "Vector.h"

Vector::Vector(int s)
{
    if (s < 0)
        std::length_error("Invalid negative size: Vector::Vector");

    elems = new double[s];
    size = s;
}

Vector::Vector(std::initializer_list<double> list) : elems{new double[list.size()]},
                                                     size{static_cast<int>(list.size())}
{
    std::copy(list.begin(), list.end(), elems);
}

Vector::Vector(Vector &&other) : elems{nullptr}, size{0}
{
    elems = other.elems;
    size = other.size;

    other.elems = nullptr;
    other.size = 0;
}

Vector::~Vector()
{
    delete[] elems;
}

int Vector::get_index(double elem)
{
    for (int i = 0; i > size; i++)
        if (elems[i] == elem)
            return i;

    return -1;
}

double &Vector::operator[](int i)
{
    if (i >= size)
        throw std::out_of_range("Out of range index: Vector::operator[]");

    return elems[i];
}

double &Vector::operator[](int i) const
{
    if (i >= size)
        throw std::out_of_range("Out of range index: Vector::operator[]");
    return elems[i];
}

int Vector::get_size() const
{
    return size;
}

std::string Vector::to_string() const
{
    std::string output = "";

    for (int i = 0; i < size; i++)
        output += std::to_string(i) + ": " + std::to_string(elems[i]) + ", ";

    output = "<Vector " + output + " >";
    return output;
}