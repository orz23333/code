#include "include/speechManager.h"
#include <iostream>

using namespace std;

int main(int, char**)
{
    srand(time(0));

    cout << "Hello, from SpeachManager!\n";

    SpeechManager sm;

    // sm.showSpeaker();

    sm.showMenu();

    int choice = 0;

    while (true) {
        cout << "请输入您的选择: " << endl;

        cin >> choice;

        cout << endl;

        switch (choice) {
        case 1:
            sm.startSpeech();
            break;
        case 2:
            sm.showRecord();
            break;
        case 3:
            sm.clearRecord();
            break;
        case 4:
            sm.showMenu();
            break;
        case 0:
            sm.exitSystem();
            break;
        default:
            system("clear");
            break;
        }
    }

    return 0;
}
