#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int head = 0, tail = 0;
        const int size = nums.size();
        int sum = 0;
        int minLength = 0x7fffffff;
        while (tail <= size) {
            if (sum >= target) {
                minLength = min(tail - head, minLength);
                sum -= nums[head];
                head++;
            } else {
                if (tail < size)
                    sum += nums[tail];
                tail++;
            }
        }
        if (minLength == 0x7fffffff) {
            return 0;
        }
        return minLength;
    }
};

int main() {
    Solution sol;
    vector<int> shit = {2, 3, 1, 2, 4, 3};
    cout << sol.minSubArrayLen(7, shit);
}