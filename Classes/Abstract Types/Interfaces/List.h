#include <list>
#include "Container.h"

class List : public Container
{
private:
    std::list<double> *elems;

public:
    List(int s);
    List(List &&list);
    List(std::initializer_list<double> list);
    ~List() override;
    double &operator[](int i) override;
    double &operator[](int i) const override;
    int get_index(double) override;
    int get_size() const override;
    std::string to_string() const override;
};