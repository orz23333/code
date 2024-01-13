#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void print_val(int val)
{
    cout << val << endl;
}

void iterator_method1(vector<int> v)
{
    vector<int>::iterator cur = v.begin();
    vector<int>::iterator end = v.end();
    while (cur < end) {
        print_val(*cur);
        cur++;
    }
}

void iterator_method2(vector<int> v)
{
    for (vector<int>::iterator cur = v.begin(); cur < v.end(); cur++) {
        print_val(*cur);
    }
}

void iterator_method3(vector<int> v)
{
    for_each(v.begin(), v.end(), print_val);
}

int main()
{
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    // iterator_method1(v);
    // iterator_method2(v);
    iterator_method3(v);
}
