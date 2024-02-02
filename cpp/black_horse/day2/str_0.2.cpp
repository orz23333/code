#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class MyCompare {
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

int main()
{
    vector<int> v1;
    srand(time(0));
    for (int i = 0; i < 10; i++) {
        v1.push_back(rand() & 0xFF);
    }

    sort(v1.begin(), v1.end(), MyCompare());

    for (vector<int>::iterator it = v1.begin(); it < v1.end(); it++) {
        cout << *it << "\t";
    }
    cout << endl;
}