#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<vector<int>> roadMat;
int siteCount, edgeCount, questCount;
bool isNext(int a1, int a2) {
    for (auto i : roadMat[a1]) {
        if (i == a2)
            return true;
    }
    return false;
}
bool isNot(vector<bool>& visited, int pos) {
    for (auto i : roadMat[pos]) {
        if (!visited[i])
            return false;
    }
    return true;
}
//这块还得是模拟DFS，所以说这个就是比较错误的打法，但是除了一个用例剩下的都能过
bool isGood(queue<int> buff) {
    int pos = buff.front();
    vector<bool> visited(siteCount, false);
    visited[pos] = true;
    buff.pop();
    while (!buff.empty()) { 
        int nextData = buff.front();
        if ((!visited[nextData]) &&
            (isNext(pos, nextData) || isNot(visited, pos))) {
            pos = nextData;
            visited[nextData] = true;
            buff.pop();
            continue;
        }
        return false;
    }
    return true;
}
int main() {
    cin >> siteCount >> edgeCount >> questCount;
    roadMat = vector<vector<int>>(siteCount);
    for (int i = 0; i < edgeCount; ++i) {
        int data1, data2;
        cin >> data1 >> data2;
        roadMat[data1 - 1].push_back(data2 - 1);
    }
    for (int i = 0; i < questCount; ++i) {
        queue<int> res;
        for (int i = 0; i < siteCount; ++i) {
            int dataS;
            cin >> dataS;
            res.push(dataS - 1);
        }
        if (isGood(res)) {
            cout << "yes";
        } else {
            cout << "no";
        }
        if (i != questCount - 1) {
            cout << endl;
        }
    }
}