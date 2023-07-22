#include <iostream>
#include <vector>

using namespace std;
int n;
int minCount = 0x7fffffff;
vector<bool> visited;

int dfsCount(vector<vector<int>>& maps, vector<int>& sizes, int pos) {
    visited[pos] = true;
    int tempMax = -1;
    for (int i = 0; i < maps[pos].size(); ++i) {
        if (!visited[maps[pos][i]]) {
            // 这里可以简化。
            // 如果不能ac的话，简化一下代码试试。
            int num = dfsCount(maps, sizes, maps[pos][i]);
            tempMax = max(num, tempMax);
            sizes[pos] += num;
        }
    }
    // 关键问题就是在这个n上。是n就对，如果是1就不对。
    // 所以说能不写dummy就不要写dummy！
    // 问题是在便利的时候没有从dummy开始遍历，所以导致size[1]和n不一致
    tempMax = max(n - sizes[pos], tempMax);
    minCount = min(tempMax, minCount);
    return sizes[pos];
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
    int root = dfsCount(maps, sizes, 0);
    cout << sizes[1] << endl;
    cout << minCount;
}