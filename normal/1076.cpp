#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> fellows;
int maxFloorCount, userCount;
vector<bool> visited;
void BFS(int root)
{
    queue<int> nodeQue;
    nodeQue.push(root);
    int floorCount = -1;
    int userCountTemp = -1;
    visited[root] = true;
    while ((!nodeQue.empty()) && floorCount < maxFloorCount)
    {
        int queCount = nodeQue.size();
        floorCount++;
        for (int i = 0; i < queCount; ++i)
        {
            int nodeTemp = nodeQue.front();
            userCountTemp++;
            nodeQue.pop();
            for (auto i : fellows[nodeTemp])
            {
                if (!visited[i])
                {
                    visited[i] = true;//这种就是提前打上了bfs的标签进而使同一层的节点无法访问同一层的子节点，进而避免了重复。
                    nodeQue.push(i);
                }
            }
        }
    }
    cout << userCountTemp << endl;
}
int main()
{
    cin >> userCount >> maxFloorCount;
    fellows = vector<vector<int>>(userCount + 1);
    visited = vector<bool>(userCount + 1, false);
    for (int i = 1; i <= userCount; i++)
    {
        int tempLoop;
        cin >> tempLoop;
        for (int j = 0; j < tempLoop; ++j)
        {
            int data;
            cin >> data;
            fellows[data].push_back(i);
        }
    }
    int data;
    cin >> data;
    for (int i = 0; i < data; ++i)
    {
        visited = vector<bool>(userCount + 1);
        int tempD;
        cin >> tempD;
        BFS(tempD);
    }
}