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
    vector<int> v1;
    v1.resize(10);
    srand(time(0));
    for_each(v1.begin(), v1.end(), [](int& val) -> void {
        val = rand() & 0x1;
    });
    print_vector(v1);

    cout << accumulate(v1.begin(), v1.end(), 0) << endl;
}