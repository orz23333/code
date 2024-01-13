#include <iostream>

using namespace std;

class Person {
private:
    static int a;

public:
    static int b;
};

int Person::b = 3;
int Person::a = 1;

int main()
{
    Person p1;
    cout << p1.b << endl;

    p1.b = 2;
    cout << p1.b << endl;

    cout << Person::b << endl;

    Person p2;
    cout << p2.b << endl;
}