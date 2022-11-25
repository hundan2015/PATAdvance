#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> tree;
int numCount;
int deg;
void fillTree(int pos) {
    if (pos >= numCount)
        return;
    cin >> tree[pos];
    for (int i = 1; i <= deg; ++i) {
        fillTree(pos * deg + i);
    }
}
inline void level() {
    for (auto i = 0; i < numCount; ++i) {
        cout << tree[i];
        if (i != numCount - 1) {
            cout << " ";
        }
    }
}
int main() {
    cin >> numCount >> deg;
    tree = vector<int>(numCount);
    fillTree(0);
    for (int i = 0; i < numCount; ++i) {
        cout << tree[i];
        if (i != numCount - 1) {
            cout << " ";
        } else {
            cout << endl;
        }
    }
    int questCount;
    cin >> questCount;
    for (int i = 0; i < questCount; ++i) {
        int pos;
        cin >> pos;
        while (pos > 0) {
            cout << tree[pos] << " ";
            pos = (pos - 1) / deg;
        }
        cout << tree[0] << endl;
    }
}