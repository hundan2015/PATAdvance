#include <iostream>
#include <vector>
using namespace std;
// 经典并查集板子
int find(vector<int>& parent, int a)
{
    if (a != parent[a]) {
        parent[a] = find(parent, parent[a]);
    }
    return parent[a];
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> parent(n);
    vector<int> size(n);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        size[i] = 1;
    }
    for (int i = 0; i < m; ++i) {
        string command;
        int    a, b;
        cin >> command;
        if (command == "C") {
            cin >> a >> b;
            a--;
            b--;
            int a_parent = find(parent, a);
            int b_parent = find(parent, b);
            // 这里的一个关键：和普通并查集不同的是，这个
            // 题目要求增加计数。如果没有continue的话就会有多余的计数。
            if (a_parent == b_parent)
                continue;
            // size的设计就是只有在父节点有用。这里如果一个集合被合并了的话
            // 这个集合原有的root的size就不再维护，也无法访问。
            size[b_parent] += size[a_parent];
            parent[a_parent] = b_parent;
        } else if (command == "Q1") {
            cin >> a >> b;
            a--;
            b--;
            if (find(parent, a) == find(parent, b)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        } else {
            cin >> a;
            a--;
            int root = find(parent, a);
            cout << size[root] << endl;
        }
    }
}