#include <iostream>

using namespace std;

class Vector
{
public:
    Vector(int size) : elems{new double[size]}, size{size}
    {
        cout << "Constructing Vector \n";
    }

    ~Vector()
    {
        cout << "Destroying Vector \n";
        delete[] elems;
    }

    double &operator[](int i) { return elems[i]; }

    int get_size() { return size; }

    double get_sum()
    {
        double sum{0};

        for (int i = 0; i < size; i++)
            sum += elems[i];

        return sum;
    }

private:
    double *elems;
    int size;
};

void read_and_sum(int size)
{
    Vector v(size);

    for (int i = 0; i < v.get_size(); i++)
        cin >> v[i];

    cout << "Sum of elems is: " << v.get_sum() << "\n";
}

int main()
{
    int size;
    cin >> size;
    read_and_sum(size);
}