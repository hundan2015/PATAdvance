#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Node {
    int weight = 0;
    int total = 0;
    vector<int> child;
    vector<int> order;
};
vector<Node> nodeList;
int nodeCount, notLeaf, target;
vector<int> order;
vector<vector<int>> res;
int dfs(int root, int sum) {
    Node& shit = nodeList[root];
    shit.total = sum + shit.weight;
    order.push_back(shit.weight);
    if (shit.child.empty()) {
        if (shit.total == target) {
            res.push_back(order);
        }
    } else if (shit.total < target) {
        for (auto i : shit.child) {
            int nextTotal = dfs(i, shit.total);
        }
    }
    order.pop_back();
    return shit.total;
}
int main() {
    cin >> nodeCount >> notLeaf >> target;
    nodeList = vector<Node>(nodeCount);
    for (auto& i : nodeList) {
        cin >> i.weight;
    }
    for (int i = 0; i < notLeaf; ++i) {
        int pos, childCount;
        cin >> pos >> childCount;
        for (int j = 0; j < childCount; ++j) {
            int data;
            cin >> data;
            nodeList[pos].child.push_back(data);
            vector<int>& shit = nodeList[pos].child;
            auto cmp = [](int& i1, int& i2) {
                return nodeList[i1].weight > nodeList[i2].weight;
            };
            sort(shit.begin(), shit.end(), cmp);
        }
    }
    int tempShit = dfs(0, 0);
    sort(res.begin(), res.end(), ([](auto& a, auto& b) { return a > b; }));
    for (auto i : res) {
        for (int j = 0; j < i.size(); ++j) {
            cout << i[j];
            if (j != i.size() - 1) {
                cout << " ";
            } else {
                cout << endl;
            }
        }
    }
}
/**
 * @brief 经验！他妈的在用例过不去的时候就是用暴力方法！
 * 有的时候你的优化并不是优化！
 * 就像是这道题的问题，要是提前使用优化的话，相同层的不同子节点就无法考虑了！
 * 所以PAT就是一个比较暴力的考试。
 *         1
 *       / \
 *     2   2
 *     /     \
 *   2       3
 *  /         \
 *  3           2
 */