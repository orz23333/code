#pragma once
#include "global_file.h"
#include <fstream>
#include <iostream>
#include <map>
#include <string>
using namespace std;

class OrderFile {
public:
    OrderFile();

    void updateOrder();

    map<int, map<string, string>> m_order_data;

    int m_size;
};