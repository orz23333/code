#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    ifstream input;
    input.open("text.txt", ios::in);

    if (!input.is_open()) {
        cout << "读取失败" << endl;
    }

    // 第一种方式
    // char buffer[1024] = { 0 };
    // while (input >> buffer) {
    //     cout << buffer << endl;
    // }

    // 第二种方式
    // char buffer[1024] = { 0 };
    // while (input.getline(buffer, sizeof(buffer))) {
    //     cout << buffer << endl;
    // }

    // 第三种方式
    // string buffer;
    // while (getline(input, buffer)) {
    //     cout << buffer << endl;
    // }

    // 第四种方式
    char buffer;
    while ((buffer = input.get()) != EOF) {
        cout << buffer;
    }

    input.close();
}