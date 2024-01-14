#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print_vec(vector<int> &v)
{
    cout << &v << ": ";

    for (vector<int>::iterator cur = v.begin(); cur < v.end(); cur++) {
        cout << *cur << "\t";
    }
    cout << endl;
}

int main()
{
    vector<int> v1(10, 1);
    print_vec(v1);

    // 方式一
    vector<int> v2 = v1;
    print_vec(v2);

    // 方式二
    vector<int> v3(v1.begin(), v1.end());
    print_vec(v3);

    // 方式三
    vector<int> v4;
    v4.assign(10, 2);
    print_vec(v4);

    // 方式四
    vector<int> v5;
    v5.assign(v4.begin(), v4.end());
    print_vec(v5);
}