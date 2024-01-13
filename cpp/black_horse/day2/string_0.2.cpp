#include <iostream>
#include <string>

using namespace std;

int main()
{
    // operator =
    string s1;
    s1 = "hello, cpp";
    cout << s1 << endl;

    string s2 = s1;
    cout << s2 << endl;

    string s3;
    s3 = 97;
    cout << s3 << endl;

    cout << "-------------------------------" << endl;

    // assign
    string s4;
    s4.assign("hello, c++");
    cout << s4 << endl;

    string s5;
    s5.assign(s4);
    cout << s5 << endl;

    string s6;
    s6.assign("hello, c++", 5);
    cout << s6 << endl;

    string s7;
    s7.assign(10, 's');
    cout << s7 << endl;
}