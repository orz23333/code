#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1 = "abcdefg";

    for (int i = 0; i < s1.size(); i++) {
        cout << s1[i] << "\t";
    }

    cout << "\n";

    for (int i = 0; i < s1.size(); i++) {
        cout << s1.at(i) << "\t";
    }

    cout << endl;
}