#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Node {
    int node;
    int dist;
    Node(int _node, int _dist) : node(_node), dist(_dist) {}
};
int cityCount;
vector<vector<int>> roadMat;
vector<int> distTo;
void dij(int root) {
    auto cmp = [](Node* n1, Node* n2) { return n1->dist > n2->dist; };
    priority_queue<Node*, vector<Node*>, decltype(cmp)> pQueue(cmp);
    distTo = vector<int>(cityCount, 2147483647);
    pQueue.push(new Node(root, 0));
    distTo[root] = 0;
    while (!pQueue.empty()) {
        Node* tempNode = pQueue.top();
        pQueue.pop();
        int node = tempNode->node;
        if (tempNode->dist > distTo[node]) {
            continue;
        }
        for (int i = 0; i < cityCount; ++i) {
            if (roadMat[node][i] != -1) {
                int newDist = tempNode->dist + distTo[node];
                if (newDist < distTo[i]) {
                    distTo[i] = newDist;
                    pQueue.push(new Node(i, newDist));
                }
            }
        }
    }
}
void initModel() {
    int roadCount;
    roadMat = vector<vector<int>>(cityCount, vector<int>(cityCount, -1));
    for (int i = 0; i < roadCount; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        roadMat[a][b] = c;
        roadMat[b][a] = c;
    }
}