#include <iostream>
#include <map>

using namespace std;

void print_map(map<int, int>& m)
{
    cout << &m << endl;
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
        cout << "first: " << it->first << " second: " << it->second << endl;
    }
}

int main()
{
    map<int, int> m1;
    m1.insert(pair<int, int>(1, 2));
    m1.insert(pair<int, int>(1, 3));
    m1.insert(pair<int, int>(2, 3));
    m1.insert(pair<int, int>(3, 4));

    map<int, int>::iterator res = m1.find(1);
    if (res != m1.end()) {
        cout << "found, result is: " << (*res).second << endl;
    } else {
        cout << "not found." << endl;
    }

    print_map(m1);
}