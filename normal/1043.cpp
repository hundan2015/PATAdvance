#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct node
{
    int data = -1;
    node *left = nullptr;
    node *right = nullptr;
    node(int x) : data(x) {}
};
int nodeCount;
bool deadsignal = false;
vector<int> preOrder;
node *makeTree(int start, int end)
{
    if (start > end || start < 0 || end >= nodeCount)
    {
        return nullptr;
    }
    else if (start == end)
    {
        return new node(preOrder[start]);
    }
    node *res = new node(preOrder[start]);
    int dividesignal = -1;
    for (int i = start + 1; i <= end; ++i)
    {
        if (!((preOrder[i] < preOrder[start] && dividesignal == -1) || (preOrder[i] >= preOrder[start] && dividesignal != -1)))
        {
            if (dividesignal == -1)
            {
                dividesignal = i;
            }
            else
            {
                deadsignal = true;
                break;
            }
        }
    }
    if (deadsignal)
        return nullptr;
    if (dividesignal == -1)
        dividesignal = end + 1;
    res->left = makeTree(start + 1, dividesignal - 1);
    res->right = makeTree(dividesignal, end);
    return res;
}
node *makeMirror(int start, int end)
{
    if (start > end)
    {
        return nullptr;
    }
    else if (start == end)
    {
        return new node(preOrder[start]);
    }
    node *res = new node(preOrder[start]);
    int dividesignal = -1;
    for (int i = start + 1; i <= end; ++i)
    {
        if (!((preOrder[i] >= preOrder[start] && dividesignal == -1) || (preOrder[i] < preOrder[start] && dividesignal != -1)))
        {
            if (dividesignal == -1)
            {
                dividesignal = i;
            }
            else
            {
                deadsignal = true;
                break;
            }
        }
    }
    if (deadsignal)
        return nullptr;
    if (dividesignal == -1)
        dividesignal = end + 1;
    res->left = makeMirror(start + 1, dividesignal - 1);
    res->right = makeMirror(dividesignal, end);
    return res;
}
vector<int> nodePostOrder;
void outNode(node *root)
{
    if (!root)
        return;
    outNode(root->left);
    outNode(root->right);
    nodePostOrder.push_back(root->data);
}
int main()
{
    cin >> nodeCount;
    for (int i = 0; i < nodeCount; ++i)
    {
        int data;
        cin >> data;
        preOrder.push_back(data);
    }
    if (nodeCount == 1)
    {
        cout << "YES" << endl
             << preOrder.front();
        return 0;
    }
    node *root;
    if (preOrder[0] > preOrder[1])
    {
        root = makeTree(0, nodeCount - 1);
        if (deadsignal)
        {
            deadsignal = false;
            root = makeMirror(0, nodeCount - 1);
        }
    }
    else
    {
        root = makeMirror(0, nodeCount - 1);
        if (deadsignal)
        {
            deadsignal = false;
            root = makeTree(0, nodeCount - 1);
        }
    }
    if (deadsignal)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES" << endl;
        outNode(root);
        for (int i = 0; i < nodePostOrder.size(); ++i)
        {
            cout << nodePostOrder[i];
            if (i != nodeCount - 1)
            {
                cout << " ";
            }
        }
    }
}
//虽然最后答案是正确的但说实话代码复用性很傻逼啊
//但是debug还是很幸运，比较快
