#include <iostream>
#include <vector>
using namespace std;
struct mouse
{
    int size;
    int numPos;
};
vector<mouse> mouseTable;
vector<mouse> mouseBuffer;
vector<mouse> mouseCom;
vector<int> rankTable;
//select one mouse to the next round competetion
void pushOneMouse(int start, int end, int rank)
{
    //some special judge
    if (start > end)
        return;
    if (start == end)
    {
        mouseBuffer.push_back(mouseCom[end]);
        rankTable[mouseCom[start].numPos] = rank;
        return;
    }
    //get the fat mouse
    int maxTemp = -1;
    mouse tempMouse;
    for (int i = start; i <= end; ++i)
    {
        rankTable[mouseCom[i].numPos] = rank;
        if (mouseCom[i].size > maxTemp)
        {
            tempMouse = mouseCom[i];
            maxTemp = mouseCom[i].size;
        }
    }
    mouseBuffer.push_back(tempMouse);
}

int main()
{
    int count, group;
    cin >> count >> group;
    mouseTable = vector<mouse>(count);
    mouseCom = vector<mouse>(count);
    rankTable = vector<int>(count);
    for (int i = 0; i < count; ++i)
    {
        cin >> mouseTable[i].size;
        mouseTable[i].numPos = i;
    }//get all the mouse data

    for (int i = 0; i < count; ++i)
    {
        int data;
        cin >> data;
        mouseCom[i] = mouseTable[data];
    } // inital mouseCom;
    if (count == 1)
    {
        cout << 1;
        return 0;
    }
    int rankTemp = 0;
    while (mouseCom.size() > 1)
    {
        int stepCount = 0;
        //way to caculate the rank of this round.
        rankTemp = mouseCom.size() % group == 0 ? (mouseCom.size() / group + 1) : (mouseCom.size() / group + 2);
        //shit the mouse every group
        while (stepCount + group - 1 < mouseCom.size())
        {
            pushOneMouse(stepCount, stepCount + group - 1, rankTemp);
            stepCount += group;
        }
        //shit the mouse group which can't be a complete group.
        pushOneMouse(stepCount, mouseCom.size() - 1, rankTemp);
        //switch the future buffer to next round
        mouseCom = mouseBuffer;
        mouseBuffer.clear();
    }
    //get the final mouse to the top
    rankTable[mouseCom[0].numPos] = 1;
    for (int i = 0; i < rankTable.size() - 1; ++i)
    {
        cout << rankTable[i] << " ";
    }
    cout << rankTable.back();
}
//设计的挺不错，就是人有点傻逼