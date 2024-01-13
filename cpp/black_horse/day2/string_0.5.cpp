#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1 = "abc";

    string s2 = "def";

    int result = s1.compare(s2);

    if (result == 0) {
        cout << "equal" << endl;
    } else if (result < 0) {
        cout << "s1 < s2" << endl;
    } else {
        cout << "s1 > s2" << endl;
    }
}