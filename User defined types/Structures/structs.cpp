#include <iostream>

using namespace std;

struct Vector {
    int size;
    double* elems; // pointer to elems
};

void vector_init(Vector& v, int size) {
    cout << "Creating Vector\n";
    v.elems = new double[size];
    v.size = size;
}

void vector_destroy(Vector* v) {
    cout << "Destroying Vector\n";
    delete v->elems;
} 

double sum(Vector& v) {
    double sum = 0;

    for (int i = 0; i < v.size; i++) {
        sum += v.elems[i];
    }

    return sum;
}

void read_and_sum(int size) {
    Vector v;
    vector_init(v, size);

    for (int i = 0; i < size; i++) {
        cin >> v.elems[i];
    }

    cout << "Sum of elems is: " << sum(v) << "\n";

    vector_destroy(&v);
}

int main() {
    int size;
    cin >> size;
    read_and_sum(size);
}