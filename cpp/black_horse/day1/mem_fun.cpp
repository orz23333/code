#include <iostream>

using namespace std;

int* func_stack();
int* func_heap();

int main()
{
    int* p = NULL;

    // p = func_stack();
    // cout << *p << endl;

    p = func_heap();
    cout << *p << endl;

    delete p;
    cout << *p << endl;
}

int* func_stack()
{
    int i = 10;
    return &i;
}

int* func_heap()
{
    int* i = new int(10);
    return i;
}