#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0)
            return;
        for (int i = 0; i < m; ++i) {
            if (nums1[i] > nums2[0]) {
                int temp = nums1[i];
                nums1[i] = nums2[0];
                nums2[0] = temp;

                int j;
                for (j = 1; j < n; ++j) {
                    if (nums2[j] < temp) {
                        nums2[j - 1] = nums2[j];
                    } else {
                        break;
                    }
                }
                nums2[j - 1] = temp;
            }
        }

        for (int i = m; i < n + m; ++i) {
            nums1[i] = nums2[i - m];
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {4, 5, 6, 0, 0, 0}, nums2 = {1, 2, 3};
    sol.merge(nums1, 3, nums2, 3);
    for (auto& i : nums1) {
        cout << i << " ";
    }
}