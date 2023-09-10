// 贪心加剪枝
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Edge {
    int child;
    int weight;
    Edge(int _child, int _weight) : child(_child), weight(_weight) {}
};
vector<vector<Edge>> mat;
int numCount, y;
int minX = -1;
bool cmp(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
};
// 算法是错的！因为没有考虑到bounder对于下面的weight的影响。
// 最好的办法就是直接贪心然后直接暴力BFS进行计数。
// 可以用二分搜索优化一下
 void search(int node, int nodeCount, int lowBound, int upBound) {
    int tempCount = nodeCount;
    auto lowIndex =
        lower_bound(mat[node].begin(), mat[node].end(), Edge(0, lowBound), cmp);
    if (lowIndex == mat[node].end())
        lowIndex = mat[node].begin();
    auto upIndex =
        upper_bound(mat[node].begin(), mat[node].end(), Edge(0, upBound), cmp);
    if (upIndex == mat[node].end())
        upIndex = mat[node].end() - 1;
    for (auto i = mat[node].begin(); i < lowIndex; ++i) {
        tempCount -= i->weight;
    }
    if (tempCount <= y) {
        minX = lowBound;
        return;
    }
    vector<Edge> tempVec(lowIndex, upIndex + 1);
    for (int i = 0; i < tempVec.size(); i++) {
        int tempX = tempVec[i].weight + 1;
        tempCount -= (mat[tempVec[i].child].size() + 1);
        if (tempCount <= y) {
            int lastBound =
                i == 0 ? lowIndex->weight : tempVec[i - 1].weight + 1;
            search(tempVec[i].child,
                   tempCount + (mat[tempVec[i].child].size() + 1), lastBound,
                   tempVec[i].weight);
            if (minX != -1)
                return;
            minX = tempX;
            return;
        }
    }
}
int main() {
    cin >> numCount >> y;
    int sum = 0;
    int maxW = -1;
    mat = vector<vector<Edge>>(numCount);
    for (int i = 0; i < numCount - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        mat[u].push_back(Edge(v, w));
        sum += w;
        maxW = max(maxW, w);
    }
    for (auto& i : mat) {
        sort(i.begin(), i.end(), cmp);
    }
    search(0, numCount, 0, maxW + 1);
    cout << minX;
}