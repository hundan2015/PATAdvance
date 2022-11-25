#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
    int counter, largeCounter;
    cin >> counter >> largeCounter;
    priority_queue<int, vector<int>, less<int>> que;
    for (int i = 0; i < counter; ++i) {
        int data;
        cin >> data;
        que.push(data);
    }
    int num = min(largeCounter, (int)que.size());
    for (int i = 0; i < num; ++i) {
        int data = que.top();
        que.pop();
        cout << data;
        if (i != num - 1) {
            cout << " ";
        }
    }
}