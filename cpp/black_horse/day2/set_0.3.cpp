#include <iostream>
#include <set>

using namespace std;

void print_set(set<int>& s)
{
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << '\t';
    }
    cout << endl;
}

int main()
{
    set<int> s;

    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);

    auto res = s.find(20);
    if (res != s.end()) {
        cout << "找到了" << endl;
    } else {
        cout << "没有找到" << endl;
    }

    int count = s.count(40);
    cout << count << endl;
}