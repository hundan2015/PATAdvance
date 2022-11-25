#include <iostream>
#include <map>
#include <set>
#include <vector>
#define INT_MAX 2147483647
using namespace std;
int siteCount, eventCount;
vector<vector<int>> table;
int main() {
    cin >> siteCount >> eventCount;
    table = vector<vector<int>>(eventCount, vector<int>(siteCount));
    for (auto& i : table) {
        for (auto& j : i) {
            cin >> j;
        }
    }
    vector<int> scoreSite(siteCount, 0);
    for (int event = 0; event < eventCount; ++event) {
        vector<int> siteScore = vector<int>(siteCount, siteCount);
        int minScore = 99999999;
        for (int siteNow = 0; siteNow < siteCount; ++siteNow) {
            for (int site = 0; site < siteCount; ++site) {
                if (table[event][siteNow] != table[event][site]) {
                    siteScore[siteNow]--;
                }
            }
            minScore = min(siteScore[siteNow], minScore);
        }
        for (int site = 0; site < siteCount; ++site) {
            if (siteScore[site] == minScore) {
                scoreSite[site]--;
            }
        }
    }
    int minShit, minNum = INT_MAX;
    for (int i = 0; i < siteCount; ++i) {
        if (scoreSite[i] < minNum) {
            minShit = i + 1;
            minNum = scoreSite[i];
        }
    }
    cout << minShit;
}