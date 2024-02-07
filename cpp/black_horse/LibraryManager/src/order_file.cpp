#include "order_file.h"

OrderFile::OrderFile()
{
    ifstream ifs(ORDER_FILE, ios::in);

    if (!ifs.is_open()) {
        cerr << "order文件不存在,退出." << endl;
        ifs.close();
        return;
    }

    string date; // 日期
    string interval; // 时间段
    string stuId; // 学生编号
    string stuName; // 学生姓名
    string roomId; // 机房编号
    string status; // 预约状态

    this->m_size = 0;

    while (
        ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status) {
        string key;
        string value;
        int pos = -1;
        map<string, string> m;

        if ((pos = date.find(":")) != -1) {
            key = date.substr(0, pos);
            value = date.substr(pos + 1, date.size() - pos - 1);
            m.insert(make_pair(key, value));
        }

        pos = interval.find(":");
        if (pos != -1) {
            key = interval.substr(0, pos);
            value = interval.substr(pos + 1, interval.size() - pos - 1);
            m.insert(make_pair(key, value));
        }

        pos = stuId.find(":");
        if (pos != -1) {
            key = stuId.substr(0, pos);
            value = stuId.substr(pos + 1, stuId.size() - pos - 1);
            m.insert(make_pair(key, value));
        }

        pos = stuName.find(":");
        if (pos != -1) {
            key = stuName.substr(0, pos);
            value = stuName.substr(pos + 1, stuName.size() - pos - 1);
            m.insert(make_pair(key, value));
        }

        pos = roomId.find(":");
        if (pos != -1) {
            key = roomId.substr(0, pos);
            value = roomId.substr(pos + 1, roomId.size() - pos - 1);
            m.insert(make_pair(key, value));
        }

        pos = status.find(":");
        if (pos != -1) {
            key = status.substr(0, pos);
            value = status.substr(pos + 1, status.size() - pos - 1);
            m.insert(make_pair(key, value));
        }

        m_order_data.insert(make_pair(m_size, m));
        m_size++;
    }

    ifs.close();
}

void OrderFile::updateOrder()
{
    if (m_size == 0) {
        // cout << "无预约记录." << endl;
        return;
    }

    ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
    for (int i = 0; i < m_size; i++) {
        ofs << "date:" << this->m_order_data[i]["date"] << " ";
        ofs << "interval:" << this->m_order_data[i]["interval"] << " ";
        ofs << "stuId:" << this->m_order_data[i]["stuId"] << " ";
        ofs << "stuName:" << this->m_order_data[i]["stuName"] << " ";
        ofs << "roomId:" << this->m_order_data[i]["roomId"] << " ";
        ofs << "status:" << this->m_order_data[i]["status"] << endl;
    }
    ofs.close();
}