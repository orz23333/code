#include "my_vector.h"

void test01()
{
    vector<int> v;

    // v.reserve(100000);   // 1次
    v.reserve(10000);       // 5次

    int* start = NULL;
    int num = 0;

    for (int i = 0; i < 100000; i++) {
        v.push_back(i);
        if (start != &v[0]) {
            start = &v[0];
            num++;
        }
    }

    cout << "扩容次数: " << num << endl;
}

int main()
{

    test01();

    return 0;
}