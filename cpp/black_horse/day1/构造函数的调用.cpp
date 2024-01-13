#include <iostream>

using namespace std;

class Person {
public:
    int age;

    Person()
    {
        this->age = 1;
    }

    Person(int age)
    {
        this->age = age;
    }

    Person(const Person& p)
    {
        this->age = p.age;
    }
};

void m1()
{
    Person p1;
    cout << p1.age <<endl;
}

void m2()
{
    Person p1(10);
    cout << p1.age <<endl;
}

void m3()
{
    Person p1 = 3;
    Person p2 = p1;
    cout << p1.age <<endl;
    cout << p2.age <<endl;
}

void m4()
{
    Person p1 = Person(4);
    cout << p1.age <<endl;
}

void m5()
{
    Person p0 = 0;
    cout << p0.age <<endl;
    Person p1 = Person(p0);
    cout << p1.age <<endl;
}

int main()
{
    /**
     * 总结：3种调用方法
     * 1、括号法()
     * 2、显式调用person(*)
     * 3、隐式调用p1 = *
     * 
    */
    m5();
}