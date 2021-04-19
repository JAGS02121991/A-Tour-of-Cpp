#include <iostream>
#include <complex>
#include "Vector.hpp"

using namespace std::complex_literals;

template <typename Sequence, typename Value>
Value sum(Sequence &sequence, Value value)
{
    for (auto elem : sequence)
        value += elem;

    return value;
}

int main()
{
    Vector v{1, 2, 3, 4, 5};                       // Vector<int> v
    Vector v2{1.0i + 1.5, 2.0i + 2.0, 4.0i + 5.0}; // Vector<std::complex<double>> v2

    std::cout << sum(v, 0) << "\n";
    std::cout << sum(v2, 0.0i) << "\n";
}