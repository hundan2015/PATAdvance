#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool canPartition(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int sum = 0;
    for (auto& i : nums) {
        sum += i;
    }
    if (sum % 2 != 0) return false;
    sum /= 2;
    const int size = nums.size();
    vector<vector<bool>> res(size, vector<bool>(sum + 1, false));
    res[0][0] = true;
    if (nums[0] > sum) return false;
    res[0][nums[0]] = true;
    for (int i = 1; i < size; ++i) {
        for (int j = 0; j <= sum; ++j) {
            res[i][j] = res[i - 1][j];
            if (j - nums[i] > -1)
                res[i][j] = res[i][j] || res[i - 1][j - nums[i]];
        }
    }
    return res[size - 1][sum];
}

int main() {
    vector<int> temp = {1, 5, 5, 11};
    cout << canPartition(temp);
}