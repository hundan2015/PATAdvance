#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        auto target1 = lower_bound(nums.begin(), nums.end(), target);
        auto target2 = upper_bound(nums.begin(), nums.end(), target);
        if (target1 == nums.end() || target2 == nums.end() ||
            *target1 != target) {
            if (target2 == nums.end() && *(target2 - 1) == target) {
                return {int(target1 - nums.begin()),
                        int(target2 - nums.begin() - 1)};
            }
            return {-1, -1};
        }
        return {int(target1 - nums.begin()), int(target2 - nums.begin() - 1)};
    }
};

int main() {
    vector<int> nums = {0};
    Solution sol;
    auto shit = sol.searchRange(nums, 0);
}