#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
    int numCount;
    cin >> numCount;
    vector<int> queues(100000);
    int queCount = 0;
    for (int i = 0; i < numCount; ++i) {
        int temp;
        cin >> temp;
        bool finded = false;
        // 用了一个二分搜索进行遍历优化
        auto iter =
            lower_bound(queues.begin(), queues.begin() + queCount, temp);
        if (iter != queues.begin() + queCount) {
            *iter = temp;
        } else {
            queues[queCount] = temp;
            queCount++;
        }
    }
    cout << queCount;
}