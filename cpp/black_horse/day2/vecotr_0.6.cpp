#include "my_vector.h"

void test1()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i + 1);
    }

    vector<int> v2;
    for (int i = 0; i < 10; i++) {
        v2.push_back(i + 10);
    }

    print_vec(v1);
    print_vec(v2);

    cout << "swap" << endl;

    v1.swap(v2);

    print_vec(v1);
    print_vec(v2);
}

void test2()
{
    vector<int> v;
    for (int i = 0; i < 100000; i++) {
        v.push_back(i);
    }

    cout << "v的容量为：" << v.capacity() << endl;
    cout << "v的大小为：" << v.size() << endl;

    v.resize(3);

    cout << "v的容量为：" << v.capacity() << endl;
    cout << "v的大小为：" << v.size() << endl;

    // 收缩内存
    // vector<int>(v).swap(v); // 匿名对象
    v.shrink_to_fit();  // 调用api收缩内存

    cout << "v的容量为：" << v.capacity() << endl;
    cout << "v的大小为：" << v.size() << endl;
}

int main()
{
    // test1();
    test2();
}