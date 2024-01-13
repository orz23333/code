#include <fstream>

using namespace std;

void test01()
{
    fstream output;
    output.open("text.txt", ios::out);

    output << "gls" << endl;
    output << 27 << endl;
    output << "good" << endl;

    output.close();
}

int main()
{

    test01();

    return 0;
}