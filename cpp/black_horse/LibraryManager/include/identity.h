#pragma once
#include <string>
using namespace std;

class Identity {
public:
    virtual void oper_menu() = 0;

public:
    string m_name;
    string m_password;
};