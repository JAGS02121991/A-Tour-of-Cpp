#include <iostream>

class Vector
{
public:
    Vector(int s);
    Vector(std::initializer_list<double> list);
    Vector(Vector &&v);
    ~Vector();
    double &operator[](int i);
    double &operator[](int i) const;
    int getIndex(double);
    int getSize() const;

    void push_back(double elem);

    friend std::ostream &operator<<(std::ostream &strm, const Vector &a);

private:
    double *elems;
    int sz;
};