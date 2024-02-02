#include <iostream>
#include <set>

using namespace std;

class MyCompare {
public:
    bool operator()(int i1, int i2)
    {
        return i1 > i2;
    }
};

int main()
{
    set<int, MyCompare> s1;
    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(40);

    for (set<int, MyCompare>::iterator it = s1.begin(); it != s1.end(); it++) {
        cout << *it << '\t';
    }
    cout << endl;

    set<int, greater<int>> s2;
    s2.insert(10);
    s2.insert(30);
    s2.insert(20);
    s2.insert(40);

    for (set<int, greater<int>>::iterator it = s2.begin(); it != s2.end(); it++) {
        cout << *it << '\t';
    }
    cout << endl;
}