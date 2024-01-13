#include <iostream>

using namespace std;

class Cal1 {
public:
    int a;
    int b;

public:
    int getResult(string oper)
    {
        if (oper == "+") {
            return a + b;
        } else if (oper == "-") {
            return a - b;
        } else if (oper == "*") {
            return a * b;
        } else {
            return a + b;
        }
    }
};

void test01()
{
    Cal1 cal1;
    cal1.a = 2;
    cal1.b = 3;
    cout << cal1.getResult("+") << endl;
    cout << cal1.getResult("-") << endl;
    cout << cal1.getResult("*") << endl;
}

class AbsCal {
public:
    int a;
    int b;

public:
    virtual int getResult()
    {
        return 0;
    }
};

class AddCal : public AbsCal {
public:
    int getResult()
    {
        return a + b;
    }
};

class SubCal : public AbsCal {
public:
    int getResult()
    {
        return a - b;
    }
};

void test02()
{
    AddCal a1;
    a1.a = 2;
    a1.b = 3;
    cout << a1.getResult() << endl;

    SubCal s1;
    s1.a = 2;
    s1.b = 3;
    cout << s1.getResult() << endl;
}

int main()
{
    test01();
    cout << "-----------------" << endl;
    test02();
}