#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1;
    s1 = "hello, world";

    string s2(s1);

    string s3;
    s3 = 'x';

    string s4;

    ////////////////////////////////////////////

    s4 += "one";

    s4 += '\t';

    s4 += s3;

    s4.append("\t");

    s4.append(s3);

    s4.append("\t");

    s4.append("two three", 3);

    s4.append("\t");

    s4.append(s1, 7, 5);

    cout << s4 << endl;
}