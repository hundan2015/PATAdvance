#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> tb;
int campCount, linecount;
int good, res = 0, tempcount, rescount = 0;
void bfs(vector<bool> visited, int data, int count)
{
    if (visited[data])
    {
        return;
    }
    else
    {
        visited[data] = true;
    }
    sort(tb[data].begin(), tb[data].end());
    int dest = 0;
    bool trigger = false;
    for (auto i : tb[data])
    {
        if (!visited[i])
        {
            dest = i;
            trigger = true;
            break;
        }
    }
    if (trigger)
        bfs(visited, dest, count + 1);
    else
    {
        if (count > rescount)
        {
            rescount = count;
            res = good;
        }
    }
}
int main()
{

    cin >> campCount >> linecount;
    tb = vector<vector<int>>(campCount);
    for (int i = 0; i < linecount; ++i)
    {
        int data1, data2;
        cin >> data1 >> data2;
        tb[data1 - 1].push_back(data2 - 1);
        tb[data2 - 1].push_back(data1 - 1);
    }
    for (int i = 0; i < campCount; ++i)
    {
        good = i;
        bfs(vector<bool>(campCount), i, 0);
    }
    cout << res + 1 << " " << rescount + 1;
}