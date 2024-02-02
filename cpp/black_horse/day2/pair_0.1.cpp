#include <iostream>
#include <string>

using namespace std;

int main()
{
    pair<string, int> pair1(string("tom"), 28);
    pair<string, int> pair2 = make_pair(string("jerry"), 27);

    cout << pair1.first << " " << pair1.second << endl;
    cout << pair2.first << " " << pair2.second << endl;
}