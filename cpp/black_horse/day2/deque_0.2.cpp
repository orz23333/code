#include <algorithm>
#include <deque>
#include <iostream>

using namespace std;

void print_deque(const deque<int>& d)
{
    for (deque<int>::const_iterator it = d.begin(); it < d.end(); it++) {
        cout << *it << "\t";
    }
    cout << endl;
}

int main()
{
    deque<int> d;
    for (int i = 0; i < 10; i++) {
        d.push_front(random() & 0xFFF);
    }
    print_deque(d);

    sort(d.begin(), d.end());
    print_deque(d);
}