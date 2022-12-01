#include <iostream>
#include <queue>
#include <vector>

using namespace std;
vector<int> preOrder;
vector<int> inOrder;
vector<int> tree;
int frontPos = 0;
struct Node {
    int data;
    Node *left, *right;
};
Node* makeTree(int start, int end) {
    if (start > end) {
        return nullptr;
    }
    Node* res = new Node;
    res->data = preOrder[frontPos];
    frontPos++;
    for (int i = start; i <= end; ++i) {
        if (res->data == inOrder[i]) {
            res->left = makeTree(start, i - 1);
            res->right = makeTree(i + 1, end);
            return res;
        }
    }
    return nullptr;
}
vector<int> resList;
void orderT(Node* root) {
    queue<Node*> nodeQ;
    nodeQ.push(root);
    while (!nodeQ.empty()) {
        int size = nodeQ.size();
        for (int i = 0; i < size; ++i) {
            Node* top = nodeQ.front();
            if (top->left) {
                nodeQ.push(top->left);
            }
            if (top->right) {
                nodeQ.push(top->right);
            }
            nodeQ.pop();
            if (i == 0) {
                resList.push_back(top->data);
            }
        }
    }
}
int main() {
    int nodeCount;
    cin >> nodeCount;
    preOrder = vector<int>(nodeCount);
    inOrder = vector<int>(nodeCount);
    tree = vector<int>(nodeCount);
    for (auto& i : inOrder) {
        cin >> i;
    }
    for (auto& i : preOrder) {
        cin >> i;
    }
    Node* root = makeTree(0, nodeCount - 1);
    orderT(root);
    for (int i = 0; i < resList.size(); ++i) {
        cout << resList[i];
        if (i != resList.size() - 1) {
            cout << " ";
        }
    }
}