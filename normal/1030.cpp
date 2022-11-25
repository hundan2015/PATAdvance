#include <limits.h>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
struct node {
    int cost = 0;
    vector<int> parent;
};

struct state {
    int nodeP;
    int dist;
    state(int _node, int d) : nodeP(_node), dist(d) {}
};

struct cmp {
    bool operator()(const state* s1, const state* s2) {
        return s1->dist > s2->dist;
    }
};

vector<node> nodeList;
vector<int> distTo;
vector<vector<int>> nodeMat;
vector<vector<int>> costMat;
int nodeCount;
void dijskra(int root) {
    priority_queue<state*, vector<state*>, cmp> nodePQ;
    nodeList[root].parent = {};
    nodeList[root].cost = 0;
    distTo[root] = 0;
    nodePQ.push(new state(root, 0));
    while (!nodePQ.empty()) {
        state* tempState = nodePQ.top();
        nodePQ.pop();
        int tempNode = tempState->nodeP;
        if (tempState->dist > distTo[tempState->dist]) {
            continue;
        }
        for (int i = 0; i < nodeCount; ++i) {
            if (nodeMat[tempNode][i] != -1) {
                int tempDist = distTo[tempNode] + nodeMat[tempNode][i];
                if (tempDist < distTo[i]) {
                    distTo[i] = tempDist;
                    nodeList[i].parent = {tempNode};
                    nodePQ.push(new state(i, tempDist));
                } else if (tempDist == distTo[i]) {
                    nodeList[i].parent.push_back(tempNode);
                }
            }
        }
    }
}
int roadCount, startCity, endCity;
int minCost = INT_MAX;
vector<int> minVec;
void DFS(int root, int cost, vector<int> shit) {
    shit.push_back(root);
    if (root == startCity) {
        if (cost < minCost) {
            minCost = cost;
            minVec = shit;
        }
    }
    for (auto i : nodeList[root].parent) {
        int costTemp = cost + costMat[root][i];
        DFS(i, costTemp, shit);
    }
}
int main() {
    cin >> nodeCount >> roadCount >> startCity >> endCity;
    nodeMat = vector<vector<int>>(nodeCount, vector<int>(nodeCount, -1));
    costMat = vector<vector<int>>(nodeCount, vector<int>(nodeCount, -1));
    nodeList = vector<node>(nodeCount);
    distTo = vector<int>(nodeCount, INT_MAX);
    for (int i = 0; i < roadCount; ++i) {
        int c1, c2, weight, cost;
        cin >> c1 >> c2 >> weight >> cost;
        nodeMat[c1][c2] = weight;
        nodeMat[c2][c1] = weight;
        costMat[c1][c2] = cost;
        costMat[c2][c1] = cost;
    }
    dijskra(startCity);
    int p = endCity;
    DFS(endCity, 0, {});
    for (int i = minVec.size() - 1; i > -1; --i) {
        cout << minVec[i] << " ";
    }
    cout << distTo[endCity] << " " << minCost;
}
//另一种做法详见WA，我真的没有想明白为啥错