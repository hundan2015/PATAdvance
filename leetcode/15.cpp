#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> temp;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            vector<int> result;
            int front = i + 1;
            int end = nums.size() - 1;
            while (front < end) {
                if (nums[i] + nums[front] + nums[end] > 0) {
                    end--;
                } else if (nums[i] + nums[front] + nums[end] < 0) {
                    front++;
                } else {
                    temp.insert({nums[i], nums[front], nums[end]});
                    end--;
                    front++;
                }
            }
        }
        for (auto& i : temp) {
            res.push_back(i);
        }
        return res;
    }
};
