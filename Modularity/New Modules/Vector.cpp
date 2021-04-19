module;

export module Vector;

export class Vector
{
public:
    Vector(int s);
    ~Vector();
    double &operator[](int i);
    int getSize();

private:
    double *elems;
    int sz;
};

Vector::Vector(int s) : elems{new double[s]}, sz{s}
{
}

Vector::~Vector()
{
    delete[] elems;
}

double &Vector::operator[](int i)
{
    return elems[i];
}

int Vector::getSize()
{
    return sz;
}