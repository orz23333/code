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

void print_01(int val)
{
    cout << val << '\t';
}

class MyPrint {
public:
    void operator()(int val)
    {
        cout << val << '\t';
    }
};

int main()
{
    vector<int> v1 = { 1, 3, 2, 5, 4, 9, 8, 7, 0 };

    // 普通函数
    for_each(v1.begin(), v1.end(), print_01);
    cout << endl;

    // 函数对象
    for_each(v1.begin(), v1.end(), MyPrint());
    cout << endl;

    // lambda表达式
    for_each(v1.begin(), v1.end(), [](int val) -> int {
        cout << val << '\t';
    });
    cout << endl;
}