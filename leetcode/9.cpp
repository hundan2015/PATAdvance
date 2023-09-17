#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        if (x == 0)
            return true;
        vector<int> nums;
        int shit = x;
        while (shit != 0) {
            nums.push_back(shit % 10);
            shit /= 10;
        }

        for (int i = 0; i < nums.size() / 2 + 1; ++i) {
            if (nums[i] != nums[nums.size() - i - 1]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    cout << sol.isPalindrome(10);
}