#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
struct node {
    int c, m, e, a;
    string id;
    node(string _i, int _c, int _m, int _e) : id(_i), c(_c), m(_m), e(_e) {
        a = _c + _m + _e;
    }
    char best;
    int rank = 9999999;
};
bool cmpA(node* n1, node* n2) {
    return n1->a > n2->a;
}
bool cmpM(node* n1, node* n2) {
    return n1->m > n2->m;
}
bool cmpC(node* n1, node* n2) {
    return n1->c > n2->c;
}
bool cmpE(node* n1, node* n2) {
    return n1->e > n2->e;
}
map<string, node*> nodeMap;
vector<node*> nodeList;

int main() {
    int nodeCount, reqCount;
    cin >> nodeCount >> reqCount;
    for (int i = 0; i < nodeCount; ++i) {
        int c, m, e;
        string id;
        cin >> id >> c >> m >> e;
        node* tempNode = new node(id, c, m, e);
        nodeMap.insert(make_pair(id, tempNode));
        nodeList.push_back(tempNode);
    }
    // 3 times sort.
    int prevScore = -1;
    int prevRank = -1;
    sort(nodeList.begin(), nodeList.end(), cmpE);
    for (int i = 1; i <= nodeCount; ++i) {
        int rank;
        if (nodeList[i - 1]->e == prevScore) {
            rank = prevRank;
        } else {
            rank = i;
            prevRank = i;
            prevScore = nodeList[i - 1]->e;
        }
        if (rank <= nodeList[i - 1]->rank) {
            nodeList[i - 1]->best = 'E';
            nodeList[i - 1]->rank = rank;
        }
    }
    prevScore = -1;
    prevRank = -1;
    sort(nodeList.begin(), nodeList.end(), cmpM);
    for (int i = 1; i <= nodeCount; ++i) {
        int rank;
        if (nodeList[i - 1]->m == prevScore) {
            rank = prevRank;
        } else {
            rank = i;
            prevRank = i;
            prevScore = nodeList[i - 1]->m;
        }
        if (rank <= nodeList[i - 1]->rank) {
            nodeList[i - 1]->best = 'M';
            nodeList[i - 1]->rank = rank;
        }
    }
    prevScore = -1;
    prevRank = -1;
    sort(nodeList.begin(), nodeList.end(), cmpC);
    for (int i = 1; i <= nodeCount; ++i) {
        int rank;
        if (nodeList[i - 1]->c == prevScore) {
            rank = prevRank;
        } else {
            rank = i;
            prevRank = i;
            prevScore = nodeList[i - 1]->c;
        }
        if (rank <= nodeList[i - 1]->rank) {
            nodeList[i - 1]->best = 'C';
            nodeList[i - 1]->rank = rank;
        }
    }
    prevScore = -1;
    prevRank = -1;
    sort(nodeList.begin(), nodeList.end(), cmpA);
    for (int i = 1; i <= nodeCount; ++i) {
        int rank;
        if (nodeList[i - 1]->a == prevScore) {
            rank = prevRank;
        } else {
            rank = i;
            prevRank = i;
            prevScore = nodeList[i - 1]->a;
        }
        if (rank <= nodeList[i - 1]->rank) {
            nodeList[i - 1]->best = 'A';
            nodeList[i - 1]->rank = rank;
        }
    }

    for (int i = 0; i < reqCount; ++i) {
        string data;
        cin >> data;
        auto shit = nodeMap.find(data);
        if (shit != nodeMap.end()) {
            cout << (*shit).second->rank << " " << (*shit).second->best << endl;
        } else {
            cout << "N/A" << endl;
        }
    }
}
//主要是same rank的特判这块需要注意