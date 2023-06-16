#include <deque>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    deque<int> dq;
    for (int i = 0; i < k; ++i) {
        if (dq.front() < nums[i]) {
            dq.push_front(nums[i]);
        } else if (dq.back() > nums[i]) {
            dq.clear();
            dq.push_back(nums[i]);
        }
    }
    for (int i = 1; i < n - k + 1; ++i) {
        if (nums[i - 1] == dq.back()) {
            dq.pop_back();
        }
        if (dq.front() < nums[i + k - 1]) {
            dq.push_front(nums[i + k - 1]);
        } else if (dq.back() > nums[i + k - 1]) {
            dq.clear();
            dq.push_back(nums[i + k - 1]);
        }
        cout << dq.back() << " ";
    }
}