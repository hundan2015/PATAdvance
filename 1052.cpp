#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
struct node
{
    int key = 0;
    string address = "";
    string next = "";
    node(int _key, string _address, string _next) : key(_key), address(_address), next(_next) {}
};
bool cmp(node *a, node *b)
{
    return a->key < b->key;
}
int main()
{
    vector<node *> nodeList;
    map<string, node *> nodeMap;
    int nodeCount;
    string headAddress;
    cin >> nodeCount >> headAddress;

    for (int i = 0; i < nodeCount; ++i)
    {
        int key;
        string address, next;
        cin >> address >> key >> next;
        node *nodeTemp = new node(key, address, next);
        // nodeList.push_back(nodeTemp);
        nodeMap.insert(make_pair(address, nodeTemp));
    } //安装数据

    if (nodeMap.empty())
    {
        cout << 0 << " "
             << "-1";
        return 0;
    } //判断是不是根本没有输入数据

    node *temp;
    while (headAddress != "-1")
    {
        map<string, node *>::iterator shit = nodeMap.find(headAddress);
        temp = NULL;
        if (shit != nodeMap.end())
        {
            temp = shit->second;
        }
        else
        {
            cout << 0 << " "
                 << "-1";
            return 0;
        }

        if (temp)
        {
            nodeList.push_back(temp);
            headAddress = temp->next;
        }
    }
    if (nodeList.empty())
    {
        cout << 0 << " "
             << "-1";
        return 0;
    }
    sort(nodeList.begin(), nodeList.end(), cmp);
    nodeCount = nodeList.size();//就是这句话搞了我2个小时，如果不是所有数据都有用到，直接快进到越界
    for (int i = 0; i < nodeCount - 1; ++i)
    {
        nodeList[i]->next = nodeList[i + 1]->address;
    }
    nodeList[nodeCount - 1]->next = "-1";
    headAddress = nodeList.front()->address;
    cout << nodeCount << " " << headAddress << endl;
    for (auto i : nodeList)
    {
        cout << i->address << " " << i->key << " " << i->next << endl;
    }
}
//想要完美debug就是要对每一个可能的情况设计数据，然后针对问题对每一个地方进行排查
//现在有的bug就是有些node并不在链上
//使用一个map来快速查询节点是否在上面，保证连续性