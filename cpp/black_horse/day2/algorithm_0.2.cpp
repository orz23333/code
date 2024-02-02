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
    vector<int> v1 = { 1, 2, 3, 4, 1, 3, 4, 4, 5 };

    auto res = adjacent_find(v1.begin(), v1.end());

    if (res == v1.end()) {
        cout << "not found." << endl;
    } else {
        cout << "found." << endl;
        cout << "result is: " << *res << endl;
        cout << "index is: " << res.base() << endl;
    }
}