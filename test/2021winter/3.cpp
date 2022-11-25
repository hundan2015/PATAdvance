#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> tree;
int humanCount;
vector<int> dp;
int dfs(int pos) {
    int res = 1;
    if (dp[pos] == -1) {
        for (auto& i : tree[pos]) {
            res += dfs(i);
        }
        dp[pos] = res;
        return res;
    } else {
        return dp[pos];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin >> humanCount;
    dp = vector<int>(humanCount, -1);
    tree = vector<vector<int>>(humanCount);
    for (int i = 1; i < humanCount; ++i) {
        int data;
        cin >> data;
        tree[data - 1].push_back(i);
    }
    int resCount;
    cin >> resCount;
    for (int i = 0; i < resCount; ++i) {
        int data;
        cin >> data;
        cout << dfs(data - 1);
        if (i != resCount - 1) {
            cout << endl;
        }
    }
}