#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1 = "hello, cpp";
    cout << s1.substr(7, 3) << endl;

    string s2 = "orz23333@github.com";
    int pos = s2.find("@");
    cout << s2.substr(0, pos) << endl;
}