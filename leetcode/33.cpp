#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
   public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1) return nums[0] == target ? 0 : -1;
        // int peakPoint = findPeakElement(nums);
        int peakPoint = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i + 1] < nums[i]) {
                peakPoint = i;
                break;
            }
        }
        auto target1 =
            lower_bound(nums.begin(), nums.begin() + peakPoint + 1, target);
        auto target2 =
            lower_bound(nums.begin() + peakPoint + 1, nums.end(), target);
        if (target1 != nums.end() && *target1 == target) {
            return target1 - nums.begin();
        } else if (target2 != nums.end() && *target2 == target) {
            return target2 - nums.begin();
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5, 1, 3};
    cout << sol.search(nums, 1);
}