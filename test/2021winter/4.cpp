#include <iostream>
#include <vector>
#define INT_MAX 2147483647
#define INT_MIN (-2147483647 - 1)
using namespace std;
struct Position {
    int ddl;
    int earn;
    int panal;
};

vector<vector<int>> floydTable;
vector<Position> timeTable;
// vector<vector<int>> roadMap;
int posCount, roadCount, startTime;
int bestTime = INT_MAX, bestEarn = INT_MIN, bestPlan;
void floyd() {
    for (int mid = 0; mid < posCount + 1; ++mid) {
        for (int j = 0; j < posCount + 1; ++j) {
            for (int i = 0; i < posCount + 1; ++i) {
                floydTable[i][j] = min(floydTable[i][j],
                                       floydTable[i][mid] + floydTable[mid][j]);
            }
        }
    }
}
int main() {
    int startHour, startMin;
    scanf("%d %d %d:%d", &posCount, &roadCount, &startHour, &startMin);
    timeTable = vector<Position>(posCount + 1);
    floydTable =
        vector<vector<int>>(posCount + 1, vector<int>(posCount + 1, 9999999));
    startTime = startHour * 60 + startMin;
    for (int i = 1; i <= posCount; ++i) {
        int ddlMin, ddlHour, y, p;
        scanf("%d:%d %d %d", &ddlHour, &ddlMin, &y, &p);
        timeTable[i].ddl = ddlHour * 60 + ddlMin;
        timeTable[i].earn = y;
        timeTable[i].panal = p;
    }
    for (int i = 0; i < roadCount; ++i) {
        int data1, data2, data3;
        scanf("%d %d %d", &data1, &data2, &data3);
        floydTable[data1][data2] = data3;
        floydTable[data2][data1] = data3;
    }
    floyd();
    int planCount;
    scanf("%d", &planCount);
    for (int i = 0; i < planCount; i++) {
        int nowPos = 0;
        int timeNow = startTime;
        int money = 0;
        bool death = false;
        vector<bool> visited(posCount);
        for (int pos = 0; pos < posCount; ++pos) {
            int data;
            cin >> data;
            if (!visited[data - 1])
                visited[data - 1] = true;
            else {
                death = true;
                break;
            }
            timeNow += floydTable[nowPos][data];
            if (timeNow > timeTable[data].ddl) {
                money += timeTable[data].earn - timeTable[data].panal;
            } else {
                money += timeTable[data].earn;
            }
            nowPos = data;
        }
        if (!death) {
            timeNow += floydTable[nowPos][0];
            if ((money > bestEarn) || (money == bestEarn && timeNow < bestTime)) {
                bestEarn = money;
                bestTime = timeNow;
            }
        }
    }
    bestTime = bestTime % (60 * 24);
    printf("%d %02d:%02d", bestEarn, bestTime / 60, bestTime % 60);
}