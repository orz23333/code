#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void print_vec(vector<int> &v)
{
    cout << &v << ": ";

    for (vector<int>::iterator cur = v.begin(); cur < v.end(); cur++) {
        cout << *cur << "\t";
    }
    cout << endl;
}