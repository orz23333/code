#pragma once
#include "speaker.h"
#include <algorithm>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

using namespace std;

class SpeechManager {

public:
    SpeechManager();

    ~SpeechManager() {};

    void showMenu();

    void exitSystem();

    void initSpeech();

    void createSpeaker();

    void showSpeaker();

    void startSpeech();

    void speechDraw();

    void speechContest();

    void showScore();

    void saveRecord();

    void loadRecord();

    void showRecord();

    void clearRecord();

public:
    // 第一轮选手编号
    vector<int> round1_speaker;

    // 第二轮选手编号
    vector<int> round2_speaker;

    // 胜者编号
    vector<int> victory;

    // 选手编号对照表
    map<int, Speaker> speakers;

    // 比赛轮次编号
    int round_num;

    bool file_empty;

    map<int, vector<string>> records;
};