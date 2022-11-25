#include <iostream>
#include <vector>
using namespace std;
struct node
{
    int data = 0;
    node *left = nullptr;
    node *right = nullptr;
    node(int x) : data(x) {}
};
int nodeCount = 0;
int countFin;
node *makeTree()
{
    int data;
    cin >> data;
    node *res = new node(data);
    nodeCount++;
    string stringCommand;
    cin >> stringCommand;
    if (nodeCount < countFin)
    {
        if (stringCommand == "Push")
        {
            res->left = makeTree();
        }
        if (nodeCount == countFin)
        {
            return res;
        }
        cin >> stringCommand;
        if (stringCommand == "Push")
        {
            res->right = makeTree();
        }
        return res;
    }
    else
    {
        cin >> stringCommand;
        return res;
    }
}
vector<int> numorder;
void makeNode(node *root)
{
    if (!root)
        return;
    makeNode(root->left);
    makeNode(root->right);
    numorder.push_back(root->data);
}
int main()
{

    cin >> countFin;
    string tempCommand;
    cin >> tempCommand;
    node *root = makeTree();
    makeNode(root);
    for (int i = 0; i < numorder.size() - 1; ++i)
    {
        cout << numorder[i] << " ";
    }
    cout << numorder.back();
}