#include <iostream>
#include <set>

using namespace std;

void print_set(set<int>& s)
{
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << "\t";
    }

    cout << endl;
}

int main()
{
    set<int> s;
    for (int i = 0; i < 10; i++) {
        s.insert(rand() & 0xFFF);
    }

    print_set(s);
}