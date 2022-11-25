#include <iostream>
#include <vector>
using namespace std;
vector<int> tree;
bool isTree = true;
vector<int> order;
int numCount;
void travel(int pos) {
    if (pos >= numCount || tree[pos] == -1) {
        return;
    }
    int leftPos = pos * 2 + 1;
    int rightPos = pos * 2 + 2;
    travel(leftPos);
    if (leftPos < numCount && tree[leftPos] != -1 &&
        tree[leftPos] >= tree[pos]) {
        isTree = false;
    } else if (rightPos < numCount && tree[rightPos] != -1 &&
               tree[rightPos] < tree[pos]) {
        isTree = false;
    }
    order.push_back(tree[pos]);
    travel(rightPos);
}
int main() {
    cin >> numCount;
    tree = vector<int>(numCount);
    for (auto& i : tree) {
        cin >> i;
    }
    travel(0);
    if (numCount == 0) {
        isTree = false;
    }
    if (isTree) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    for (int i = 0; i < order.size(); ++i) {
        cout << order[i];
        if (i != order.size() - 1) {
            cout << " ";
        }
    }
}