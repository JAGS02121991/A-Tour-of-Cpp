#include "Container.h"
#include <iostream>
#include <string>

class Vector : public Container
{
public:
    Vector(int s);
    Vector(std::initializer_list<double> list);
    Vector(Vector &&v);
    ~Vector();
    double &operator[](int i) override;
    double &operator[](int i) const override;
    int get_index(double) override;
    int get_size() const override;
    std::string to_string() const override;

private:
    double *elems;
    int size;
};