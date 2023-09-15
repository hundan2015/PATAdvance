#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int maxRes = (-0x7fffffff - 1);
        int res = 0;
        int maxMinus = (-0x7fffffff - 1);
        for (int i = 0; i < nums.size(); ++i) {
            res = max(nums[i], res + nums[i]);
            maxRes = max(res, maxRes);
        }
        return max(maxRes, maxMinus);
    }
};