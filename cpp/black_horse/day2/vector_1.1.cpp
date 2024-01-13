#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

public:
    string name;
    int age;
};

void print_person(Person p)
{
    cout << "name: " << p.name << '\t'
         << "age: " << p.age << endl;
}

void print_person2(Person* p)
{
    cout << "name: " << p->name << '\t'
         << "age: " << p->age << endl;
}

void person_case1()
{
    Person p1("a", 1);
    Person p2("b", 2);
    Person p3("c", 3);
    Person p4("d", 4);
    Person p5("e", 5);

    vector<Person> v;
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    for_each(v.begin(), v.end(), print_person);
}

void person_case2()
{
    Person p1("a", 1);
    Person p2("b", 2);
    Person p3("c", 3);
    Person p4("d", 4);
    Person p5("e", 5);

    vector<Person*> v;
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

    for_each(v.begin(), v.end(), print_person2);
}

int main()
{
    // person_case1();
    person_case2();
}