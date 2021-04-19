#include "Vector.hpp"
#include <string>

class Car
{
private:
    std::string manufacturer = "Unmarked";

public:
    Car()
    {
        std::cout << "Car(" << manufacturer << "): default constructor \n";
    }

    Car &operator=(const Car &c)
    {
        std::cout << "Car(" << manufacturer << "): operator= " << c.manufacturer << "\n";

        manufacturer = c.manufacturer;

        return *this;
    }

    Car(std::string manufacturer) : manufacturer{manufacturer}
    {
        std::cout << "Car(" << manufacturer << "): unary constructor \n";
    }

    std::string get_manufacturer() const
    {
        return manufacturer;
    }

    ~Car()
    {
        std::cout << "Car(" << manufacturer << "):"
                  << " destructor \n";
    }

    friend std::ostream &operator<<(std::ostream &stream, const Car &c)
    {
        stream << "<Car manufacturer: " << c.get_manufacturer() << ">";
        return stream;
    }
};

int main()
{
    Vector v{1.5, 1.6, 1.7};                             // Vector<double>
    Vector v2{Car("Mazda"), Car("Ford"), Car("Suzuki")}; // Vector<Car> v2
    std::pair p{1.5, 2.3};                               // std::pair<double, double> p

    std::cout << v << "\n";
    std::cout << v2 << "\n";
}