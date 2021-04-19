#include <iostream>
#include "Complex.h"

Complex::Complex(double r, double i) : re{r}, im{i} {}
Complex::Complex(double r) : re{r}, im{0} {}
Complex::Complex() : re{0}, im{0} {}

double Complex::get_real() const { return re; }
double Complex::get_imag() const { return im; }
void Complex::set_real(double r) { re = r; }
void Complex::set_imag(double i) { im = i; }

Complex &Complex::operator+=(Complex z)
{
    re += z.re;
    im += z.im;
    return *this;
}
Complex &Complex::operator-=(Complex z)
{
    re -= z.re;
    im -= z.im;
    return *this;
}
Complex &Complex::operator*=(Complex z)
{
    re *= z.re;
    im *= z.im;
    return *this;
}
Complex &Complex::operator/=(Complex z)
{
    re /= z.re;
    im /= z.im;
    return *this;
}
std::ostream &operator<<(std::ostream &stream, const Complex &z)
{
    return stream << z.get_real() << ", " << z.get_imag() << "i";
}

Complex operator+(Complex a, Complex b) { return a += b; }
Complex operator-(Complex a, Complex b) { return a -= b; }
Complex operator-(Complex a) { return {-a.get_real(), -a.get_imag()}; } // unary minus
Complex operator*(Complex a, Complex b) { return a *= b; }
Complex operator/(Complex a, Complex b) { return a /= b; }