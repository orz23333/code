#include <iostream>

using namespace std;

class Person {
private:
    int a;
    int b;
    int c;

public:
    Person()
    {
        cout << "默认构造" << endl;
    }

    Person(int a, int b, int c)
        : a(a)
        , b(b)
        , c(c) {};

    void print()
    {
        cout << a << '\n'
             << b << '\n'
             << c << '\n'
             << endl;
    }
};

int main()
{
    Person p1(1, 2, 3);
    p1.print();
}