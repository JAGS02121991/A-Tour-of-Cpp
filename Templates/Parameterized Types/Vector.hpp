#include <memory>
#include <iostream>
#include <string>

template <typename T>
class Vector
{
private:
    std::unique_ptr<T[]> elems = nullptr;
    int sz = 0;

public:
    Vector();
    explicit Vector(int size);
    int size() const;
    T &operator[](int i) const;
    ~Vector();

    Vector(Vector<T> &v);
    Vector<T> &operator=(const Vector<T> &v);

    Vector(Vector<T> &&v);
    Vector<T> &operator=(Vector<T> &&v);

    std::string to_string();
};

template <typename T>
Vector<T>::Vector()
{
    std::cout << "Vector: calling default constructor \n";
}

template <typename T>
Vector<T>::Vector(int size) : elems{std::unique_ptr<T[]>{new T[size]}}, sz{size}
{
    std::cout << "Vector(int size): calling unary constructor \n";
}

template <typename T>
Vector<T>::Vector(Vector<T> &v)
{
    std::cout << "Vector(Vector<T> &v): calling copy constructor \n";

    elems = std::unique_ptr<T[]>{new T[v.size()]};
    sz = v.size();

    for (int i = 0; i < v.size(); i++)
        (*this)[i] = v[i];
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &v)
{
    std::cout << "Vector<T>& Vector<T>::operator=(const Vector<T> &v): calling copy assignation \n";

    elems = std::unique_ptr<T[]>{new T[v.size()]};
    sz = v.size();

    for (int i = 0; i < v.size(); i++)
        elems[i] = v[i];

    return *this;
}

template <typename T>
Vector<T>::Vector(Vector<T> &&v)
{
    elems = std::move(v.elems);
    v.elems = nullptr;

    sz = v.sz;
}

template <typename T>
Vector<T> &Vector<T>::operator=(Vector<T> &&v)
{
    elems = std::move(v.elems);
    v.elems = nullptr;

    sz = v.sz;

    return *this;
}

template <typename T>
Vector<T>::~Vector()
{
    if (!elems)
        std::cout << "~Vector: destructor elems = nullptr \n";
    else
        std::cout << "~Vector: destructor \n";
}

template <typename T>
T &Vector<T>::operator[](int i) const
{
    if (i > sz)
        throw std::out_of_range("Vector::operator[]: out of range index");

    return elems[i];
}

template <typename T>
int Vector<T>::size() const
{
    return sz;
}

template <typename T>
std::string Vector<T>::to_string()
{
}

template <typename T>
T *begin(const Vector<T> &x)
{
    return x.size() ? &x[0] : nullptr;
}

template <typename T>
T *end(const Vector<T> &x)
{
    return x.size() ? &x[0] + x.size() : nullptr;
}

template <typename T>
std::ostream &operator<<(std::ostream &stream, const Vector<T> &v)
{
    stream << "<Vector \n";
    int i = 0;
    for (auto &elem : v)
    {
        stream << i << ": " << elem << ",\n";
        i++;
    }

    stream << ">";
    return stream;
}