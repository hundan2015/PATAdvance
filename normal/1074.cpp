#include <iostream>
#include <map>
#include <vector>

using namespace std;
struct node {
    int data;
    int next;
    int addr;
    node(int _data, int _addr, int _next)
        : data(_data), next(_next), addr(_addr) {}
};
vector<node*> nodeList = vector<node*>(100000, nullptr);
vector<node*> resList;

int start, nodeCount, reCount;
void resort(int startPos, int endPos) {
    if (endPos - startPos < reCount - 1) {
        return;
    }
    while (startPos < endPos) {
        node* tempNode = resList[startPos];
        resList[startPos] = resList[endPos];
        resList[endPos] = tempNode;
        startPos++;
        endPos--;
    }
}
void remake() {
    for (int i = 0; i < resList.size(); ++i) {
        if (i == resList.size() - 1) {
            resList[i]->next = -1;
        } else {
            resList[i]->next = resList[i + 1]->addr;
        }
    }
}
int main() {
    cin >> start >> nodeCount >> reCount;
    for (int i = 0; i < nodeCount; ++i) {
        int data, addr, next;
        cin >> addr >> data >> next;
        nodeList[addr] = new node(data, addr, next);
    }
    int nowPos = start;
    while (nowPos != -1) {
        resList.push_back(nodeList[nowPos]);
        nowPos = nodeList[nowPos]->next;
    }
    nowPos = 0;
    while (nowPos < resList.size()) {
        int enP = min(nowPos + reCount - 1, (int)resList.size() - 1);
        resort(nowPos, enP);
        nowPos += reCount;
    }
    remake();
    for (auto shit : resList) {
        printf("%05d %d ", shit->addr, shit->data);
        if (shit->next != -1) {
            printf("%05d\n", shit->next);
        } else {
            printf("-1\n");
        }
    }
}
/**
brief 针对
 * 
 */