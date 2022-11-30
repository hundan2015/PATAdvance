#include <iostream>
#include <vector>
using namespace std;
string ori, target;
int lastFirst;
int minSize = 2147483647;
string minString;
void getO(int tarP, int oriP) {
    if (tarP >= target.size()) {
        int len = oriP - lastFirst;
        if (len < minSize) {
            minSize = len;
            minString = ori.substr(lastFirst, len);
        }
        return;
    }
    for (int i = oriP; i < ori.size(); ++i) {
        if (ori[i] == target[tarP]) {
            if (tarP == 0) {
                lastFirst = i;
            }
            getO(tarP + 1, i + 1);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin >> ori >> target;
    getO(0, 0);
    cout << minString;
}
// 超时的时候试着用迭代法！因为有的时候就只有暴力算法，超时只能迭代。