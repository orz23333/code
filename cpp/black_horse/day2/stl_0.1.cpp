#include <iostream>

using namespace std;

class MyAdd {
public:
    int operator()(int v1, int v2)
    {
        return v1 + v2;
    }
};

class MyPrint {
public:
    void operator()(string test)
    {
        cout << "myprint: " << test << endl;
        count++;
    }

public:
    int count = 0;
};

void test01()
{
    int v1 = 10;
    int v2 = 21;
    MyAdd myadd;
    cout << myadd(v1, v2) << endl;
}

void test02()
{
    MyPrint my_print;
    cout << my_print.count << endl;

    my_print(string("1"));
    my_print(string("2"));
    my_print(string("3"));

    cout << my_print.count << endl;
}

void func1(MyPrint& my, string str)
{
    my(str);
}

void test03()
{
    string s1("hello, world");
    MyPrint my;
    func1(my, s1);
}

int main()
{
    // test01();
    test02();
    // test03();
}