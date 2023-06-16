#include <deque>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    deque<int> dq;

    for (int i = 0; i < k; ++i) {
        while (!dq.empty() && dq.back() > nums[i]) {
            dq.pop_back();
        }
        dq.push_back(nums[i]);
    }
    cout << dq.front();
    for (int i = 1; i < n - k + 1; ++i) {
        if (nums[i - 1] == dq.front()) {
            dq.pop_front();
        }
        while (!dq.empty() && dq.back() > nums[i + k - 1]) {
            dq.pop_back();
        }
        dq.push_back(nums[i + k - 1]);
        cout << " " << dq.front();
    }
    cout << endl;
    // 单调队列的方法。
    /**
     * 单调队列只在队伍里保留可能成为最小值的元素。
     * 假设一个元素把前面所有的都排除了，因为前面出现过的元素一定先于
     * 这个元素调出窗口，因此他们不可能是最小值。只有后面进来的元素才可能在
     * 后面的窗口中成为最小值的元素。
     * 
     * 还是需要解析一下这个方法的来源。
     */
    dq.clear();
    for (int i = 0; i < k; ++i) {
        while (!dq.empty() && dq.back() < nums[i]) {
            dq.pop_back();
        }
        dq.push_back(nums[i]);
    }
    cout << dq.front();
    for (int i = 1; i < n - k + 1; ++i) {
        if (nums[i - 1] == dq.front()) {
            dq.pop_front();
        }
        while (!dq.empty() && dq.back() < nums[i + k - 1]) {
            dq.pop_back();
        }
        dq.push_back(nums[i + k - 1]);
        cout << " " << dq.front();
    }
}