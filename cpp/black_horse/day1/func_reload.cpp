#include <iostream>

using namespace std;

void func(int& c)
{
    cout << "普通函数调用" << endl;
}

void func(int c)
{
    cout << "引用调用" << endl;
}

void func2(int arg1)
{
    cout << "非默认参数函数调用" << endl;
}

void func2(int arg1, int arg2 = 10)
{
    cout << "默认参数函数调用" << endl;
}

int main()
{
    int i = 1;

    func2(i);
}