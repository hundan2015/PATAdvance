#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
   public:
    int findPeakElement(vector<int>& nums) {
        int head = 0, tail = nums.size() - 1;
        if (nums.size() == 1) return 0;
        while (head < tail) {
            int current = (head + tail) / 2;
            if (current == 0) {
                if (nums[current + 1] < nums[current]) return current;
                head = current + 1;
                continue;
            }
            if (current == int(nums.size())) {
                if (nums[current - 1] < nums[current]) return current;
                tail = current - 1;
                continue;
            }
            if (nums[current - 1] < nums[current] &&
                nums[current + 1] < nums[current]) {
                return current;
            }
            if (nums[current - 1] < nums[current] &&
                nums[current + 1] > nums[current]) {
                head = current + 1;
                continue;
            }
            if (nums[current - 1] > nums[current] &&
                nums[current + 1] < nums[current]) {
                tail = current - 1;
                continue;
            }
            head = current + 1;
        }
        return head;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    cout << sol.findPeakElement(nums);
}