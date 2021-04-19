#include <vector>
#include <iostream>

using namespace std;
  
void add_safe(const vector<int>& v, int ammount) {
  for (auto elem = v.begin(); elem != v.end(); ++elem) {
        // *elem += ammount; // Cannot modify the value
    }
}

void add(vector<int>& v, int ammount) {
    for (auto& elem : v) {
        elem += ammount;
    }
}


int main() {
    // Used typically when we don´t want to modify an argument but still we don´t want the cost of copying it, we use a const reference
    vector<int> vect;

    vect.push_back(13);
    vect.push_back(14);
    vect.push_back(15);

    add(vect, 10);

    cout << "vect" << "\n";
    for (auto elem : vect) {
        cout << elem << "\n";
    }
}