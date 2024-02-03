#pragma once
#include "computer_room.h"
#include "identity.h"
#include <vector>

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