#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
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
    srand(time(0));

    vector<int> v1;
    v1.resize(10);
    for_each(v1.begin(), v1.end(), [](int& val) -> void {
        val = rand() & 0xF;
    });
    sort(v1.begin(), v1.end());
    print_vector(v1);

    vector<int> v2;
    v2.resize(10);
    for_each(v2.begin(), v2.end(), [](int& val) -> void {
        val = rand() & 0xF;
    });
    sort(v2.begin(), v2.end());
    print_vector(v2);

    vector<int> v3;
    v3.resize(min(v1.size(), v2.size()));
    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    print_vector(v3);
}