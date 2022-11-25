#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int INF = 1000000000;
int bonder, m, G[205][205], vis[205], ans = 0;
vector<int> vec;  //存储访问路径
void dfs(int pos, int temp) {
    if (vec.size() == bonder)  // 1-n都已访问过
    {
        ans = temp;
        return;
    }
    int minpos = 0, mindis = INF, flag = 0;
    for (int i = 0; i <= bonder; i++) {
        if (!vis[i])
            if (G[pos][i] < mindis) {
                flag = 1;
                mindis = G[pos][i];
                minpos = i;
            }
    }  //找到最短距离的点（距离相同时编号小的点优先）
    if (!flag)
        return;  //没有点可以访问
    vis[minpos] = 1;
    vec.emplace_back(minpos);
    dfs(minpos, temp + mindis);  //访问下一个点
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> bonder >> m;
    int a, b, c;
    for (int i = 0; i <= bonder; i++)
        for (int j = 0; j <= bonder; j++) {
            if (i == j)
                G[i][j] = 0;
            else
                G[i][j] = INF;
        }  //邻接矩阵初始化
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        G[a][b] = G[b][a] = c;
    }  //输入图
    for (int i = 0; i <= bonder; i++)
        for (int j = 0; j <= bonder; j++)
            for (int k = 0; k <= bonder; k++)
                if (G[i][k] + G[k][j] < G[i][j])
                    G[i][j] = G[i][k] + G[k][j];  // Floyd最短路更新
    vis[0] = 1;
    dfs(0, 0);  //从0点出发开始访问
    cout << "0";
    for (int i = 0; i < vec.size(); i++)
        cout << " " << vec[i];
    cout << endl;  //输出路径
    if (vec.size() == bonder)
        cout << ans << endl;  //如果所有点都访问过，输出路径长度之和
    else {
        int flag = 1;
        for (int i = 0; i <= bonder; i++)
            if (!vis[i]) {
                if (flag) {
                    cout << i;
                    flag = 0;
                } else
                    cout << " " << i;
            }
    }  //输出未访问到的点
    return 0;
}