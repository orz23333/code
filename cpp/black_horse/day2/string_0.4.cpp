#include <iostream>
#include <string>

using namespace std;

void my_find(int pos)
{
    if (pos == -1) {
        cout << "not found!" << endl;
    } else {
        cout << "pos: " << pos << endl;
    }
}

int main()
{
    string s1 = "abcdefg";

    string s2 = "fg";

    my_find(s1.find("de"));

    my_find(s1.find("de", 5));

    my_find(s1.find("abef", 0, 2));

    my_find(s1.find(s2));

    cout << string(s1).replace(3, 1, "sss") << endl;

    cout << string(s1).replace(3, 2, "sss") << endl;

    cout << string(s1).replace(3, 3, "sss") << endl;

    cout << string(s1).replace(3, 5, "sss") << endl;
}