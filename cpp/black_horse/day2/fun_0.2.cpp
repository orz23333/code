#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void print_vector(vector<T>& v1)
{
    for (auto it = v1.begin(); it < v1.end(); it++) {
        cout << *it << '\t';
    }
    cout << endl;
}

int main()
{
    vector<bool> v1 = { 1, 0, 1, 0, 1 };
    print_vector(v1);

    vector<bool> v2;
    v2.resize(v1.size());
    print_vector(v2);

    transform(v1.begin(), v1.end(), v2.begin(), logical_not<bool>());
    print_vector(v2);
}