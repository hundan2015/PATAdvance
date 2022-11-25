#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
int siteCount, eventCount;
vector<vector<int>> table;
int main() {
    cin >> siteCount >> eventCount;
    vector<int> scoreTable(siteCount);
    for (int event = 0; event < eventCount; ++event) {
        map<int, int> hashMap;
        vector<int> opnion(siteCount);
        for (int i = 0; i < siteCount; ++i) {
            cin >> opnion[i];
            hashMap[opnion[i]]++;
        }
        vector<int> score(siteCount);
        int maxShit = -1;
        for (int i = 0; i < siteCount; ++i) {
            score[i] = siteCount - hashMap[opnion[i]];
            maxShit = max(score[i], maxShit);
        }
        for (int i = 0; i < siteCount; ++i) {
            if (score[i] == maxShit) {
                scoreTable[i]++;
            }
        }
    }
    int maxShit = -1, maxNum;
    for (int i = 0; i < siteCount; ++i) {
        if (scoreTable[i] > maxShit) {
            maxShit = scoreTable[i];
            maxNum = i + 1;
        }
    }
    cout << maxNum;
}
