#include <iostream>
#include <iterator>
#include <queue>
#include <string>
#include <vector>

using namespace std;
vector<vector<int>> mat;
struct Node {
    int data;
    int distance;
    Node(int d, int di) : data(d), distance(di) {}
};

vector<int> bikeList;
vector<Node> nodeList;
vector<int> distTo;
vector<vector<int>> parent;

int nodeCount;
int target, cap;
void dij() {
    auto cmp = [](auto& a, auto& b) { return a->distance > b->distance; };
    priority_queue<Node*, vector<Node*>, decltype(cmp)> nodeQue(cmp);
    nodeQue.push(new Node(0, 0));
    distTo[0] = 0;
    while (!nodeQue.empty()) {
        Node* temp = nodeQue.top();
        nodeQue.pop();
        if (distTo[temp->data] < temp->distance) {
            continue;
        } else {
            for (int i = 1; i < nodeCount; ++i) {
                int road = mat[temp->data][i];
                if (road != -1) {
                    int distT = road + distTo[temp->data];
                    if (distT < distTo[i]) {
                        nodeQue.push(new Node(i, distT));
                        distTo[i] = distT;
                        parent[i] = {temp->data};
                    } else if (distT == distTo[i]) {
                        parent[i].push_back(temp->data);
                    }
                }
            }
        }
    }
}
int bestNeed = 99999999, bestTake = 999999999;
bool isFirst = true;
string bestString;
void dfs(int pos, vector<int> list) {
    list.push_back(pos);
    if (pos == 0) {
        int need = 0, remain = 0;
        for (int i = list.size() - 2; i > -1; --i) {
            int root = bikeList[list[i]];
            remain += root;
            if (remain < 0) {
                need = need - remain;
                remain = 0;
            }
        }
        if (need < bestNeed || (need == bestNeed && remain < bestTake)) {
            bestNeed = need;
            bestTake = remain;
            bestString = "";
            for (int i = list.size() - 1; i > -1; --i) {
                bestString += to_string(list[i]);
                if (i != 0) {
                    bestString += "->";
                }
            }
        }
    }
    for (auto i : parent[pos]) {
        dfs(i, list);
    }
}
int main() {
    int roadCount;
    cin >> cap >> nodeCount >> target >> roadCount;
    cap = cap / 2;
    nodeCount++;
    mat = vector<vector<int>>(nodeCount, vector<int>(nodeCount, -1));
    bikeList = vector<int>(nodeCount);
    distTo = vector<int>(nodeCount, 2147483645);
    parent = vector<vector<int>>(nodeCount);
    for (int i = 1; i < nodeCount; ++i) {
        cin >> bikeList[i];
        bikeList[i] -= cap;
    }
    for (int i = 0; i < roadCount; ++i) {
        int data1, data2, data3;
        cin >> data1 >> data2 >> data3;
        mat[data1][data2] = data3;
        mat[data2][data1] = data3;
    }
    dij();
    dfs(target, {});
    cout << bestNeed << " " << bestString << " " << bestTake;
}
/**
 * @brief Dijkstra + DFS
 * 以后遇到这种问题就别他妈整什么局部最优了。
 * 之后就遇到这种情况就他妈DFS
 * 先收集所有最短路，然后直接DFS
 * 我感觉他他妈特别喜欢DFS
 */