#include <iostream>
#include <vector>
#include <thread>

using namespace std;

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
        std::cout << "Vector: destroying elems \n";
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

void heart_beat()
{
}

vector<int> init(int size, vector<thread> &threads, vector<Vector> &vectors)
{
    thread t1{heart_beat};
    threads.push_back(move(t1));

    Vector v1{1, 2, 3, 4, 5};
    vectors.push_back(move(v1));

    vector<int> integers(size);

    for (int i = 0; i < integers.size(); i++)
        integers[i] = 666;

    return move(integers);
}

int main()
{
    vector<thread> threads;

    vector<Vector> vectors;

    vector<int> output = init(10, threads, vectors);

    for (int elem : output)
        cout << to_string(elem) << "\n";
}