#include <cmath>
#include <iostream>

namespace My_code
{
    class complex
    {
    public:
        complex(float r, float i) : real{r}, imaginary{i}
        {
        }

        float getReal()
        {
            return real;
        }

        float getImaginary()
        {
            return imaginary;
        }

    private:
        float real;
        float imaginary;
    };

    complex sqrt(complex z)
    {
        return complex{
            std::sqrt(z.getReal()),
            std::sqrt(z.getImaginary())};
    }

    void main();
}

void My_code::main()
{
    complex z{1, 2};
    auto z2 = sqrt(z);

    std::cout << "real: " << z2.getReal() << ","
              << "imaginary: " << z2.getImaginary() << "\n";
}

int main()
{
    My_code::main();
}