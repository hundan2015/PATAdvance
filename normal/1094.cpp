#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> treeTable;

int main()
{
    int nodeCount, nodeParent;
    cin >> nodeCount >> nodeParent;
    treeTable = vector<vector<int>>(nodeCount + 1, vector<int>({}));
    for (int i = 0; i < nodeParent; ++i)
    {
        int ptr, childCount;
        cin >> ptr >> childCount;
        for (int j = 0; j < childCount; ++j)
        {
            int data;
            cin >> data;
            treeTable[ptr].push_back(data);
        }
    } // init tree

    int gen = 0;
    int maxFloor = -1, maxFloorCount = -1;
    queue<int> nodeQue;
    nodeQue.push(1);
    while (!nodeQue.empty())
    {
        int floor = nodeQue.size();
        gen++;
        for (int i = 0; i < floor; ++i)
        {
            int root = nodeQue.front();
            nodeQue.pop();
            for (auto data : treeTable[root])
            {
                nodeQue.push(data);
            }
        }

        if (floor > maxFloorCount)
        {
            maxFloorCount = floor;
            maxFloor = gen;
        }
    }
    cout << maxFloorCount << " " << maxFloor;
}