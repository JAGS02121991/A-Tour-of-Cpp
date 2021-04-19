// Interface
class Vector
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