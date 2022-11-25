#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct node
{
    string name;
    int weight = 0;
    vector<node *> child;
    bool visited = false;
    int num = 0;
    node() {}
    node(string n, int x) : name(n), weight(x) {}
};

map<string, node *> nodeMap;
vector<node *> gangList;
int weightGlobal, callCount;
void BFS(node *root)
{
    int weightSum = 0;
    int memSum = 0;
    queue<node *> nodeQue;
    nodeQue.push(root);
    node *tempMaxNode = new node();
    while (!nodeQue.empty())
    {
        node *tempNode = nodeQue.front();
        nodeQue.pop();
        if (tempNode->visited)//这块是个关键：很多节点属于上一层但是因为同时也是上一层寄子节点进而导致被重复计算。但幸运的是再上一层钟就能确定他们是否被访问。因此可以采用跳过节点的方式。
        //或者再访问前边给他们标记被访问的标签。即便是本层节点也不能访问被访问的节点。
            continue;
        tempNode->visited = true;
        weightSum += tempNode->weight;
        memSum++;
        if (tempNode->weight > tempMaxNode->weight)
        {
            tempMaxNode = tempNode;
        }
        for (auto i : tempNode->child)
        {
            if (!i->visited)
            {
                nodeQue.push(i);
            }
        }
    }
    if (memSum > 2 && weightSum > weightGlobal * 2)
    {
        tempMaxNode->num = memSum;
        gangList.push_back(tempMaxNode);
    }
}
bool cmp(node *n1, node *n2)
{
    return n1->name < n2->name;
}
int main()
{
    cin >> callCount >> weightGlobal;
    for (int i = 0; i < callCount; i++)
    {
        string s1, s2;
        int data;
        cin >> s1 >> s2 >> data;
        if (nodeMap.find(s1) == nodeMap.end())
        {
            nodeMap.insert(make_pair(s1, new node(s1, 0)));
        }
        if (nodeMap.find(s2) == nodeMap.end())
        {
            nodeMap.insert(make_pair(s2, new node(s2, 0)));
        }
        node *t1 = nodeMap[s1];
        node *t2 = nodeMap[s2];
        t1->weight += data;
        t2->weight += data;
        t1->child.push_back(t2);
        t2->child.push_back(t1);
    }

    for (auto i : nodeMap)
    {
        if (!i.second->visited)
        {
            BFS(i.second);
        }
    }
    cout << gangList.size() << endl;
    sort(gangList.begin(), gangList.end(), cmp);
    for (auto i : gangList)
    {
        cout << i->name << " " << i->num << endl;
    }
}
//代码整洁一点就是好啊......