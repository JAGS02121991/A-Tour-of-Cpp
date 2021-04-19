#include <iostream>
#include <initializer_list>
#include <stdexcept>
#include <string>

class Complex
{
private:
    double i;
    double r;

public:
    Complex(double r, double i) : r{r}, i{i}
    {
        std::cout << "Complex Class: normal constructor \n";
    }

    // Conversion from double to Complex
    explicit Complex(double r) : r{r}, i{0.0} {}
    Complex() : r{0.0}, i{0.0} {}

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

int main()
{
    Complex a(1.0); // Converts from 1.0 double to 1.0, 0.0i Complex

    // Complex a = 1.0; // This would normally call Complex a(1.0)
    // but we disallowed the implicit conversion between double and complex
    // by setting explicit in the constructor

    std::cout << a;
}