#include <iostream>

class Vector
{
public:
    Vector(int s);
    Vector(Vector &&v);
    ~Vector();
    double &operator[](int i);
    double &operator[](int i) const;
    int getIndex(double);
    int getSize() const;
    friend std::ostream &operator<<(std::ostream &strm, const Vector &a);

private:
    double *elems;
    int sz;
};