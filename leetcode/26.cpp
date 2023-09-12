#include <iostream>
#include <vector>
// 22:43 -> 22:47
using namespace std;

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int counter = 1;
        int last = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != last) {
                last = nums[i];
                nums[counter] = last;
                counter++;
            }
        }
        return counter;
    }
};

int main() {
    Solution sol;
    vector<int> shit = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << sol.removeDuplicates(shit);
    for (auto& i : shit) {
        cout << i << " ";
    }
}