#include <iostream>

using namespace std;

class Animal {
public:
    string name;

    virtual void speak() { }

    Animal()
    {
        this->name = "animal";
    }

    Animal(string name)
    {
        this->name = name;
    }
};

class Cat : public Animal {
public:
    void speak()
    {
        cout << this->name << "在喵喵叫" << endl;
    }

    Cat()
    {
        this->name = "cat";
    }

    Cat(string name)
    {
        this->name = name;
    }
};

class Dog : public Animal {
public:
    void speak()
    {
        cout << this->name << "在汪汪叫" << endl;
    }

    Dog()
    {
        this->name = "dog";
    }

    Dog(string name)
    {
        this->name = name;
    }
};

void doSpeak(Animal& animal)
{
    animal.speak();
}

int main()
{
    Cat cat("mimi");
    Dog dog("旺财");

    doSpeak(cat);
    doSpeak(dog);
}