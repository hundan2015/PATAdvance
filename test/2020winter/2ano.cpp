#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
string ori, target;
map<char, vector<int>> mat;
int minSize = 99999999;
string minString;
int lastStart;

void getO(int tarP, int oriP) {
    if (tarP == target.size() - 1) {
        int lastPos = -1;
        vector<int>& shit = mat[target[tarP]];
        
        for (auto i : shit) {
            if (i > oriP) {
                lastPos = i;
                break;
            }
        }
        if (lastPos != -1) {
            int len = lastPos - lastStart + 1;
            if (len < minSize) {
                minString = ori.substr(lastStart, len);
                minSize = len;
                return;
            }
        }
    }
    vector<int>& shit = mat[target[tarP]];
    for (auto i : shit) {
        if (i > oriP) {
            if (tarP == 0) {
                lastStart = i;
            }
            getO(tarP + 1, i);
        }
    }
}
int main() {
    cin >> ori >> target;
    for (int i = 0; i < ori.size(); ++i) {
        auto it = mat.find(ori[i]);
        if (it != mat.end()) {
            it->second.push_back(i);
        } else {
            mat.insert({ori[i], {i}});
        }
    }
    getO(0, -1);
    cout << minString;
}