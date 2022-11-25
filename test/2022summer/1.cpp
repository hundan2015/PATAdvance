#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> boy1(3);
    vector<int> boy2(3);
    int pos1, pos2;
    for (int i = 0; i < 3; ++i) {
        cin >> boy1[i];
        // boy1[i] += 7;
    }
    for (int i = 0; i < 3; ++i) {
        cin >> boy2[i];
        // boy2[i] += 7;
    }
    for (int i = 0; i < 3; i++) {
        bool trigger = false;
        for (int j = 0; j < 3; ++j) {
            boy1[i] %= 7;
            boy2[i] %= 7;
            if (j > i && boy2[j] < boy1[i]) {
                boy2[j] += 7;
            }
            if (i > j && boy1[i] < boy2[j]) {
                boy1[i] += 7;
            }
            if (boy2[j] - boy1[i] == j - i) {
                trigger = true;
                pos1 = i;
                pos2 = j;
                break;
            }
        }
        if (trigger) {
            break;
        }
    }
    vector<string> dayStr = {"Sunday",   "Monday", "Tuesday", "Wednesday",
                             "Thursday", "Friday", "Saturday"};
    vector<string> goodStr = {"yesterday", "today", "tomorrow"};
    int today;
    switch (pos1) {
        case 0:
            today = (boy1[pos1] + 1) % 7;
            break;
        case 1:
            today = boy1[pos1] % 7;
            break;
        case 2:
            today = (boy1[pos1] - 1) % 7;
        default:
            break;
    }
    cout << dayStr[today] << endl;
    cout << goodStr[pos1] << endl << goodStr[pos2];
}