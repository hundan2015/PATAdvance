#include <iostream>
#include <vector>
// 22:49 -> 22:51
using namespace std;

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int counter = 1;
        int tempCounter = 1;

        int last = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != last) {
                tempCounter = 1;
                last = nums[i];
                nums[counter] = last;
                counter++;
            } else if (tempCounter == 1) {
                tempCounter++;
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