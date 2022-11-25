#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> nodeList;
int total = 0;
double maxPrice = -1;
int nodeCount;
double price, percent;
void order(int root, double price)
{
    if (nodeList[root].size() == 0)
    {
        if (price > maxPrice)
        {
            total = 1;
            maxPrice = price;
        }
        else if (maxPrice == price)
        {
            total++;
        }
    }
    for (auto i : nodeList[root])
    {
        order(i, price * (1 + percent));
    }
}
//还是得遍历
int main()
{

    cin >> nodeCount >> price >> percent;
    percent /= 100;
    nodeList = vector<vector<int>>(nodeCount);
    int root;
    for (int i = 0; i < nodeCount; ++i)
    {
        int data;
        cin >> data;
        if (data != -1)
        {
            nodeList[data].push_back(i);
        }
        else
        {
            root = i;
        }
    }
    order(root, price);
    printf("%.2lf %d", maxPrice, total);
}