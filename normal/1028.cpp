#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct node {
    string id, name;
    int grade;
    node(string i, string n, int g) : id(i), name(n), grade(g) {}
};

bool cmp1(node* n1, node* n2) {
    return n1->id < n2->id;
}
bool cmp2(node* n1, node* n2) {
    if (n1->name != n2->name) {
        return n1->name < n2->name;
    } else {
        return n1->id < n2->id;
    }
}
bool cmp3(node* n1, node* n2) {
    if (n1->grade != n2->grade) {
        return n1->grade < n2->grade;
    } else {
        return n1->id < n2->id;
    }
}
int main() {
    vector<node*> nodeList;
    int nodeCount, mode;
    cin >> nodeCount >> mode;
    for (int i = 0; i < nodeCount; ++i) {
        string name, id;
        int grade;
        cin >> id >> name >> grade;
        nodeList.push_back(new node(id, name, grade));
    }
    switch (mode) {
        case (1):
            sort(nodeList.begin(), nodeList.end(), cmp1);
            break;
        case (2):
            sort(nodeList.begin(), nodeList.end(), cmp2);
            break;
        case (3):
            sort(nodeList.begin(), nodeList.end(), cmp3);
            break;
    }
    for (auto i : nodeList) {
        cout << i->id << " " << i->name << " " << i->grade << endl;
    }
}