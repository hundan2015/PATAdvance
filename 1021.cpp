#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> linkedTable;
int nodeCount;
vector<bool> visitedTable;
vector<int> maxFloorNode;
int maxFloor = -1;
bool errTrigger = false;
int secCount = 0;
void BFS(int root)
{
    int floor = 0;
    queue<int> nodeQue;
    nodeQue.push(root);
    while (!nodeQue.empty())
    {
        int floorCount = nodeQue.size();
        floor++;
        for (int i = 0; i < floorCount; ++i)
        {
            int nodeTemp = nodeQue.front();
            nodeQue.pop();
            visitedTable[nodeTemp] = true;
            for (auto i : linkedTable[nodeTemp])
            {
                if (!visitedTable[i])
                {
                    nodeQue.push(i);
                }
            }
        }
    }
    // make error trigger
    for (int i = 1; i <= nodeCount; ++i)
    {
        if (!visitedTable[i])
        {
            errTrigger = true;
            break;
        }
    }

    if (floor > maxFloor)
    {
        maxFloor = floor;
        maxFloorNode = {root};
    }
    else if (floor == maxFloor)
    {
        maxFloorNode.push_back(root);
    }
}
int main()
{
    cin >> nodeCount;

    linkedTable = vector<vector<int>>(nodeCount + 1);
    for (int i = 0; i < nodeCount - 1; i++)
    {
        int d1, d2;
        cin >> d1 >> d2;
        linkedTable[d1].push_back(d2);
        linkedTable[d2].push_back(d1);
    }

    for (int i = 1; i <= nodeCount; i++)
    {

        if (errTrigger)
        {
            if (!visitedTable[i])
            {
                BFS(i);
                secCount++;
            }
        }
        else
        {
            visitedTable = vector<bool>(nodeCount + 1, false);
            BFS(i);
        }
    }
    if (!errTrigger)
    {
        for (auto i : maxFloorNode)
        {
            cout << i << endl;
        }
    }
    else
    {
        cout << "Error: " << secCount + 1 << " components";
    }
} // KILLED