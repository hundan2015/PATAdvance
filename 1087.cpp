// Dijkstra + DFS
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#define INT_MAX 2147483647
using namespace std;
struct state {
    int node;
    int dist;
    state(int n, int d) : node(n), dist(d) {}
};
struct cmp {
    bool operator()(const state* s1, const state* s2) {
        return s1->dist > s2->dist;
    }
};

map<string, int> connection;
int to(string r) {
    return connection[r];
}
vector<int> distTo;
vector<vector<int>> nodeMap;
vector<vector<int>> nodeTree;
int nodeCount;
void dijkstra(string root) {
    distTo[to(root)] = 0;
    priority_queue<state*, vector<state*>, cmp> nodePQ;
    nodePQ.push(new state(to(root), 0));
    while (!nodePQ.empty()) {
        state* tempState = nodePQ.top();
        nodePQ.pop();
        int tempNode = tempState->node;
        if (tempState->dist > distTo[tempNode]) {
            continue;
        }
        for (int i = 0; i < nodeCount; ++i) {
            if (nodeMap[tempNode][i] != -1) {
                int tempDist = distTo[tempNode] + nodeMap[tempNode][i];
                if (tempDist < distTo[i]) {
                    distTo[i] = tempDist;
                    nodeTree[i] = {tempNode};
                    nodePQ.push(new state(i, tempDist));
                } else if (tempDist == distTo[i]) {
                    nodeTree[i].push_back(tempNode);
                }
            }
        }
    }
}
vector<int> nodeHappiness;
int routeCount = 0;
int finalHappySum = -1;
float finalAvrHappySum;
vector<int> finalReverseOrder;
void DFS(int root, int happySum, int nodeCount, vector<int> prevOrder) {
    prevOrder.push_back(root);
    nodeCount++;
    if (root == 0) {
        routeCount++;
        if (happySum > finalHappySum) {
            finalHappySum = happySum;
            finalReverseOrder = prevOrder;
            finalAvrHappySum = (float)happySum / (nodeCount - 1);
        } else if (happySum == finalHappySum &&
                   (float)happySum / (nodeCount - 1) > finalAvrHappySum) {
            finalReverseOrder = prevOrder;
            finalAvrHappySum = (float)happySum / (nodeCount - 1);
        }
        return;
    }
    int tempHappy = happySum + nodeHappiness[root];
    for (auto i : nodeTree[root]) {
        DFS(i, tempHappy, nodeCount, prevOrder);
    }
}
map<int, string> reverseNode;
int main() {
    string startPlace;
    int roadCount;
    cin >> nodeCount >> roadCount >> startPlace;
    nodeHappiness.push_back(0);
    connection.insert(make_pair(startPlace, 0));
    reverseNode.insert(make_pair(0, startPlace));
    for (int i = 1; i < nodeCount; ++i) {
        string city;
        int happy;
        cin >> city >> happy;
        nodeHappiness.push_back(happy);
        connection.insert(make_pair(city, i));
        reverseNode.insert(make_pair(i, city));
    }
    distTo = vector<int>(nodeCount, INT_MAX);
    nodeMap = vector<vector<int>>(nodeCount, vector<int>(nodeCount, -1));
    nodeTree = vector<vector<int>>(nodeCount);
    for (int i = 0; i < roadCount; ++i) {
        string c1, c2;
        int weight;
        cin >> c1 >> c2 >> weight;
        nodeMap[to(c1)][to(c2)] = weight;
        nodeMap[to(c2)][to(c1)] = weight;
    }
    dijkstra(startPlace);
    DFS(to("ROM"), 0, 0, {});
    cout << routeCount << " " << distTo[to("ROM")] << " " << finalHappySum
         << " " << (int)finalAvrHappySum << endl;
    for (int i = finalReverseOrder.size() - 1; i > -1; --i) {
        cout << reverseNode[finalReverseOrder[i]];
        if (i != 0) {
            cout << "->";
        }
    }
}