#include <iostream>

class Complex
{
private:
    double re, im;

public:
    Complex(double r, double i);
    Complex(double r);
    Complex();

    double get_real() const;
    double get_imag() const;

    void set_real(double r);
    void set_imag(double i);

    Complex &operator+=(Complex z);
    Complex &operator-=(Complex z);
    Complex &operator*=(Complex z);
    Complex &operator/=(Complex z);

    friend std::ostream &operator<<(std::ostream &strm, const Complex &z);
};

Complex operator+(Complex a, Complex b);
Complex operator-(Complex a, Complex b);
Complex operator-(Complex a);
Complex operator*(Complex a, Complex b);
Complex operator/(Complex a, Complex b);
