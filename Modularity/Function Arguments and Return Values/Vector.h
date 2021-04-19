class Vector
{
public:
    Vector(int s);
    ~Vector();
    double &operator[](int i);
    double &operator[](int i) const;
    int getIndex(double);
    int getSize() const;

private:
    double *elems;
    int sz;
};