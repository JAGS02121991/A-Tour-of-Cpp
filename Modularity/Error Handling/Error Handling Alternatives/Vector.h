// Interface
class Vector
{
public:
    Vector(int s);
    ~Vector();
    double &operator[](int i);
    int getIndex(double);
    int getSize();

private:
    double *elems;
    int sz;
};