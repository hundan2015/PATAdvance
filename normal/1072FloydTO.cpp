#include <limits.h>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#define _HUGE_ENUF 1e+300
#define INFINITY ((float)(_HUGE_ENUF * _HUGE_ENUF))
using namespace std;
vector<vector<int>> distTo;

int nodeCount;
int gasCount, maxRange;
void floyd() {
    int shit = nodeCount + gasCount;
    for (int k = 0; k < shit; ++k) {
        for (int i = 0; i < shit; ++i) {
            for (int j = 0; j < shit; ++j) {
                int dis = distTo[i][k] + distTo[k][j];
                if (distTo[i][k] != INT_MAX && distTo[k][j] != INT_MAX &&
                    distTo[i][j] > dis) {
                    distTo[i][j] = dis;
                }
            }
        }
    }
}
map<string, int> connection;
int to(string s) {
    return connection[s];
}
int main() {
    int roadCount;
    cin >> nodeCount >> gasCount >> roadCount >> maxRange;
    for (int i = 1; i <= nodeCount; ++i) {
        connection.insert(make_pair(to_string(i), i - 1));
    }
    for (int i = 1; i <= gasCount; ++i) {
        connection.insert(make_pair("G" + to_string(i), nodeCount + i - 1));
    }
    distTo = vector<vector<int>>(nodeCount + gasCount,
                                 vector<int>(nodeCount + gasCount, INT_MAX));

    for (int i = 0; i < roadCount; ++i) {
        string c1, c2;
        int data;
        cin >> c1 >> c2 >> data;
        distTo[to(c1)][to(c2)] = data;
        distTo[to(c2)][to(c1)] = data;
    }
    floyd();
    float minSum = INFINITY;
    string finalGasName;
    float finalMinRoute = -1;
    for (int i = gasCount; i > 0; --i) {
        string gasName = "G" + to_string(i);
        int gasNum = to(gasName);
        float sumTemp = 0;
        float tempMin = INT_MAX;
        float tempMax = -1;
        bool deathTrigger = false;
        for (int i = 0; i < nodeCount; ++i) {
            if (distTo[i][gasNum] == INT_MAX) {
                deathTrigger = true;
                break;
            }
            sumTemp += distTo[i][gasNum];
            tempMin = min(tempMin, (float)(distTo[i][gasNum]));
            tempMax = max(tempMax, (float)(distTo[i][gasNum]));
        }
        if (deathTrigger || tempMax > maxRange) {
            continue;
        }
        if (finalMinRoute < tempMin) {
            minSum = sumTemp;
            finalGasName = gasName;
            finalMinRoute = tempMin;
        } else if (finalMinRoute == tempMin) {
            if (minSum >= sumTemp) {
                minSum = sumTemp;
                finalGasName = gasName;
                finalMinRoute = tempMin;
            }
        }
    }
    if (minSum != INFINITY) {
        cout << finalGasName << endl;
        printf("%.1f %.1f", finalMinRoute, minSum / nodeCount);
    } else {
        cout << "No Solution";
    }
}
//解是对的但是严重超时因为是O(n^3)所以说应该是dijkstra
//我是傻逼