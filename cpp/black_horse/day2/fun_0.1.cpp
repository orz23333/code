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
    vector<int> v1;

    srand(time(0));
    for (int i = 0; i < 10; i++) {
        v1.push_back(rand() & 0xff);
    }
    print_vector(v1);

    sort(v1.begin(), v1.end(), greater<int>());
    print_vector(v1);

    sort(v1.begin(), v1.end(), less_equal<int>());
    print_vector(v1);
}