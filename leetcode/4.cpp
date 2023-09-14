#include <iostream>
#include <vector>
using namespace std;
// 实在是像归并排序
class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        int target1 = (nums1.size() + nums2.size() - 1) / 2;
        int target2 = (nums1.size() + nums2.size()) / 2;
        int sum = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                if (i + j == target1) {
                    sum = nums1[i];
                }
                if (i + j == target2) {
                    return (double(sum) + nums1[i]) / 2;
                }
                i++;
            } else {
                if (i + j == target1) {
                    sum = nums2[j];
                }
                if (i + j == target2) {
                    return (double(sum) + nums2[j]) / 2;
                }
                j++;
            }
        }
        while (i < nums1.size()) {
            if (i + j == target1) {
                sum = nums1[i];
            }
            if (i + j == target2) {
                return (double(sum) + nums1[i]) / 2;
            }
            i++;
        }
        while (j < nums2.size()) {
            if (i + j == target1) {
                sum = nums2[j];
            }
            if (i + j == target2) {
                return (double(sum) + nums2[j]) / 2;
            }
            j++;
        }
        return 0;
    }
};

int main() {
    Solution sol;
    vector<int> shit = {1, 3};
    vector<int> shit2 = {2};
    cout << sol.findMedianSortedArrays(shit, shit2);
}