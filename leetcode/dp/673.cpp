#include <algorithm>
#include <utility>
#include <vector>
#include "bits/stdc++.h"
using namespace std;

class Solution {
   public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<pair<int, int>> dp(nums.size(), make_pair(1, 1));
        for (int i = 1; i < dp.size(); ++i) {
            int maxLength = 0;
            int maxSum = 1;
            for (int j = i - 1; j >= 0; --j) {
                int currentMaxLength = dp[j].first;
                int currentMaxCount = dp[j].second;
                if (nums[j] < nums[i]) {
                    if (currentMaxLength > maxLength) {
                        maxLength = currentMaxLength;
                        maxSum = currentMaxCount;
                    } else if (currentMaxLength == maxLength) {
                        maxSum += currentMaxCount;
                    }
                }
            }
            dp[i] = make_pair(maxLength + 1, maxSum);
        }
        int maxLength = -1;
        int maxSum = 0;
        for (auto [currentMaxLength, currentMaxSum] : dp) {
            if (currentMaxLength > maxLength) {
                maxLength = currentMaxLength;
                maxSum = currentMaxSum;
            } else if (currentMaxLength == maxLength) {
                maxSum += currentMaxSum;
            }
        }
        return maxSum;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 2, 2, 2, 2};

    int res = sol.findNumberOfLIS(nums);
    cout << res;
}