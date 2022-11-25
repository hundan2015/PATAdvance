#include <limits.h>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#define _HUGE_ENUF 1e+300
#define INFINITY ((float)(_HUGE_ENUF * _HUGE_ENUF))
using namespace std;
vector<vector<int>> nodeMap;

struct state {
    int node;
    int dist;
    state(int n, int d) : node(n), dist(d) {}
};
vector<int> distTo;
int nodeCount;
int gasCount, maxRange;

map<string, int> connection;

int to(string s) {
    return connection[s];
}
struct cmp {
    bool operator()(state* s1, state* s2) { return s1->dist > s2->dist; }
};

string finalGasName;
int finalMinRoute = -1;
int finalSum;

void dijstra(string root) {
    int finalCount = nodeCount + gasCount;
    distTo = vector<int>(finalCount, INT_MAX);
    priority_queue<state*, vector<state*>, cmp> nodePQ;
    distTo[to(root)] = 0;
    nodePQ.push(new state(to(root), 0));
    while (!nodePQ.empty()) {
        state* tempState = nodePQ.top();
        int nodeNum = tempState->node;
        nodePQ.pop();
        if (tempState->dist > distTo[nodeNum]) {
            continue;
        }
        for (int i = 0; i < finalCount; ++i) {
            if (nodeMap[nodeNum][i] != -1) {
                int tempDist = distTo[nodeNum] + nodeMap[nodeNum][i];
                if (tempDist < distTo[i]) {
                    distTo[i] = tempDist;
                    nodePQ.push(new state(i, tempDist));
                }
            }
        }
    }

    int sum = 0;
    int deathTrigger = false;
    int minRoute = INT_MAX;
    for (int i = 0; i < nodeCount; ++i) {
        if (distTo[i] <= maxRange) {
            sum += distTo[i];
            if (distTo[i] < minRoute) {
                minRoute = distTo[i];
            }
        } else {
            deathTrigger = true;
            break;
        }
    }
    if (!deathTrigger) {
        if (finalMinRoute < minRoute) {
            finalMinRoute = minRoute;
            finalGasName = root;
            finalSum = sum;
        } else if (finalMinRoute == minRoute) {
            if (sum <= finalSum) {
                finalMinRoute = minRoute;
                finalGasName = root;
                finalSum = sum;
            }
        }
    }
}
int main() {
    int roadCount;
    cin >> nodeCount >> gasCount >> roadCount >> maxRange;
    // init connection map.
    for (int i = 1; i <= nodeCount; ++i) {
        connection.insert(make_pair(to_string(i), i - 1));
    }
    for (int i = 1; i <= gasCount; ++i) {
        connection.insert(make_pair("G" + to_string(i), nodeCount + i - 1));
    }

    nodeMap = vector<vector<int>>(nodeCount + gasCount,
                                  vector<int>(nodeCount + gasCount, -1));

    for (int i = 0; i < roadCount; ++i) {
        string c1, c2;
        int data;
        cin >> c1 >> c2 >> data;
        nodeMap[to(c1)][to(c2)] = data;
        nodeMap[to(c2)][to(c1)] = data;
    }
    for (int i = gasCount; i > 0; --i) {
        dijstra("G" + to_string(i));
    }
    if (finalMinRoute != -1) {
        cout << finalGasName << endl;
        double shit = (float)finalSum / (float)nodeCount;
        printf("%.1f %.1lf", (float)finalMinRoute, shit + 0.01);
    } else {
        cout << "No Solution";
    }
}
//解是对的但是严重超时因为是O(n^3)所以说应该是dijkstra
//我是傻逼