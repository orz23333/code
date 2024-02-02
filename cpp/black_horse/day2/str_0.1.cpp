#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class GreaterFive {
public:
    bool operator()(int v2)
    {
        return v2 > 5;
    }
};

int main()
{
    vector<int> v1;

    for (int i = 0; i < 10; i++) {
        v1.push_back(i + 1);
    }

    vector<int>::iterator res = find_if(v1.begin(), v1.end(), GreaterFive());

    if (res != v1.end()) {
        cout << "found, result is: " << *res << endl;
    } else {
        cout << "not found." << endl;
    }
}