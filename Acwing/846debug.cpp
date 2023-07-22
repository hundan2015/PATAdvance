#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;
int n;
int minCount = 0x7fffffff;
vector<bool> visited;

int dfsCount(vector<vector<int>>& maps, vector<int>& sizes, int pos) {
    visited[pos] = true;
    for (int i = 0; i < maps[pos].size(); ++i) {
        if (!visited[maps[pos][i]]) {
            sizes[pos] += dfsCount(maps, sizes, maps[pos][i]);
        }
    }
    return sizes[pos];
}

void cacu(vector<vector<int>>& maps, vector<int>& sizes, int pos) {
    int tempMax = -1;
    for (int i = 0; i < maps[pos].size(); ++i) {
        if (sizes[maps[pos][i]] < sizes[pos])
            tempMax = max(tempMax, sizes[maps[pos][i]]);
    }
    tempMax = max(tempMax, sizes[1] - sizes[pos]);
    minCount = min(tempMax, minCount);
}
int main() {
    cin >> n;
    vector<vector<int>> maps(n + 1);
    vector<int> sizes(n + 1, 1);
    visited = vector<bool>(n + 1, false);
    maps[0].push_back(1);
    maps[1].push_back(0);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        maps[a].push_back(b);
        maps[b].push_back(a);
    }
    // 错误就是这dummy必须被访问，不然永远都是比正常值多一个
    // 错误写法root = dfsCount(maps, sizes, 1)
    // 所以说能不写dummy就不要写dummy！
    int root = dfsCount(maps, sizes, 0);
    cout << sizes[1];
    assert(sizes[1] == n);
    for (int i = 1; i <= n; ++i) {
        cacu(maps, sizes, i);
    }
    cout << minCount;
}