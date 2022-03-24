#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> linkTable;
vector<bool> visitedTable;
int city, roadCount, cityCheckedCount;
int deletedNodeNow;
void DFS(int root)
{
    if (visitedTable[root] || root == deletedNodeNow)
        return;
    visitedTable[root] = true;
    for (auto i : linkTable[root])
    {
        DFS(i);
    }
}

int main()
{
    cin >> city >> roadCount >> cityCheckedCount;
    linkTable = vector<vector<int>>(city + 1);
    visitedTable = vector<bool>(city + 1, false);
    for (int i = 0; i < roadCount; ++i)
    {
        int c1, c2;
        cin >> c1 >> c2;
        linkTable[c1].push_back(c2);
        linkTable[c2].push_back(c1);
    }
    // input road data;
    vector<int> city2Check;
    for (int i = 0; i < cityCheckedCount; ++i)
    {
        int data;
        cin >> data;
        // init new round;
        deletedNodeNow = data;
        visitedTable = vector<bool>(city, false);
        int blockCount = 0;
        for (int i = 1; i <= city; ++i)//每一个都要遍历。
        {
            //如果当前没有被访问的话，说明它不属于之前任何一个块
            if (!visitedTable[i] && i != data)//如果当前被访问了，就不应该被当成一个块。
            {
                DFS(i);
                blockCount++; // this way to deal with is absoltly great;
                //当前块完毕后自然是需要增加一个计数的。
                //每当一个DFS结束时，说明和这个节点没有和他在一起连接的了，说明当前块完结。
            }
        }
        cout << blockCount - 1 << endl;
    } // going to to check the city;
}

//同时还有并查集的做法。也是很妙此时就不写了。