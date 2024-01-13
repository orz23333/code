#include <fstream>
#include <iostream>

using namespace std;

class Person {
public:
    char name[64];
    int age;
};

int main()
{
    Person p = { "gls", 27 };
    ofstream output("person.txt", ios::out | ios::binary);
    output.write((const char*)&p, sizeof(p));
    output.close();

    Person p1;
    ifstream input("person.txt", ios::in | ios::binary);
    if (!input.is_open()) {
        cout << "error" << endl;
        return -1;
    }
    input.read((char*)&p1, sizeof(p1));
    cout << p1.name << endl;
    cout << p1.age << endl;
    input.close();
}