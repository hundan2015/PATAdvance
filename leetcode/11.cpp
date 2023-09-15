#include <iostream>
#include <vector>
using namespace std;
// 双指针一般都是要求一个极值，然后通过贪心的办法剪枝
// 从两边开始，然后向中间靠拢。
class Solution {
   public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int maxSize = -1;
        while (i < j) {
            int h = min(height[i], height[j]);
            maxSize = max(maxSize, h * (j - i));
            if (height[i] < height[j]) {
                ++i;
            } else {
                --j;
            }
        }
        return maxSize;
    }
};