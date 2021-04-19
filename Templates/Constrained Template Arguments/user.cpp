#include "Vector.hpp"
#include <string>

class Car
{
private:
    std::string manufacturer = "Ford";

public:
    Car()
    {
        std::cout << "Car(" << manufacturer << "): default constructor \n";
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

Vector<Vector<Car>> create_cars(int brands_quantity, int cars_quantity)
{
    Vector<Vector<Car>> brands = Vector<Vector<Car>>(brands_quantity);
    for (int i = 0; i < brands.size(); i++)
    {
        brands[i] = Vector<Car>(cars_quantity);
        for (int j = 0; j < brands[i].size(); j++)
            brands[i][j] = Car("Brand: " + std::to_string(i) + ", Car: " + std::to_string(j));
    }

    return std::move(brands);
}

int main()
{

    std::unique_ptr<Car[]> cars = std::unique_ptr<Car[]>(new Car[1]);
    std::cout << "------------- Show case unique_ptr ------------------\n";
    std::unique_ptr<Car[]> cars2 = std::unique_ptr<Car[]>(new Car[2]);
    std::cout << "------------- Show case unique_ptr ------------------\n";
    cars = std::move(cars2);
    //cars = std::unique_ptr<Car[]>(new Car[1]); // equivalent to a move since we are dealing with a r-value
    std::cout << "------------- Show case unique_ptr ------------------\n\n\n";

    Vector<Vector<Car>> all_brands = create_cars(2, 2);

    std::cout << all_brands;
}