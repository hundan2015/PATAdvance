#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node
{
    int l;
    int m; // hang
    int n; // lie
};
int m, bonder, l, bonder;
vector<vector<vector<bool>>> visited;
vector<vector<vector<int>>> mat;

bool notOverBonder(Node node)
{
    return node.l < l && node.l >= 0 && node.m >= 0 && node.m < m && node.n < bonder && node.n >= 0;
}
bool matIsCore(Node node)
{
    return mat[node.l][node.m][node.n] == 1;
}
int processNode(Node node)
{
    if (visited[node.l][node.m][node.n] || !matIsCore(node))
    {
        return 0;
    }
    queue<Node> queNode;
    queNode.push(node);
    int res = 0;
    while (!queNode.empty())
    {
        Node nodeTemp = queNode.front();
        queNode.pop();
        if (visited[nodeTemp.l][nodeTemp.m][nodeTemp.n])
        {
            continue;
        }
        else
        {
            visited[nodeTemp.l][nodeTemp.m][nodeTemp.n] = true;
            res++;
        }

        // Start DFS in 6 direction
        if (notOverBonder({nodeTemp.l, nodeTemp.m + 1, nodeTemp.n}) && matIsCore({nodeTemp.l, nodeTemp.m + 1, nodeTemp.n}))
        {
            queNode.push({nodeTemp.l, nodeTemp.m + 1, nodeTemp.n});
        }
        if (notOverBonder({nodeTemp.l, nodeTemp.m - 1, nodeTemp.n}) && matIsCore({nodeTemp.l, nodeTemp.m - 1, nodeTemp.n}))
        {
            queNode.push({nodeTemp.l, nodeTemp.m - 1, nodeTemp.n});
        }
        if (notOverBonder({nodeTemp.l + 1, nodeTemp.m, nodeTemp.n}) && matIsCore({nodeTemp.l + 1, nodeTemp.m, nodeTemp.n}))
        {
            queNode.push({nodeTemp.l + 1, nodeTemp.m, nodeTemp.n});
        }
        if (notOverBonder({nodeTemp.l - 1, nodeTemp.m, nodeTemp.n}) && matIsCore({nodeTemp.l - 1, nodeTemp.m, nodeTemp.n}))
        {
            queNode.push({nodeTemp.l - 1, nodeTemp.m, nodeTemp.n});
        }
        if (notOverBonder({nodeTemp.l, nodeTemp.m, nodeTemp.n + 1}) && matIsCore({nodeTemp.l, nodeTemp.m, nodeTemp.n + 1}))
        {
            queNode.push({nodeTemp.l, nodeTemp.m, nodeTemp.n + 1});
        }
        if (notOverBonder({nodeTemp.l, nodeTemp.m, nodeTemp.n - 1}) && matIsCore({nodeTemp.l, nodeTemp.m, nodeTemp.n - 1}))
        {
            queNode.push({nodeTemp.l, nodeTemp.m, nodeTemp.n - 1});
        }
    }
    if (res >= bonder)
    {
        return res;
    }
    else
    {
        return 0;
    }
}

int main()
{
    cin >> m >> bonder >> l >> bonder;
    visited = vector<vector<vector<bool>>>(l, vector<vector<bool>>(m, vector<bool>(bonder, false)));
    mat = vector<vector<vector<int>>>(l, vector<vector<int>>(m, vector<int>(bonder, 0)));
    for (int i = 0; i < l; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            for (int k = 0; k < bonder; ++k)
            {
                cin >> mat[i][j][k];
            }
        }
    } // input mat data

    int res = 0;
    for (int i = 0; i < l; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            for (int k = 0; k < bonder; ++k)
            {
                res += processNode({i, j, k});
            }
        }
    }
    cout << res;
}