#include <iostream>
#include <initializer_list>
#include <stdexcept>
#include <string>

class Vector
{
private:
    double *elems;
    int sz;

public:
    int size() const
    {
        return sz;
    }
    void size(int size)
    {
        sz = size;
    }
    double &operator[](int i)
    {
        return elems[i];
    }
    double &operator[](int i) const
    {
        return elems[i];
    }

    Vector(int size) : elems{new double[size]}, sz{size}
    {
        std::cout << "Vector: default constructor\n";
    }
    Vector(std::initializer_list<double> list) : elems{new double[list.size()]}, sz{static_cast<int>(list.size())}
    {
        std::cout << "Vector: default constructor\n";
        auto it = list.begin();
        for (int i = 0; i < list.size(); i++)
        {
            elems[i] = *it;
            ++it;
        }
    }

    ~Vector()
    {
        delete[] elems;
    }

    // As an object initializer
    // As a function argument
    Vector(Vector &a) : elems{new double[a.size()]}, sz{a.size()}
    {
        std::cout << "Vector: copy constructor \n";
        for (int i = 0; i < a.size(); i++)
            elems[i] = a[i];
    }

    Vector &operator=(Vector &a)
    {
        std::cout << "Vector: copy assignment \n";

        delete[] elems;
        elems = new double[a.size()];
        sz = a.size();

        for (int i = 0; i < a.size(); i++)
            elems[i] = a[i];

        return *this;
    }

    Vector &operator=(Vector &&a)
    {
        std::cout << "Vector: move assignment \n";

        delete[] elems;

        elems = a.elems;
        sz = a.size();

        a.elems = nullptr;
        a.size(0);

        return *this;
    }

    Vector(Vector &&a) : elems{a.elems}, sz{a.size()}
    {
        std::cout << "Vector: move constructor \n";
        a.elems = nullptr;
        a.size(0);
    }

    friend std::ostream &operator<<(std::ostream &stream, const Vector &a)
    {
        stream << "<Vector ";
        for (int i = 0; i < a.size(); i++)
            stream << std::to_string(i) << ": " << std::to_string(a[i]) << ", ";

        stream << " >\n";
        return stream;
    }
};

int main()
{

    Vector v1{1, 2, 3}; // Default constructor
    Vector v2{4, 5, 6};

    std::swap(v1, v2);
    /*
        Only uses moves, not copies making this quite efficient, the only caviat
        is that you need to supply Copy Constructor and Copy assignment to your
        class for this to work
    */

    std::cout << v1;
    std::cout << v2;
}