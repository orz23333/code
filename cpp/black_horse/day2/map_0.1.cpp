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
    // m1.insert(1, 1);
    m1.insert(pair<int, int>(2, 2));
    m1.insert(pair<int, int>(3, 3));

    print_map(m1);
}