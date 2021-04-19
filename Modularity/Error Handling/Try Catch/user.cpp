/*
    The main technique for making error handling simple and
    systematic is called  Resource Adquisition Is Initialization RAII
*/

#include <iostream>
#include <stdexcept>

class Vector
{
public:
    Vector(int s) : elems{new double[s]}, sz{s}
    {
    }

    ~Vector()
    {
        delete elems;
    }

    double &operator[](int i)
    {
        if (i < 0 || i > sz - 1)
            throw std::out_of_range("Out of range error: Vector::operator[]");
        return elems[i];
    }

    int getSize()
    {
        return sz;
    }

private:
    double *elems;
    int sz;
};

int main()
{
    Vector v = Vector(12);
    try
    {
        v[v.getSize()] = 25;
    }
    catch (std::out_of_range &err) // Used reference to avoid copying
    {
        std::cerr << err.what() << "\n";
    }
}
