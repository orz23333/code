#include "student.h"
#include "global_file.h"
#include <fstream>
#include <iostream>
using namespace std;

Student::Student(int id, string name, string pwd)
{
    m_id = id;
    m_name = name;
    m_password = pwd;

    ifstream ifs(COMPUTER_FILE, ios::in);

    ComputerRoom com_room;
    while (ifs >> com_room.m_com_id && ifs >> com_room.m_max_capatity) {
        v_com.push_back(com_room);
    }

    ifs.close();
}

void Student::oper_menu()
{
    cout << "欢迎学生代表：" << m_name << "登录！" << endl;
    cout << "\t\t ----------------------------------\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t|          1.申请预约              |\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t|          2.查看我的预约          |\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t|          3.查看所有预约          |\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t|          4.取消预约              |\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t|          0.注销登录              |\n";
    cout << "\t\t|                                  |\n";
    cout << "\t\t ----------------------------------\n";
    cout << "请选择您的操作： " << endl;
}

void Student::apply_order()
{
}

void Student::show_order()
{
}

void Student::show_all_order()
{
}

void Student::cancel_order()
{
}