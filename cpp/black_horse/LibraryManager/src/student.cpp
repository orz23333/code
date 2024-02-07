#include "student.h"

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
<<<<<<< HEAD
=======
    cout << "机房开放时间为周一至周五！" << endl;
    cout << "请输入申请预约的时间：" << endl;
    cout << "1、周一" << endl;
    cout << "2、周二" << endl;
    cout << "3、周三" << endl;
    cout << "4、周四" << endl;
    cout << "5、周五" << endl;

    int date = 0;
    int interval = 0;
    int room = 0;

    while (true) {
        cin >> date;
        if (date >= 1 && date <= 5) {
            break;
        }
        cout << "输入有误，请重新输入." << endl;
    }

    cout << "请输入申请预约的时间段：" << endl;
    cout << "1、上午" << endl;
    cout << "2、下午" << endl;

    while (true) {
        cin >> interval;
        if (interval >= 1 && interval <= 2) {
            break;
        }
        cout << "输入有误，请重新输入." << endl;
    }

    cout << "请选择机房：" << endl;
    cout << "1号机房容量：" << v_com[0].m_max_capatity << endl;
    cout << "2号机房容量：" << v_com[1].m_max_capatity << endl;
    cout << "3号机房容量：" << v_com[2].m_max_capatity << endl;

    while (true) {
        cin >> room;
        if (room >= 1 && room <= 3) {
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }

    cout << "预约成功！审核中" << endl;

    ofstream ofs(ORDER_FILE, ios::app);

    if (!ofs.is_open()) {
        cerr << "order文件不存在,退出." << endl;
        ofs.close();
        return;
    }

    ofs << "date:" << date << " ";
    ofs << "interval:" << interval << " ";
    ofs << "stuId:" << m_id << " ";
    ofs << "stuName:" << m_name << " ";
    ofs << "roomId:" << room << " ";
    ofs << "status:" << IN_REVIEW << endl;

    ofs.close();

    system("read -n 1");
    system("clear");
>>>>>>> 94e6f1c (init)
}

void Student::show_order()
{
<<<<<<< HEAD
=======
    OrderFile of;
    if (of.m_size == 0) {
        cout << "无预约记录" << endl;
        system("pause");
        system("cls");
        return;
    }

    for (int i = 0; i < of.m_size; i++) {
2        int id = atoi(of.m_order_data[i]["stuId"].c_str());
        if (id == this->m_id) {
            cout << "预约日期： 周" << of.m_order_data[i]["date"];
            cout << " 时段：" << (of.m_order_data[i]["interval"] == "1" ? "上午" : "下午");
            cout << " 机房：" << of.m_order_data[i]["roomId"];
            string status = " 状态： "; // 0 取消的预约   1 审核中   2 已预约 -1 预约失败
            if (atoi(of.m_order_data[i]["status"].c_str()) == IN_REVIEW) {
                status += "审核中";
            } else if (atoi(of.m_order_data[i]["status"].c_str()) == BOOKED) {
                status += "预约成功";
            } else if (atoi(of.m_order_data[i]["status"].c_str()) == BOOKED_FAILED) {
                status += "审核未通过，预约失败";
            } else {
                status += "预约已取消";
            }
            cout << status << endl;
        }
    }
>>>>>>> 94e6f1c (init)
}

void Student::show_all_order()
{
}

void Student::cancel_order()
{
}