#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct node {
    string id;
    int location;
    int localRank;
    int score;
    int rank;
    node(string _id, int _score, int _location)
        : id(_id), score(_score), location(_location) {}
};
vector<node*> nodeList;
vector<node*> tempList;
bool cmp(node* n1, node* n2) {
    if (n1->score != n2->score) {
        return n1->score > n2->score;
    } else {
        return n1->id < n2->id;
    }
}
int main() {
    int regionCount;
    cin >> regionCount;
    for (int i = 1; i <= regionCount; ++i) {
        int manCount;
        cin >> manCount;
        for (int j = 0; j < manCount; ++j) {
            string id;
            int score;
            cin >> id >> score;
            node* shit = new node(id, score, i);
            nodeList.push_back(shit);
            tempList.push_back(shit);
        }
        sort(tempList.begin(), tempList.end(), cmp);
        int lastScore = -1, lastRank = -1;
        for (int i = 1; i <= tempList.size(); ++i) {
            if (tempList[i - 1]->score != lastScore) {
                lastScore = tempList[i - 1]->score;
                lastRank = i;
                tempList[i - 1]->localRank = i;
            } else {
                tempList[i - 1]->localRank = lastRank;
            }
        }
        tempList = vector<node*>();
    }
    sort(nodeList.begin(), nodeList.end(), cmp);
    int lastScore = -1, lastRank = -1;
    for (int i = 1; i <= nodeList.size(); ++i) {
        if (nodeList[i - 1]->score != lastScore) {
            lastScore = nodeList[i - 1]->score;
            lastRank = i;
            nodeList[i - 1]->rank = i;
        } else {
            nodeList[i - 1]->rank = lastRank;
        }
    }
    cout << nodeList.size() << endl;
    for (auto i : nodeList) {
        cout << i->id << " " << i->rank << " " << i->location << " "
             << i->localRank << endl;
    }
}