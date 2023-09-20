#include <bits/stdc++.h>
using namespace std;
// 拓扑序
class Solution {
public:
    struct Node {
        int                val;
        unordered_set<int> prev;
        unordered_set<int> next;
    };
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<Node> table(numCourses);
        for (int i = 0; i < table.size(); ++i) {
            table[i].val = i;
        }
        for (auto& i : prerequisites) {
            table[i[0]].prev.insert(i[1]);
            table[i[1]].next.insert(i[0]);
        }
        queue<Node> shit;
        for (auto& i : table) {
            if (i.prev.empty()) {
                shit.push(i);
            }
        }
        int counter = 0;
        while (!shit.empty()) {
            auto temp = shit.front();
            counter++;
            shit.pop();
            for (auto& i : temp.next) {
                table[i].prev.erase(temp.val);
                if (table[i].prev.empty()) {
                    shit.push(table[i]);
                }
            }
        }
        return counter == numCourses;
    }
};

int main()
{
    Solution            sol;
    vector<vector<int>> pre = {{0, 1}};
    cout << sol.canFinish(2, pre);
}