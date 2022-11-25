#include <iostream>
#include <vector>
#include <queue>
struct node
{
    int data = -1;
    int left = -1;
    int right = -1;
};
using namespace std;
vector<node> nodeList;
vector<int> nodeOrder;
int nodeCount;
void inOrder(int node)
{
    if (node == -1)
        return;

    inOrder(nodeList[node].left);
    nodeOrder.push_back(node);
    inOrder(nodeList[node].right);
}
void levelOrder(int root)
{
    queue<int> nodeQue;
    nodeQue.push(root);
    while (!nodeQue.empty())
    {
        int temp = nodeQue.front();
        nodeOrder.push_back(temp);
        nodeQue.pop();
        if (nodeList[temp].left != -1)
        {
            nodeQue.push(nodeList[temp].left);
        }
        if (nodeList[temp].right != -1)
        {
            nodeQue.push(nodeList[temp].right);
        }
    }
}
int main()
{

    cin >> nodeCount;
    nodeList = vector<node>(nodeCount);
    vector<bool> rootPtr(nodeCount, true);
    for (int i = 0; i < nodeCount; ++i)
    {
        nodeList[i].data = i;
        char data;
        cin >> data;
        if (data != '-')
        {
            nodeList[i].right = data - '0';
            rootPtr[data - '0'] = false;
        }
        cin >> data;
        if (data != '-')
        {
            nodeList[i].left = data - '0';
            rootPtr[data - '0'] = false;
        }
    }
    int root;
    for (int i = 0; i < nodeCount; ++i)
    {
        if (rootPtr[i])
        {
            root = i;
            break;
        }
    }
    levelOrder(root);
    for (int i = 0; i < nodeOrder.size() - 1; ++i)
    {
        cout << nodeOrder[i] << " ";
    }
    cout << nodeOrder.back() << endl;
    nodeOrder.clear();
    inOrder(root);
    for (int i = 0; i < nodeOrder.size() - 1; ++i)
    {
        cout << nodeOrder[i] << " ";
    }
    cout << nodeOrder.back() << endl;
}