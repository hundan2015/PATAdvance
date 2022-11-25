#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> nodeList;
vector<int> treeNode;
int nodeCount;
int nodeRank = 0;
void inOrderTravel(int position)
{
    if (position > nodeCount)
        return;
    inOrderTravel(position * 2);
    treeNode[position - 1] = nodeList[nodeRank];
    nodeRank++;
    inOrderTravel(position * 2 + 1);
}
int main()
{
    cin >> nodeCount;
    nodeList = vector<int>(nodeCount);
    treeNode = vector<int>(nodeCount);
    for (auto &i : nodeList)
    {
        cin >> i;
    }
    sort(nodeList.begin(), nodeList.end());
    inOrderTravel(1);
    for (int i = 0; i < nodeCount; ++i)
    {
        cout << treeNode[i];
        if (i != nodeCount - 1)
        {
            cout << " ";
        }
    }
}