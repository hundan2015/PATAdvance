#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int counter;
vector<int> tree;
void middle(int pos) {
    int size = tree.size();
    if (pos >= size) {
        return;
    }
    middle(pos * 2 + 1);
    tree[pos] = counter;
    counter++;
    middle(pos * 2 + 2);
}
vector<int> makeTree(vector<int>& original) {
    sort(original.begin(), original.end());
    tree = vector<int>(original.size());
    middle(0);
    queue<int> nodeQueue;
    nodeQueue.push(0);
    vector<int> res;
    while (!nodeQueue.empty()) {
        int pos = nodeQueue.front();
        nodeQueue.pop();
        if (pos * 2 + 1 < tree.size()) {
            nodeQueue.push(pos * 2 + 1);
        }
        if (pos * 2 + 2 < tree.size()) {
            nodeQueue.push(pos * 2 + 2);
        }
        res.push_back(original[tree[pos]]);
    }
    return res;
}

int main() {
    int count;
    cin >> count;
    vector<int> t;
    for (int i = 0; i < count; ++i) {
        int temp;
        cin >> temp;
        t.push_back(temp);
    }
    auto res = makeTree(t);
    for (auto& i : res) {
        cout << i << " ";
    }
}