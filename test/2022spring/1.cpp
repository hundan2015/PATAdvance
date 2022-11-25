#include <iostream>
using namespace std;
int questNum, thereHold, testee;
void test() {
    string answerNow;
    int score = 0;
    cin >> answerNow;
    char charNow, charLast = '\n';
    if (answerNow[0] == 'f') {
        score -= 2;
    }
    if (answerNow.back() == 'a') {
        score -= 1;
    }

    enum State { good, lianxu, xiangtong };
    int lianxuCounter = 0, xiangtongCounter = 0;
    State stateNow = good;
    for (auto a : answerNow) {
        if (charLast == '\n') {
            charLast = a;
            continue;
        }
        if (charLast == 'a' && (a == 'e' || a == 'h')) {
            score -= 4;
        }
        if (a == charLast + 1) {
            switch (stateNow) {
                case lianxu:
                    lianxuCounter++;
                    break;
                case good:
                    stateNow = lianxu;
                    lianxuCounter = 2;
                    break;
                case xiangtong:
                    stateNow = lianxu;
                    if (xiangtongCounter > 5) {
                        score += 3;
                    }
                    xiangtongCounter = 0;
                    lianxuCounter = 2;
                    break;
                default:
                    break;
            }
        } else if (a == charLast) {
            switch (stateNow) {
                case xiangtong:
                    xiangtongCounter++;
                    break;
                case good:
                    stateNow = xiangtong;
                    xiangtongCounter = 2;
                    break;
                case lianxu:
                    stateNow = xiangtong;
                    if (lianxuCounter > 3) {
                        score += 5;
                    }
                    lianxuCounter = 0;
                    xiangtongCounter = 2;
                    break;
            }
        } else {
            switch (stateNow) {
                case xiangtong:
                    if (xiangtongCounter > 5) {
                        score += 3;
                    }
                    stateNow = good;
                    xiangtongCounter = 0;
                    break;
                case good:
                    break;
                case lianxu:
                    stateNow = good;
                    if (lianxuCounter > 3) {
                        score += 5;
                    }
                    lianxuCounter = 0;
                    break;
            }
        }
        charLast = a;
    }
    switch (stateNow) {
        case xiangtong:
            if (xiangtongCounter > 5) {
                score += 3;
            }
            stateNow = good;
            xiangtongCounter = 0;
            break;
        case good:
            break;
        case lianxu:
            stateNow = good;
            if (lianxuCounter > 3) {
                score += 5;
            }
            lianxuCounter = 0;
            break;
    }
    cout << score;
    if (score > thereHold) {
        cout << "!!!";
    }
    cout << endl;
}
int main() {
    cin >> questNum >> thereHold >> testee;
    for (int i = 0; i < testee; ++i) {
        test();
    }
}