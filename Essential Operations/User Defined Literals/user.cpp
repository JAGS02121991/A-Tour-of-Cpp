#include <string>
#include <complex>
#include <chrono>

using namespace std::literals::string_literals;
using namespace std::literals::chrono_literals;
using namespace std::chrono;

constexpr std::complex<double> operator""i(long double imaginary)
{
    return {0, imaginary};
}

int main()
{
    std::complex<double> z = 200.0i + 190.0; // User defined literal

    std::string s = "Hello"s; // Standard literal

    seconds time_until_next_foo = 255s; // Standard literal
}