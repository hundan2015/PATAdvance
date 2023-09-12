#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    void rotate(vector<int>& nums, int k) {
        const int size = nums.size();
        vector<int> res(size);
        for (int i = 0; i < size; ++i) {
            res[(i + k) % size] = nums[i];
        }
        nums = res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1, -100, 3, 99};
    sol.rotate(nums, 2);
    for (auto& i : nums) {
        cout << i << " ";
    }
}