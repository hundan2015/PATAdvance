#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, m;
int distanceFinal = -1;
vector<vector<int>> nodeMap;
void bfs(int root) {
    int dis = 0;
    if (n == 1) {
        distanceFinal = 0;
        return;
    }
    vector<bool> visited(n, false);
    queue<int> nodeQue;
    nodeQue.push(root);
    while (!nodeQue.empty()) {
        dis++;
        int size = nodeQue.size();
        for (int i = 0; i < size; ++i) {
            int top = nodeQue.front();
            visited[top] = true;
            nodeQue.pop();
            for (auto& j : nodeMap[top]) {
                if (j == n - 1) {
                    distanceFinal = dis;
                    return;
                }
                if (!visited[j])
                    nodeQue.push(j);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    nodeMap.resize(n);
    for (int i = 0; i < m; ++i) {
        int start, end;
        cin >> start >> end;
        nodeMap[start - 1].emplace_back(end - 1);
    }
    bfs(0);
    cout << distanceFinal;
}