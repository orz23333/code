#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1 = "abc";
    string s2 = "def";

    s1.insert(s1.size(), "sss");
    cout << s1 << endl;

    s1.insert(s1.size(), s2);
    cout << s1 << endl;

    s1.insert(s1.size(), 10, 'a');
    cout << s1 << endl;

    s1.erase(0, 3);
    cout << s1 << endl;
}