#pragma once
#include "computer_room.h"
#include "global_file.h"
#include "identity.h"
#include "order_file.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class Student : public Identity {
public:
    Student() = default;

    Student(int id, string name, string pwd);

    virtual void oper_menu();

    void apply_order();

    void show_order();

    void show_all_order();

    void cancel_order();

public:
    int m_id;
    vector<ComputerRoom> v_com;
};