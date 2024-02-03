#include "speechManager.h"

SpeechManager::SpeechManager()
{
    this->initSpeech();

    this->createSpeaker();

    this->loadRecord();
}

void SpeechManager::showMenu()
{
    cout << "********************************************" << endl;
    cout << "*************  欢迎参加演讲比赛 ************" << endl;
    cout << "*************  1.开始演讲比赛  *************" << endl;
    cout << "*************  2.查看往届记录  *************" << endl;
    cout << "*************  3.清空比赛记录  *************" << endl;
    cout << "*************  4.显示操作菜单  *************" << endl;
    cout << "*************  0.退出比赛程序  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

void SpeechManager::exitSystem()
{
    cout << "欢迎下次使用." << endl;
    exit(0);
}

void SpeechManager::initSpeech()
{
    round_num = 1;
    round1_speaker.clear();
    round2_speaker.clear();
    victory.clear();
    records.clear();
}

void SpeechManager::createSpeaker()
{
    string speaker_seed = "ABCDEFGHIJKL";

    for (int i = 0; i < speaker_seed.size(); i++) {
        string name = "选手";
        Speaker sp;
        sp.m_name = name + speaker_seed[i];
        sp.m_score[0] = 0;
        sp.m_score[1] = 0;

        int speaker_id = i + 10001;
        this->round1_speaker.push_back(speaker_id);
        this->speakers.insert(make_pair(speaker_id, sp));
    }
}

void SpeechManager::showSpeaker()
{
    for_each(this->speakers.begin(), this->speakers.end(), [](auto& it) -> void {
        cout << "编号: " << it.first << '\t';
        cout << "姓名: " << it.second.m_name << '\t';
        cout << "成绩: " << it.second.m_score[0] << '\t';
        cout << endl;
    });
}

void SpeechManager::startSpeech()
{
    // 1 第一轮
    // 分组
    this->speechDraw();
    // 比赛
    this->speechContest();
    // 显示晋级结果
    this->showScore();

    // 2 第二轮
    round_num++;
    // 分组
    this->speechDraw();
    // 比赛
    this->speechContest();
    // 显示最终结果
    this->showScore();
    // 保存结果
    this->saveRecord();

    // 重置
    this->initSpeech();
    this->createSpeaker();
    this->loadRecord();
}

void SpeechManager::speechDraw()
{
    cout << "第" << this->round_num << "轮比赛正在抽签" << endl;
    cout << "---------------------" << endl;
    cout << "抽签后演讲顺序如下：" << endl;

    vector<int>& cur_speaker = this->round_num == 1 ? round1_speaker : round2_speaker;

    random_shuffle(cur_speaker.begin(), cur_speaker.end());

    for_each(cur_speaker.begin(), cur_speaker.end(), [](int& it) -> void {
        cout << it << "\t";
    });
    cout << endl;
    cout << "---------------------" << endl;
    cout << endl;
}

void SpeechManager::speechContest()
{
    vector<int> cur_speaker = round_num == 1 ? round1_speaker : round2_speaker;

    multimap<double, int, greater<double>> group_score;

    int num = 0;

    for (vector<int>::iterator it = cur_speaker.begin(); it < cur_speaker.end(); it++) {
        num++;
        deque<double> cur_score;
        for (int i = 0; i < 10; i++) {
            cur_score.push_back(((rand() % 401 + 600) / 10.0f));
        }
        sort(cur_score.begin(), cur_score.end(), greater<double>());
        cur_score.pop_back();
        cur_score.pop_front();
        double avg = accumulate(cur_score.begin(), cur_score.end(), 0.0f) / cur_score.size();
        speakers[*it].m_score[round_num - 1] = avg;
        group_score.insert(make_pair(avg, *it));

        if (num % 6 == 0) {
            cout << "第" << num / 6 << "小组比赛名次: " << endl;

            for_each(group_score.begin(), group_score.end(), [this](const pair<double, int>& sp) -> void {
                cout << "编号: " << sp.second << "\t"
                     << "姓名: " << this->speakers[sp.second].m_name << "\t"
                     << "成绩: " << sp.first << endl;
            });

            int count = 0;
            for (multimap<double, int, greater<double>>::iterator it = group_score.begin(); it != group_score.end(); it++) {
                count++;
                if (count <= 3) {
                    vector<int>& next_round_speaker = round_num == 1 ? round2_speaker : victory;
                    next_round_speaker.push_back((*it).second);
                }
            }
            group_score.clear();
            cout << endl;
        }
    }
    cout << "------------- 第" << round_num << "轮比赛完毕  ------------- " << endl;
}

void SpeechManager::showScore()
{
    cout << "---------第" << round_num << "轮晋级选手信息如下：-----------" << endl;

    vector<int>& cur_speakers = round_num == 1 ? round2_speaker : victory;

    for (auto it = cur_speakers.begin(); it < cur_speakers.end(); it++) {
        cout << "编号: " << *it << "\t"
             << "姓名: " << speakers[*it].m_name << "\t"
             << "成绩: " << speakers[*it].m_score[round_num - 1] << endl;
    }

    cout << endl;

    system("read -n 1");

    system("clear");

    showMenu();
}

void SpeechManager::saveRecord()
{
    ofstream ofs;
    ofs.open("../speech.csv", ios::out | ios::app);

    for (auto speaker_id : victory) {
        ofs << speaker_id << ',' << speakers[speaker_id].m_score[1] << ',';
    }

    ofs << endl;

    ofs.close();

    cout << "记录已经保存好." << endl;

    file_empty = false;
}

void SpeechManager::loadRecord()
{
    ifstream ifs("../speech.csv", ios::in);

    if (!ifs.is_open()) {
        cerr << "speech.csv文件不存在!" << endl;
        ifs.close();
        file_empty = true;
        return;
    }

    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        cerr << "speech.csv文件为空!" << endl;
        ifs.close();
        file_empty = true;
        return;
    }

    ifs.putback(ch);
    file_empty = false;
    string data;
    int index = 0;

    while (ifs >> data) {
        index++;
        int start = 0;
        int pos = -1;
        vector<string> index_speakers;

        while (true) {
            pos = data.find(",", start);
            if (pos == -1) {
                break;
            }
            string tmp_data = data.substr(start, pos - start);
            index_speakers.push_back(tmp_data);
            start = pos + 1;
        }

        records.insert(make_pair(index, index_speakers));
    }

    ifs.close();
}

void SpeechManager::showRecord()
{
    if (file_empty) {
        cerr << "无往届历史." << endl;
        return;
    }
    for (auto& history_record : records) {
        cout << "第" << history_record.first << "届比赛" << endl
             << "冠军: " << history_record.second[0] << '\t'
             << "得分: " << history_record.second[1] << '\t'
             << "亚军: " << history_record.second[2] << '\t'
             << "得分: " << history_record.second[3] << '\t'
             << "季军: " << history_record.second[4] << '\t'
             << "得分: " << history_record.second[5] << '\t' << endl;
    }
}

void SpeechManager::clearRecord()
{
    cout << "确认清空吗？[y/n]: " << endl;

    char ch;
    cin >> ch;

    if (ch == 'y') {
        ofstream ofs("../speech.csv", ios::trunc);
        ofs.close();

        // 重置
        this->records.clear();
    }
}