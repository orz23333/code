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
    deque<int> d1;
    for (int i = 0; i < 10; i++) {
        d1.push_back(i + 1);
    }
    print_deque(d1);

    deque<int> d2(d1.begin(), d1.end());
    print_deque(d2);

    deque<int> d3(d2);
    print_deque(d3);

    deque<int> d4(10, 2);
    print_deque(d4);
}