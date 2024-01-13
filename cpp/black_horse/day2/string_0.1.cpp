#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1;
    cout << s1 << endl;

    const char* c_string = "hello, world";
    string s2(c_string);
    cout << s2 << endl;

    string s3(s2);
    cout << s3 << endl;

    string s4(10, 's');
    cout << s4 << endl;
}