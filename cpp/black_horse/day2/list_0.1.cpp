#include <iostream>
#include <list>

using namespace std;

class Person {
public:
    Person() = default;
    Person(string name, int age, int height)
        : name(name)
        , age(age)
        , height(height)
    {
    }

public:
    string name;
    int age;
    int height;
};

bool comparePerson(Person& p1, Person& p2)
{
    if (p1.age == p2.age) {
        return p1.height > p2.height;
    } else {
        return p1.age < p2.age;
    }
}

int main()
{
    list<Person> L;

    Person p1("刘备", 35, 175);
    Person p2("曹操", 45, 180);
    Person p3("孙权", 40, 170);
    Person p4("赵云", 25, 190);
    Person p5("张飞", 35, 160);
    Person p6("关羽", 35, 200);

    L.push_back(p1);
    L.push_back(p2);
    L.push_back(p3);
    L.push_back(p4);
    L.push_back(p5);
    L.push_back(p6);

    for (list<Person>::iterator it = L.begin(); it != L.end(); it++) {
        cout << "姓名： " << it->name << " 年龄： " << it->age
             << " 身高： " << it->height << endl;
    }

    cout << "---------------------------------" << endl;
    L.sort(comparePerson); // 排序

    for (list<Person>::iterator it = L.begin(); it != L.end(); it++) {
        cout << "姓名： " << it->name << " 年龄： " << it->age
             << " 身高： " << it->height << endl;
    }
}