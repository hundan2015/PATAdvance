#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdio>
using namespace std;
vector<vector<int>> nodeList;
double priceSum = 0;
int nodeCount;
double price, percent;
void addPrice(int root, double price)
{
    if (nodeList[root][0] == -1)
    {
        priceSum += price * nodeList[root][1];
        return;
    }
    for (auto i : nodeList[root])
    {
        addPrice(i, price * (1 + percent));
    }
}
int main()
{
    cin >> nodeCount >> price >> percent;
    percent /= 100;
    nodeList = vector<vector<int>>(nodeCount);
    vector<bool> rootFinder(nodeCount, true);
    for (auto &i : nodeList)
    {
        int temp;
        cin >> temp;
        if (temp == 0)
        {
            int data;
            cin >> data;
            i = {-1, data};
            continue;
        }
        for (int j = 0; j < temp; ++j)
        {
            int data;
            cin >> data;
            rootFinder[data] = false;
            i.push_back(data);
        }
    } // init data

    int rootID;
    for (int i = 0; i < nodeCount; ++i)
    {
        if (rootFinder[i])
        {
            rootID = i;
            break;
        }
    } // Find root
    addPrice(rootID, price);
    printf("%.1lf", priceSum);
}