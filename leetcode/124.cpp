#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
    int maxSolution = (-0x7fffffff - 1);

   public:
    int maxPathSum(TreeNode* root) {
        dfs(root, 0);
        return maxSolution;
    }
    int dfs(TreeNode* root, int prevSum) {
        if (!root)
            return (-0x7fffffff - 1);
        int sum = prevSum + root->val;

        int leftMax = dfs(root->left, sum);
        int rightMax = dfs(root->right, sum);

        if (rightMax != (-0x7fffffff - 1) && leftMax != (-0x7fffffff - 1))
            maxSolution = max(
                maxSolution,
                root->val +
                    max(0, max(leftMax, max(rightMax, leftMax + rightMax))));
        else {
            maxSolution =
                max(maxSolution, root->val + max(0, max(leftMax, rightMax)));
        }

        return root->val + max(0, max(leftMax, rightMax));
    }
};