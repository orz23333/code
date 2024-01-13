#include <iostream>

using namespace std;

class Student {
private:
    string name;
    int age;

public:
    void set_name(string name)
    {
        this->name = name;
    }

    void set_age(int age)
    {
        this->age = age;
    }

    void print()
    {
        cout << "name: " << this->name << "\n"
             << "age: " << this->age << endl;
    }
};

int main()
{
    Student s1;
    s1.set_name("gls");
    s1.set_age(27);
    s1.print();
}