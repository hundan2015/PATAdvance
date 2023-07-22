#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
struct Node {
    int start;
    int end;
};
int main() {
    int n;
    cin >> n;
    vector<Node> nodeList;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        nodeList.push_back({a, b});
    }
    sort(nodeList.begin(), nodeList.end(),
         [](Node a, Node b) { return a.start < b.start; });
         //  之前在这个位置排序是按照末尾来进行的。但是在后面会重新排序，
         // 浪费了大量的时间。因此这里用头进行排序。
    priority_queue<int, vector<int>, greater<int>> nodeQue;
    nodeQue.push(nodeList[0].end);
    for (int i = 1; i < nodeList.size(); ++i) {
        if (nodeQue.top() < nodeList[i].start) {
            nodeQue.pop();
        }
        nodeQue.push(nodeList[i].end);
    }
    cout << nodeQue.size();
}