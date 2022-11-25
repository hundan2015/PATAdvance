#include <limits.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct node {
    int data;
    int bike;
    vector<int> prevNode;
};
struct state {
    node* nodeTar;
    int distance;
    state(node* n, int d) : nodeTar(n), distance(d) {}
};
vector<int> distTo;
vector<node> nodeList;
struct cmp {
    bool operator()(const state* s1, const state* s2) {
        return s1->distance > s2->distance;
    }
};
vector<vector<int>> nodeMat;
int nodeCount, bikeContain, targetStation;

void dijkstra() {
    priority_queue<state*, vector<state*>, cmp> nodePQue;
    nodePQue.push(new state(&nodeList[0], 0));
    distTo[0] = 0;
    nodeList[0].bike = bikeContain;
    while (!nodePQue.empty()) {
        state* tempState = nodePQue.top();
        nodePQue.pop();
        node* tempNode = tempState->nodeTar;
        if (distTo[tempNode->data] < tempState->distance) {
            continue;
        }
        for (int i = 0; i <= nodeCount; ++i) {
            if (nodeMat[tempNode->data][i] != 0) {
                int tempDistance =
                    nodeMat[tempNode->data][i] + distTo[tempNode->data];
                if (tempDistance < distTo[i]) {
                    distTo[i] = tempDistance;
                    nodeList[i].prevNode = {tempNode->data};
                    nodePQue.push(new state(&nodeList[i], tempDistance));
                } else if (tempDistance == distTo[i]) {
                    nodeList[i].prevNode.push_back(tempNode->data);
                }
            }
        }
    }
}

vector<int> finalRoute;
int finalRemain = INT_MAX, finalNeed = INT_MAX;
void judgeRoute(vector<int> route) {
    int need = 0, remain = 0;
    for (int i = route.size() - 2; i > -1; --i) {
        int root = nodeList[route[i]].bike;
        remain += root;
        if (root < 0) {
            if (remain < 0) {
                need -= remain;
                remain = 0;
            }
        }
    }
    if (need < finalNeed || (need == finalNeed && remain < finalRemain)) {
        finalNeed = need;
        finalRemain = remain;
        finalRoute = route;
    }
}
void DFS(int root, int need, vector<int> route) {
    if (nodeList[root].prevNode.empty()) {
        route.push_back(0);
        judgeRoute(route);
        return;
    }
    route.push_back(root);
    need += nodeList[root].bike;
    for (auto i : nodeList[root].prevNode) {
        DFS(i, need, route);
    }
}  // Dijskla部分设计好了，但是DFS这块还是没想好。
int main() {
    int roadCount;
    cin >> bikeContain >> nodeCount >> targetStation >> roadCount;
    bikeContain /= 2;
    nodeMat = vector<vector<int>>(nodeCount + 1, vector<int>(nodeCount + 1, 0));
    distTo = vector<int>(nodeCount + 1, INT_MAX);
    nodeList = vector<node>(nodeCount + 1);
    for (int i = 1; i <= nodeCount; ++i) {
        nodeList[i].data = i;
        cin >> nodeList[i].bike;
        nodeList[i].bike -= bikeContain;
    }
    for (int i = 0; i < roadCount; ++i) {
        int n1, n2, weight;
        cin >> n1 >> n2 >> weight;
        nodeMat[n1][n2] = weight;
        nodeMat[n2][n1] = weight;
    }
    dijkstra();
    DFS(targetStation, 0, {});
    cout << finalNeed << " ";

    for (int i = finalRoute.size() - 1; i > -1; --i) {
        cout << finalRoute[i];
        if (i != 0) {
            cout << "->";
        }
    }
    cout << " " << finalRemain;
}

/*赛后总结：
这道题主要是一个dijskla+DFS的问题。这回受折磨的主要原因一是思维定式，总是认为局部最优能解决所有问题，所以不能总是使用dp来偷懒。
然后就是在使用DFS时思考过于简单，没有考虑到题意，没有想到公司是不能走回头路的。
因此以后做题首先需要通读提议，并且首先要验证算法的可行性，不能上来就是写，这样的话很难说是直接得出答案。
要自己设计例子，并且实践查看是否满足题意。
一定要看好题！！！！！！！！！！！！！！！！！！
分析好题中隐藏的限制条件！
有的时候笨方法会更好。
一定要看懂题！一定要设计例子！！！！！！！
多思考还有多练。我们不会跌倒在同一个地方第二次。
因为我是无限可能的！*/