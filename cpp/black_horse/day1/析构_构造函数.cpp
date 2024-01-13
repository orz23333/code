#include <iostream>

using namespace std;

class Person {
public:
    Person()
    {
        cout << "构造函数被调用了" << endl;
    }

    ~Person()
    {
        cout << "析构函数被调用了" << endl;
    }
};

int main()
{
    Person p1;
}