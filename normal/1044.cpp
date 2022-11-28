#include <iostream>
#include <string>
#include <vector>
using namespace std;
int minMaxShit = 9999999;
vector<string> banker;

int main() {
    int numCount, target;
    cin >> numCount >> target;
    vector<int> numList(numCount);
    int tempSum = 0;
    int         frontPos = 0, endPos = 0;
    bool flag = false;
    for (auto& i : numList) {
        cin >> i;
        tempSum += i;
        endPos++;
        while (tempSum > target && frontPos < endPos) {
            if (tempSum < minMaxShit) {
                string temp;
                banker.clear();
                temp = to_string(frontPos + 1) + "-" + to_string(endPos);
                banker.push_back(temp);
                minMaxShit = tempSum;
            } else if (tempSum == minMaxShit) {
                string temp;
                temp = to_string(frontPos + 1) + "-" + to_string(endPos);
                banker.push_back(temp);
            }
            tempSum -= numList[frontPos];
            frontPos++;
        }
        if (tempSum == target) {
            flag = true;
            cout << frontPos + 1 << "-" << endPos << endl;
        }
    }
    if (!flag) {
        for (auto i : banker) {
            cout << i << endl;
        }
    }
}
/**
brief 简单的滑动窗口。
 *
 */