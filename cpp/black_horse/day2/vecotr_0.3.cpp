#include "my_vector.h"

int main()
{
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i + 1);
    }

    print_vec(v);

    if (v.empty()) {
        cout << "empty" << endl;
    } else {
        cout << "size: " << v.size() << endl;
        cout << "capacity: " << v.capacity() << endl;
    }

    v.resize(12, 100);
    print_vec(v);

    v.resize(5);
    print_vec(v);
}