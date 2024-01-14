#include "my_vector.h"

int main()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
    }

    for (int i = 0; i < v1.size(); i++) {
        cout << v1.at(i) << "\t";
    }
    cout << endl;

    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << "\t";
    }
    cout << endl;

    cout << "first elem: " << v1.front() << endl;
    cout << "last elem: " << v1.back() << endl;
}