#include <iostream>

using namespace std;

class Animal {
public:
    Animal()
    {
        cout << "animal 构造函数调用" << endl;
    }

    // virtual ~Animal() = 0;

    // virtual ~Animal()
    // {
    //     cout << "animal 析构函数调用" << endl;
    // }
};

// Animal::~Animal() {};

class Cat : public Animal {
public:
    string* name;

public:
    Cat() {};

    Cat(string name)
    {
        cout << "cat 构造函数调用" << endl;
        this->name = new string(name);
    }

    ~Cat()
    {
        cout << "cat 析构函数调用" << endl;
        if (name != NULL) {
            delete name;
        }
        name = NULL;
    }
};

int main()
{
    Animal cat = Cat("mimi");
    // Animal* cat = new Cat("mimi");
    // delete cat;
}