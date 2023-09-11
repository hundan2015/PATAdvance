#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int huffman(const vector<int> list) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto& i : list) {
        pq.push(i);
    }
    int sum = 0;
    while (pq.size() > 1) {
        int t1 = pq.top();
        pq.pop();
        int t2 = pq.top();
        pq.pop();
        const int temp = t1 + t2;
        sum += temp;
        pq.push(temp);
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> list(n);
    for (auto& i : list) {
        cin >> i;
    }
    cout << huffman(list);
}