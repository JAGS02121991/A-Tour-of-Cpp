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

    // As the source of an assignment
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

    // As a function return value
    Vector(Vector &&a) : elems{a.elems}, sz{a.size()}
    {
        std::cout << "Vector: move constructor \n";
        a.elems = nullptr;
        a.size(0);
    }

    // As an exception

    friend std::ostream &operator<<(std::ostream &stream, const Vector &a)
    {
        stream << "<Vector ";
        for (int i = 0; i < a.size(); i++)
            stream << std::to_string(i) << ": " << std::to_string(a[i]) << ", ";

        stream << " >\n";
        return stream;
    }
};

Vector add(Vector a, Vector &b) // a will call copy constructor, b will just pass it's reference
{
    if (a.size() != b.size())
        throw std::length_error("Vector add(Vector, Vector): could not add vectors\n");

    Vector output(a.size());
    for (int i = 0; i < a.size(); i++)
        output[i] = a[i] + b[i];

    std::cout << "About to return \n";
    return std::move(output);
}

// Simple user defined classes
class Complex
{
private:
    double i = 0.0;
    double r = 0.0;

public:
    Complex(double r, double i) : r{r}, i{i}
    {
        std::cout << "Complex Class: normal constructor \n";
    }
    Complex(double r) : r{r} {}
    Complex() {}

    // As a function argument
    // As an object initializer
    Complex(Complex &c) : r{c.real()}, i{c.img()}
    {
        std::cout << "Complex Class: copy constructor \n";
    }

    // As a function return value
    Complex(Complex &&c) : r{c.real()}, i{c.img()}
    {
        std::cout << "Complex Class: move constructor \n";
    }
    Complex &operator=(Complex &&z)
    {
        this->img(z.img());
        this->real(z.real());

        return *this;
    }

    // As the source of an assignment
    // As an exception

    double real()
    {
        return r;
    }

    void real(double real)
    {
        r = real;
    }

    double img()
    {
        return i;
    }

    void img(double img)
    {
        i = img;
    }

    friend std::ostream &operator<<(std::ostream &stream, const Complex &z)
    {
        stream << "<Complex " << z.r << "," << z.i << "i >\n";
        return stream;
    }
};
Complex add(Complex a, Complex b) // default copy constructor
{
    Complex res(a.real(), b.real());

    return std::move(res); // default move constructor
}

int main()
{
    // Complex a(1, 2);
    // Complex b(3, 4);

    // std::cout << add(a, b);

    Vector v1{1, 2, 3}; // Default constructor
    Vector v2{3, 4, 5};

    // Vector v3 = v2; // Copy Constructor
    // Vector v4(v2);

    // v3 = v1; // Copy assignment

    {
        Vector v6 = 10; // This is horrible, this compiles t Vector v6(10) and it is not intuitive
        // We can get rid of this behaviour by using explicit on the constructor

        Vector v5 = add(v1, v2);

        std::cout << v5;

        v2 = std::move(v5); // Cannot use v5 anymore
    }

    std::cout << v2;
}