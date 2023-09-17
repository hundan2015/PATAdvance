#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// 非常巧妙的递减单调栈问题
class Solution {
   public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int sum = 0;
        for (int i = 0; i < height.size(); ++i) {
            while (!stk.empty() && height[stk.top()] < height[i]) {
                // 在这种情况下，就说明栈内有一个元素比当前小。
                // 这个较小的元素作为当前需要填充部分的底部。
                int downHill = height[stk.top()];
                // 找到作为底的高度之后，我们要找作为墙的高度，因此pop
                stk.pop();
                // empty的时候，墙不存在了。因此不会积水，固向下面继续计算。
                if (stk.empty())
                    break;
                // 作为墙的高度是比作为底的高度高的。

                int distance = i - stk.top() - 1;
                int minHeight = min(height[i], height[stk.top()]);
                sum += distance * (minHeight - downHill);
                // 然而我们并没有pop作为墙的高度的元素，因为这回合的墙，可能是下回合的底
            }
            stk.push(i);
        }
        return sum;
    }
};

int main() {
    Solution sol;
    vector<int> temp = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << sol.trap(temp);
}