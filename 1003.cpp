#include <limits.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct node {
    int data;
    int humanResource;
    int maxHumanResource = 0;
    int roadCount = 0;
    node(int da) : data(da) {}
};

struct state {
    node* nodeTarget = nullptr;
    node* nodeParent = nullptr;
    int distance = 0;
    state(node* nodeP, node* nodeT, int dis)
        : nodeParent(nodeP), nodeTarget(nodeT), distance(dis) {}
};

struct cmp {
    bool operator()(const state* x1, const state* x2) {
        return x1->distance > x2->distance;
    }
};

vector<node> nodeList;
vector<int> nodeDistance;
vector<vector<int>> roadMat;
int cityCount;
void dijstla(int root) {
    nodeDistance[root] = 0;
    nodeList[root].maxHumanResource = nodeList[root].humanResource;
    nodeList[root].roadCount = 1;
    priority_queue<state*, vector<state*>, cmp> nodePQue;
    nodePQue.push(new state(&nodeList[root], &nodeList[root], 0));
    while (!nodePQue.empty()) {
        state* tempState = nodePQue.top();
        nodePQue.pop();
        node* tempNode = tempState->nodeTarget;
        if (tempState->distance > nodeDistance[tempNode->data]) {
            continue;
        }
        // if not continue,the node has found the min distance.
        for (int i = 0; i < cityCount; ++i) {
            if (roadMat[tempNode->data][i] != 0) {
                int tempDistance =
                    nodeDistance[tempNode->data] + roadMat[tempNode->data][i];
                if (tempDistance < nodeDistance[i]) {
                    nodeDistance[i] = tempDistance;
                    // going to refresh some data.
                    nodeList[i].roadCount = tempNode->roadCount;
                    nodeList[i].maxHumanResource =
                        nodeList[i].humanResource + tempNode->maxHumanResource;
                    // you have to refresh the old roadCount or other things if
                    // you find a more low distance.
                    nodePQue.push(
                        new state(tempNode, &nodeList[i], tempDistance));
                } else if (tempDistance == nodeDistance[i]) {
                    nodeList[i].roadCount += tempNode->roadCount;
                    nodeList[i].maxHumanResource = max(
                        tempNode->maxHumanResource + nodeList[i].humanResource,
                        nodeList[i].maxHumanResource);
                }
            }
        }
    }
}

int main() {
    int roadCount, cityStart, cityEnd;
    cin >> cityCount >> roadCount >> cityStart >> cityEnd;
    roadMat = vector<vector<int>>(cityCount, vector<int>(cityCount, 0));
    nodeDistance = vector<int>(cityCount, INT_MAX);
    for (int i = 0; i < cityCount; ++i) {
        node nodeTemp(i);
        cin >> nodeTemp.humanResource;
        nodeList.push_back(nodeTemp);
    }
    for (int i = 0; i < roadCount; ++i) {
        int c1, c2, weight;
        cin >> c1 >> c2 >> weight;
        roadMat[c1][c2] = weight;
        roadMat[c2][c1] = weight;
    }
    dijstla(cityStart);
    cout << nodeList[cityEnd].roadCount << " "
         << nodeList[cityEnd].maxHumanResource;
}