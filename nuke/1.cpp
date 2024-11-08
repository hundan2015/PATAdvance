#include <bits/stdc++.h>
#include <vector>
using namespace std;
struct Node {
    int id;
    int size;
};
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        map<int, int> table;
        for (int j = 0; j < n; ++j) {
            int shit;
            cin >> shit;
            auto iter = table.find(shit);
            if (iter != table.end()) {
                table[shit] = j;
            } else {
                table.insert(make_pair(shit, j));
            }
        }
        vector<Node> nodeList;
        for (auto& j : table) {
            nodeList.push_back({j.first, j.second});
        }
        sort(nodeList.begin(), nodeList.end(),
             [](Node& a, Node& b) { return a.size > b.size; });
        for (auto& j : nodeList) {
            cout << j.id << " ";
            if (j.id != nodeList.back().id) {
                cout << " ";
            }
        }
    }
}
// 64 位输出请用 printf("%lld")