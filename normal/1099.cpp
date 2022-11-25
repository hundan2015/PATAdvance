#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct node
{
    int data = -1;
    int leftChild = -1;
    int rightChild = -1;
};
vector<node> nodeList;
vector<int> shitList;
vector<int> orderList;
int nodeRank = 0;
int nodeCount;
void levelOutput()
{
    queue<int> nodeQue;
    nodeQue.push(0);
    while (!nodeQue.empty())
    {
        int nodeTemp = nodeQue.front();
        orderList.push_back(nodeList[nodeTemp].data);
        nodeQue.pop();
        if (nodeList[nodeTemp].leftChild != -1)
        {
            nodeQue.push(nodeList[nodeTemp].leftChild);
        }
        if (nodeList[nodeTemp].rightChild != -1)
        {
            nodeQue.push(nodeList[nodeTemp].rightChild);
        }
    }
}
void orderInput(int position)
{
    if (position == -1)
        return;
    orderInput(nodeList[position].leftChild);
    nodeList[position].data = shitList[nodeRank];
    nodeRank++;
    orderInput(nodeList[position].rightChild);
}
int main()
{
    cin >> nodeCount;
    nodeList = vector<node>(nodeCount);
    shitList = vector<int>(nodeCount);
    for (auto &i : nodeList)
    {
        cin >> i.leftChild >> i.rightChild;
    }
    for (auto &i : shitList)
    {
        cin >> i;
    }
    sort(shitList.begin(), shitList.end());
    orderInput(0);
    levelOutput();
    for (int i = 0; i < nodeCount; ++i)
    {
        cout << orderList[i];
        if (i != nodeCount - 1)
        {
            cout << " ";
        }
    }
}