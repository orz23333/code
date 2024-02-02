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

    // auto res = s.insert(10);
    pair<set<int>::iterator, bool> res = s.insert(10);
    if (res.second) {
        cout << "1插入成功" << endl;
    } else {
        cout << "1插入失败" << endl;
    }

    res = s.insert(10);
    if (res.second) {
        cout << "2插入成功" << endl;
    } else {
        cout << "2插入失败" << endl;
    }
    print_set(s);

    multiset<int> ms;

    ms.insert(10);
    ms.insert(10);

    for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}