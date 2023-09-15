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
        dfs(root);
        return maxSolution;
    }
    // 返回经过这个节点，最长的路径长度
    int dfs(TreeNode* root) {
        if (!root)
            return (-0x7fffffff - 1);

        int leftMax = dfs(root->left);
        int rightMax = dfs(root->right);
        // 分别计算节点加上左最长长度，节点加上右最长长度，节点自己长度，节点加上两边最长谁最长。
        // 这样就可以涵盖不同的路径了
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