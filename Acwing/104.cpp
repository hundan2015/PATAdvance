#include <algorithm>
#include <iostream>
#include <vector>
// 中位数的证明需要用右移i个单位进行证明。算一下到两边的点的距离总和
// 然后在假设在中位数的情况下移动，就会发现中位数为最优。
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto& i : nums) {
        cin >> i;
    }
    sort(nums.begin(), nums.end());
    int mid = nums[n / 2];
    int sum = 0;
    for (auto& i : nums) {
        sum += abs(mid - i);
    }
    cout << sum;
}


