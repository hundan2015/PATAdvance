#include <iostream>
#include <map>
#include <vector>
using namespace std;
struct node
{
    int key = 0;
    string address = "";
    string next = "";
    node(int _key, string _address, string _next) : key(_key), address(_address), next(_next) {}
};
int main()
{
    map<int, node *> nodeMap;
    map<string, node *> nodeSeriesmap;
    vector<node *> nodeVec;
    vector<node *> deletedNodeVec;
    int count;
    string headAddress;
    cin >> headAddress >> count;
    //首先把所有的元素都丢进nodeSeriesMap中形成序列
    //通过序列然后将没有见过的元素放进nodeMap;
    //将见过的元素放deleteNodeVec
    //没见过的直接放nodeVec
    //最后将两条链上的元素处理一下，改一下地址
    for (int i = 0; i < count; ++i)
    {
        string address, next;
        int key;
        cin >> address >> key >> next;
        node *tempNode = new node(key, address, next);
        nodeSeriesmap.insert(make_pair(address, tempNode));
    } //丢进去获得原始输入

    //分类查看是否满足要求
    while (headAddress != "-1")
    {
        map<string, node *>::iterator shit = nodeSeriesmap.find(headAddress);
        if (shit != nodeSeriesmap.end())
        {
            node *tempNode = shit->second;
            map<int, node *>::iterator anotherShit = nodeMap.find(abs(tempNode->key));
            if (anotherShit == nodeMap.end())
            {
                nodeMap.insert(make_pair(abs(tempNode->key), tempNode));
                nodeVec.push_back(tempNode);
            }
            else
            {
                deletedNodeVec.push_back(shit->second);
            }
            headAddress = shit->second->next;
        }
        else
        {
            break;
        }
    }
    if (nodeMap.empty())
    {
        return 0;
    }
    //处理每一个节点和后续地址
    for (int i = 0; i < nodeVec.size() - 1; ++i)
    {
        nodeVec[i]->next = nodeVec[i + 1]->address;
    }
    if (!nodeVec.empty())
    {
        nodeVec.back()->next = "-1"; //
    }
    int shitG = deletedNodeVec.size();

    if (!deletedNodeVec.empty())
    {
        for (int i = 0; i < deletedNodeVec.size() - 1; ++i)
        {
            deletedNodeVec[i]->next = deletedNodeVec[i + 1]->address;
        }
        deletedNodeVec.back()->next = "-1"; //
    }

    //节点输出环节
    for (auto i : nodeVec)
    {
        cout << i->address << " " << i->key << " " << i->next << endl;
    }
    for (auto i : deletedNodeVec)
    {
        cout << i->address << " " << i->key << " " << i->next << endl;
    }
}