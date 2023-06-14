#include <iostream>
#include <vector>
using namespace std;
/**
 * 关键就是在这个find函数。这个函数
 * 在寻找父节点的时候顺便把路径上的节点都整理了。
 */
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
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }

    for (int i = 0; i < m; ++i) {
        char command;
        int  a, b;
        cin >> command >> a >> b;
        a--;
        b--;
        if (command == 'M') {
            // 这句话非常关键，两个集合应当是父节点相互结合，
            // 一个父节点接到另外一个父节点
            // 而不是子节点换父亲，这样相同父节点的子节点都没有接上去。
            parent[find(parent, b)] = find(parent, a);
        } else {
            if (find(parent, a) == find(parent, b)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
}