#include <iostream>

using namespace std;

class A {
public:
    int a;
};

class B1 : virtual public A { };
class B2 : virtual public A { };

class C : public B1, public B2 { };

int main()
{
    C c;
    // c.B1::a = 1;
    // c.B2::a = 2;
    c.a = 3;

    cout << c.B1::a << endl;
    cout << c.B2::a << endl;
}