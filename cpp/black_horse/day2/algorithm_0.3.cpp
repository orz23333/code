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
    v1.reserve(10);
    for (int i = 0; i < 10; i++) {
        v1.push_back(i + 1);
    }

    srand(time(0));

    for (int i = 0; i < 5; i++) {
        random_shuffle(v1.begin(), v1.end());
        print_vector(v1);
    }
}