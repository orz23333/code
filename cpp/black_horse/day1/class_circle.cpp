#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

class Circle {
public:
    int r;
    double calculate()
    {
        return 2 * M_PI * r;
    }
};

int main()
{
    Circle c1;
    c1.r = 2;

    cout << "圆的周长为：" << c1.calculate() << endl;
    return 0;
}