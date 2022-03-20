#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;
struct treeNode
{
    int data;
    treeNode *left = nullptr;
    treeNode *right = nullptr;
    treeNode(int x) : data(x) {}
};
stack<treeNode *> post;
vector<int> inorder;

treeNode *buildTreeInSection(int start, int end)
{
    if (start > end)
        return nullptr;
    treeNode *tempNode = post.top();
    for (int i = start; i <= end; ++i)
    {
        if (inorder[i] == tempNode->data)
        {
            post.pop();
            tempNode->right = buildTreeInSection(i + 1, end);
            tempNode->left = buildTreeInSection(start, i - 1);
        }
    }
    return tempNode;
}

void levelOutput(treeNode *root)
{
    queue<treeNode *> nodeQue;
    nodeQue.push(root);
    queue<treeNode *> another;
    while (!nodeQue.empty())
    {
        treeNode *nodeT = nodeQue.front();
        nodeQue.pop();
        another.push(nodeT);
        if (nodeT->left)
            nodeQue.push(nodeT->left);
        if (nodeT->right)
            nodeQue.push(nodeT->right);
    }
    while (another.size() > 1)
    {
        treeNode *t = another.front();
        another.pop();
        cout << t->data << " ";
    }
    cout << another.front()->data;
}
int main()
{
    int nodeCount;
    cin >> nodeCount;
    treeNode *root;
    for (int i = 0; i < nodeCount; ++i)
    {
        int data;
        cin >> data;
        post.push(new treeNode(data));
    }
    inorder = vector<int>(nodeCount);
    for (auto &i : inorder)
    {
        cin >> i;
    }
    root = buildTreeInSection(0, nodeCount - 1);
    levelOutput(root);
}