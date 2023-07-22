#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct node {
    int front;
    int back;
};
vector<node> nodeList;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        nodeList.push_back({a, b});
    }
    sort(nodeList.begin(), nodeList.end(),
         [](node a, node b) { return a.back < b.back; });
    int counter = 0;
    int end = -0x7fffffff - 1;
    for (auto& i : nodeList) {
        if (i.front > end) {
            counter++;
            end = i.back;
        }
    }
    cout << counter;
}