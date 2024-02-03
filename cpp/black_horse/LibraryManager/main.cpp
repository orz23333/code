#include "global_file.h"
#include "identity.h"
#include "manager.h"
#include "student.h"
#include "teacher.h"
#include <fstream>
#include <iostream>

void student_menu(Identity*& student)
{
    while (true) {
        student->oper_menu();

        Student* stu = (Student*)student;

        int select = 0;

        cin >> select;

        switch (select) {
        case 1:
            stu->apply_order();
            break;
        case 2:
            stu->show_order();
            break;

        case 3:
            stu->show_all_order();
            break;

        case 4:
            stu->cancel_order();
            break;

        default:
            delete student;
            cout << "注销登录成功." << endl;
            system("`read -n 1");
            system("clear");
            return;
        }
    }
}

void login_in(string file_name, int type)
{
    ifstream ifs(file_name, ios::in);

    if (!ifs.is_open()) {
        cout << "文件不存在!" << endl;
        ifs.close();
        return;
    }

    int id = 0;
    string name;
    string pwd;
    Identity* person = NULL;

    if (type == 1) {
        cout << "请输入学号: ";
        cin >> id;
    } else if (type == 2) {
        cout << "请输入职工号: ";
        cin >> id;
    }

    cout << "请输入名字: ";
    cin >> name;

    cout << "请输入密码: ";
    cin >> pwd;

    if (type == 1) {
        int read_id;
        string read_name;
        string read_pwd;

        while (ifs >> read_id && ifs >> read_name && ifs >> read_pwd) {
            if (read_id == id && read_name == name && read_pwd == pwd) {
                cout << name << "登录成功" << endl;
                system("clear");
                person = new Student(id, name, pwd);
                student_menu(person);
                return;
            }
        }
    }

    cout << "验证登录失败." << endl;

    return;
}

int main(int, char**)
{
    std::cout << "Hello, from LibraryManager!\n";

    int select = 0;

    while (true) {
        cout << "======================  欢迎来到传智播客机房预约系统  ====================="
             << endl;
        cout << endl
             << "请输入您的身份" << endl;
        cout << "\t\t -------------------------------\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          1.学生代表           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          2.老    师           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          3.管 理 员           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          0.退    出           |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t -------------------------------\n";
        cout << "输入您的选择: ";

        cin >> select;

        switch (select) {
        case 1:
            login_in(STUDENT_FILE, 1);
            break;

        case 2:
            login_in(TEACHER_FILE, 2);
            break;

        case 3:
            login_in(MANAGER_FILE, 3);
            break;

        case 0:
            cout << "欢迎下一次使用." << endl;
            return 0;

        default:
            cout << "输入有误，请重新输入!" << endl;
            break;
        }
    }
}
